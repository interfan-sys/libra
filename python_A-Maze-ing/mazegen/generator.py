import random
from typing import Optional, Tuple

from mazegen.models import (
    Direction, DELTA, WALL_BIT, OPPOSITE_WALL, Wall, MazeGrid
)
from mazegen import solver

_FOUR_BITMAP = [
    "X  ",
    "X  ",
    "XXX",
    "  X",
    "  X",
]

_TWO_BITMAP = [
    "XXX",
    "  X",
    "XXX",
    "X  ",
    "XXX",
]

_PATTERN_MIN_WIDTH = 11
_PATTERN_MIN_HEIGHT = 9


def _build_pattern_cells(
    offset_col: int, offset_row: int
) -> set[Tuple[int, int]]:
    """Place the "4" and "2" bitmaps side by side on the maze grid.

    Args:
        offset_col: Column of the top-left corner where "4" starts.
        offset_row: Row of the top-left corner where "4" starts.

    Returns:
        A set of (col, row) tuples for every pattern cell.
    """
    cells: set[Tuple[int, int]] = set()
    for r, row_str in enumerate(_FOUR_BITMAP):
        for c, ch in enumerate(row_str):
            if ch == "X":
                cells.add((offset_col + c, offset_row + r))
    for r, row_str in enumerate(_TWO_BITMAP):
        for c, ch in enumerate(row_str):
            if ch == "X":
                cells.add((offset_col + 4 + c, offset_row + r))
    return cells


