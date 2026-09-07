from enum import IntEnum
from dataclasses import dataclass, field
from typing import List, Tuple


class Wall(IntEnum):
    """Bitmask for which walls are closed on a single maze cell.

    A bit set to 1 means that side has a wall. For example, value 3
    (binary 0011) means North and East are closed.
    """

    NORTH = 1
    EAST = 2
    SOUTH = 4
    WEST = 8
    ALL = 15
    NONE = 0


class Direction(IntEnum):
    """The four compass directions used when carving or solving the maze."""

    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3


DELTA: dict[Direction, Tuple[int, int]] = {
    Direction.NORTH: (0, -1),
    Direction.EAST: (1, 0),
    Direction.SOUTH: (0, 1),
    Direction.WEST: (-1, 0),
}

WALL_BIT: dict[Direction, Wall] = {
    Direction.NORTH: Wall.NORTH,
    Direction.EAST: Wall.EAST,
    Direction.SOUTH: Wall.SOUTH,
    Direction.WEST: Wall.WEST,
}

OPPOSITE_WALL: dict[Direction, Wall] = {
    Direction.NORTH: Wall.SOUTH,
    Direction.EAST: Wall.WEST,
    Direction.SOUTH: Wall.NORTH,
    Direction.WEST: Wall.EAST,
}

DIRECTION_LETTER: dict[Direction, str] = {
    Direction.NORTH: "N",
    Direction.EAST: "E",
    Direction.SOUTH: "S",
    Direction.WEST: "W",
}


@dataclass
class MazeGrid:
    """Container holding all data for one generated maze.

    Attributes:
        width: Number of columns in the grid.
        height: Number of rows in the grid.
        grid: 2-D list of wall bitmask values (0-15), indexed as
            ``grid[row][col]``.
        entry: ``(col, row)`` start position.
        exit: ``(col, row)`` goal position.
        pattern_cells: Set of ``(col, row)`` cells forming the "42" logo.
        solution: List of direction letters ("N", "E", "S", "W") from
            entry to exit.
    """

    width: int
    height: int
    grid: List[List[int]] = field(default_factory=list)
    entry: Tuple[int, int] = (0, 0)
    exit: Tuple[int, int] = (0, 0)
    pattern_cells: set = field(default_factory=set)
    solution: List[str] = field(default_factory=list)
