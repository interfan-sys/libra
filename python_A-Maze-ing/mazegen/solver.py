from collections import deque
from typing import List, Optional, Tuple

from mazegen.models import (
    Direction, DELTA, WALL_BIT, DIRECTION_LETTER, MazeGrid
)


def solve(maze: MazeGrid) -> Optional[List[str]]:
    """Find the shortest path from entry to exit using BFS.

    Args:
        maze: A fully generated MazeGrid instance.

    Returns:
        A list of direction letters ("N", "E", "S", "W") representing
        the shortest path, or ``None`` if the exit is unreachable.
    """
    grid = maze.grid
    start: Tuple[int, int] = maze.entry
    goal: Tuple[int, int] = maze.exit
    width = maze.width
    height = maze.height

    queue: deque[Tuple[int, int, List[str]]] = deque()
    queue.append((start[0], start[1], []))
    visited: set[Tuple[int, int]] = {start}

    while queue:
        col, row, path = queue.popleft()

        if (col, row) == goal:
            return path

        for direction in Direction:
            dx, dy = DELTA[direction]
            nc, nr = col + dx, row + dy

            if not (0 <= nc < width and 0 <= nr < height):
                continue
            if (nc, nr) in visited:
                continue

            wall_bit = WALL_BIT[direction]
            if grid[row][col] & wall_bit:
                continue

            visited.add((nc, nr))
            queue.append((nc, nr, path + [DIRECTION_LETTER[direction]]))

    return None