class MazeGenerator:
    """Builds a random maze using recursive backtracking (DFS).

    The result is a perfect maze (exactly one path between any two
    cells) unless ``perfect=False``, in which case dead-ends are
    removed and extra loops are added.
    """

    def __init__(
        self,
        width: int = 20,
        height: int = 15,
        entry: Tuple[int, int] = (0, 0),
        exit: Tuple[int, int] = (-1, -1),
        perfect: bool = True,
        seed: Optional[int] = None,
    ) -> None:
        """Initialise generator settings.

        Args:
            width: Maze width in cells (minimum 3).
            height: Maze height in cells (minimum 3).
            entry: (col, row) start cell.
            exit: (col, row) goal cell; (-1, -1) for bottom-right.
            perfect: If True, no extra loops. If False, dead-ends
                are removed.
            seed: Random seed for reproducibility. None means random.

        Raises:
            ValueError: If dimensions are too small, coordinates are
                out of bounds, or entry equals exit.
        """
        if width < 3 or height < 3:
            raise ValueError("width and height must each be at least 3.")

        self.width = width
        self.height = height
        self.entry = entry

        resolved_exit = (width - 1, height - 1) if exit == (-1, -1) else exit
        self.exit = resolved_exit
        self.perfect = perfect
        self.seed = seed

        if not (0 <= self.entry[0] < width and 0 <= self.entry[1] < height):
            raise ValueError(f"entry {self.entry} is out of bounds.")
        if not (0 <= self.exit[0] < width and 0 <= self.exit[1] < height):
            raise ValueError(f"exit {self.exit} is out of bounds.")
        if self.entry == self.exit:
            raise ValueError("entry and exit must be different cells.")
        if not (self.entry[0] in (0, width - 1) or
                self.entry[1] in (0, height - 1)):
            raise ValueError(
                f"entry {self.entry} must face the external wall.")
        if not (self.exit[0] in (0, width - 1) or
                self.exit[1] in (0, height - 1)):
            raise ValueError(f"exit {self.exit} must face the external wall.")

        if width >= _PATTERN_MIN_WIDTH and height >= _PATTERN_MIN_HEIGHT:
            pattern_w, pattern_h = 7, 5
            offset_col = (width - pattern_w) // 2
            offset_row = (height - pattern_h) // 2
            cells = _build_pattern_cells(offset_col, offset_row)
            if self.entry in cells:
                raise ValueError(
                    f"entry {self.entry} must not be on the 42 pattern.")
            if self.exit in cells:
                raise ValueError(
                    f"exit {self.exit} must not be on the 42 pattern.")

        self.maze: MazeGrid = MazeGrid(
            width=width,
            height=height,
            entry=self.entry,
            exit=self.exit,
        )

    def generate(self) -> MazeGrid:
        """Create the maze and attach the shortest-path solution.

        Returns:
            The fully populated MazeGrid instance.
        """
        rng = random.Random(self.seed)

        self.maze.grid = [
            [Wall.ALL for _ in range(self.width)]
            for _ in range(self.height)
        ]

        self._embed_pattern()

        visited: list[list[bool]] = [
            [False] * self.width for _ in range(self.height)
        ]
        self._dfs(self.entry[0], self.entry[1], visited, rng)

        self._fix_isolated_cells()
        self._fix_wide_corridors(rng)

        if not self.perfect:
            self._add_loops(rng)

        solution = solver.solve(self.maze)
        self.maze.solution = solution if solution is not None else []

        return self.maze

    def _embed_pattern(self) -> None:
        """Draw "42" in the centre of the maze as fully-walled cells.

        Pattern cells are never carved by DFS. If the maze is too
        small, a warning is printed and the step is skipped.
        """
        if (self.width < _PATTERN_MIN_WIDTH
                or self.height < _PATTERN_MIN_HEIGHT):
            print(
                f"[Warning] Maze is too small to embed the '42' "
                f"pattern. Minimum size: {_PATTERN_MIN_WIDTH}x"
                f"{_PATTERN_MIN_HEIGHT}. Current size is "
                f"{self.width}x{self.height}. Skipping pattern."
            )
            return

        pattern_w = 7
        pattern_h = 5
        offset_col = (self.width - pattern_w) // 2
        offset_row = (self.height - pattern_h) // 2

        self.maze.pattern_cells = _build_pattern_cells(offset_col, offset_row)
        self.maze.pattern_cells = self._close_pattern_pockets(
            self.maze.pattern_cells
        )

        for (col, row) in self.maze.pattern_cells:
            self.maze.grid[row][col] = Wall.ALL

    def _close_pattern_pockets(
        self, pattern: set[Tuple[int, int]]
    ) -> set[Tuple[int, int]]:
        """Find cells enclosed by the logo and merge them into the pattern.

        Args:
            pattern: Current set of (col, row) pattern cells.

        Returns:
            An expanded pattern set that includes pocket cells.
        """
        from collections import deque

        w, h = self.width, self.height
        seeds: set[Tuple[int, int]] = set()
        for c in range(w):
            for r in [0, h - 1]:
                if (c, r) not in pattern:
                    seeds.add((c, r))
        for r in range(h):
            for c in [0, w - 1]:
                if (c, r) not in pattern:
                    seeds.add((c, r))

        reachable_from_border: set[Tuple[int, int]] = set(seeds)
        queue: deque[Tuple[int, int]] = deque(seeds)

        while queue:
            col, row = queue.popleft()
            for dc, dr in [(0, -1), (1, 0), (0, 1), (-1, 0)]:
                nc, nr = col + dc, row + dr
                if not (0 <= nc < w and 0 <= nr < h):
                    continue
                if (nc, nr) in pattern:
                    continue
                if (nc, nr) in reachable_from_border:
                    continue
                reachable_from_border.add((nc, nr))
                queue.append((nc, nr))

        all_non_pattern = {
            (c, r) for r in range(h) for c in range(w)
            if (c, r) not in pattern
        }
        pockets = all_non_pattern - reachable_from_border
        return pattern | pockets

    def _is_pattern_cell(self, col: int, row: int) -> bool:
        """Check whether the given cell is part of the "42" pattern."""
        return (col, row) in self.maze.pattern_cells

    def _dfs(
        self,
        col: int, row: int,
        visited: list[list[bool]],
        rng: random.Random,
    ) -> None:
        """Carve passages using randomised depth-first search.

        Args:
            col: Current column.
            row: Current row.
            visited: 2-D visited flags.
            rng: Random number generator instance.
        """
        visited[row][col] = True
        directions = list(Direction)
        rng.shuffle(directions)

        for direction in directions:
            dx, dy = DELTA[direction]
            nc, nr = col + dx, row + dy

            if not (0 <= nc < self.width and 0 <= nr < self.height):
                continue
            if visited[nr][nc]:
                continue
            if self._is_pattern_cell(nc, nr):
                continue

            self._open_passage(col, row, nc, nr, direction)
            self._dfs(nc, nr, visited, rng)

    def _open_passage(
        self,
        col: int, row: int,
        nc: int, nr: int,
        direction: Direction,
    ) -> None:
        """Remove the wall between two adjacent cells.

        Args:
            col: Column of the source cell.
            row: Row of the source cell.
            nc: Column of the neighbour cell.
            nr: Row of the neighbour cell.
            direction: Direction from source to neighbour.
        """
        self.maze.grid[row][col] &= ~WALL_BIT[direction]
        self.maze.grid[nr][nc] &= ~OPPOSITE_WALL[direction]

    def _open_border(self, coord: Tuple[int, int]) -> None:
        """Open whichever outer-edge wall this cell touches.

        Args:
            coord: (col, row) of a border cell.
        """
        col, row = coord
        if row == 0:
            self.maze.grid[row][col] &= ~Wall.NORTH
        elif row == self.height - 1:
            self.maze.grid[row][col] &= ~Wall.SOUTH
        elif col == 0:
            self.maze.grid[row][col] &= ~Wall.WEST
        elif col == self.width - 1:
            self.maze.grid[row][col] &= ~Wall.EAST

    def _fix_isolated_cells(self) -> None:
        """Ensure every non-pattern cell is reachable from the entry."""
        from collections import deque

        grid = self.maze.grid
        w, h = self.width, self.height
        entry = self.maze.entry

        def bfs_reachable() -> set[tuple[int, int]]:
            visited: set[tuple[int, int]] = {entry}
            queue: deque[tuple[int, int]] = deque([entry])
            while queue:
                col, row = queue.popleft()
                for direction in Direction:
                    dc, dr = DELTA[direction]
                    nc, nr = col + dc, row + dr
                    if not (0 <= nc < w and 0 <= nr < h):
                        continue
                    if (nc, nr) in visited:
                        continue
                    if grid[row][col] & WALL_BIT[direction]:
                        continue
                    visited.add((nc, nr))
                    queue.append((nc, nr))
            return visited

        reachable = bfs_reachable()

        all_non_pattern = {
            (c, r)
            for r in range(h) for c in range(w)
            if (c, r) not in self.maze.pattern_cells
        }
        isolated = all_non_pattern - reachable

        for (col, row) in isolated:
            for direction in Direction:
                dc, dr = DELTA[direction]
                nc, nr = col + dc, row + dr
                if not (0 <= nc < w and 0 <= nr < h):
                    continue
                if self._is_pattern_cell(nc, nr):
                    continue
                if (nc, nr) in reachable:
                    self._open_passage(col, row, nc, nr, direction)
                    reachable = bfs_reachable()
                    break

    def _fix_wide_corridors(self, rng: random.Random) -> None:
        """Break up 3x3 open blocks by sealing one random internal wall.

        Args:
            rng: Random number generator instance.
        """
        changed = True
        while changed:
            changed = False
            for row in range(self.height - 2):
                for col in range(self.width - 2):
                    if self._is_3x3_open(col, row):
                        self._seal_random_internal_wall(col, row, rng)
                        changed = True

    def _is_3x3_open(self, top_col: int, top_row: int) -> bool:
        """Check whether a 3x3 block has no internal east/south walls.

        Args:
            top_col: Left column of the block.
            top_row: Top row of the block.

        Returns:
            True if all internal east and south walls are open.
        """
        grid = self.maze.grid
        for r in range(top_row, top_row + 3):
            for c in range(top_col, top_col + 2):
                if grid[r][c] & Wall.EAST:
                    return False
        for c in range(top_col, top_col + 3):
            for r in range(top_row, top_row + 2):
                if grid[r][c] & Wall.SOUTH:
                    return False
        return True

    def _seal_random_internal_wall(
        self, top_col: int, top_row: int, rng: random.Random
    ) -> None:
        """Close one random east or south wall inside a 3x3 region.

        Args:
            top_col: Left column of the block.
            top_row: Top row of the block.
            rng: Random number generator instance.
        """
        candidates: list[tuple[int, int, Direction]] = []
        for r in range(top_row, top_row + 3):
            for c in range(top_col, top_col + 2):
                candidates.append((c, r, Direction.EAST))
        for c in range(top_col, top_col + 3):
            for r in range(top_row, top_row + 2):
                candidates.append((c, r, Direction.SOUTH))

        rng.shuffle(candidates)
        for col, row, direction in candidates:
            nc, nr = col + DELTA[direction][0], row + DELTA[direction][1]
            if (self._is_pattern_cell(col, row)
                    or self._is_pattern_cell(nc, nr)):
                continue
            self.maze.grid[row][col] |= WALL_BIT[direction]
            self.maze.grid[nr][nc] |= OPPOSITE_WALL[direction]
            return

    def _add_loops(self, rng: random.Random) -> None:
        """Remove all dead-ends and add extra loop walls.

        Args:
            rng: Random number generator instance.
        """
        self._remove_dead_ends(rng)
        self._add_extra_loops(rng)

    def _remove_dead_ends(self, rng: random.Random) -> None:
        """Iteratively open one wall at every dead-end cell.

        Args:
            rng: Random number generator instance.
        """
        changed = True
        while changed:
            changed = False
            for r in range(self.height):
                for c in range(self.width):
                    if self._is_pattern_cell(c, r):
                        continue
                    cell = self.maze.grid[r][c]
                    walls_closed = bin(cell).count("1")
                    if walls_closed != 3:
                        continue
                    dirs = list(Direction)
                    rng.shuffle(dirs)
                    for direction in dirs:
                        if not (cell & WALL_BIT[direction]):
                            continue
                        dx, dy = DELTA[direction]
                        nc, nr = c + dx, r + dy
                        if not (0 <= nc < self.width
                                and 0 <= nr < self.height):
                            continue
                        if self._is_pattern_cell(nc, nr):
                            continue
                        self._open_passage(c, r, nc, nr, direction)
                        changed = True
                        break

    def _add_extra_loops(
        self, rng: random.Random, count: int = 5
    ) -> None:
        """Open up to ``count`` random closed walls for added variety.

        Args:
            rng: Random number generator instance.
            count: Maximum number of extra walls to remove.
        """
        attempts = 0
        added = 0
        while added < count and attempts < 1000:
            attempts += 1
            col = rng.randint(0, self.width - 2)
            row = rng.randint(0, self.height - 2)
            direction = rng.choice(list(Direction))
            dx, dy = DELTA[direction]
            nc, nr = col + dx, row + dy
            if not (0 <= nc < self.width and 0 <= nr < self.height):
                continue
            if (self._is_pattern_cell(col, row)
                    or self._is_pattern_cell(nc, nr)):
                continue
            if not (self.maze.grid[row][col] & WALL_BIT[direction]):
                continue
            self._open_passage(col, row, nc, nr, direction)
            added += 1
