import sys
from mazegen.models import MazeGrid


def write_output(maze: MazeGrid, filepath: str) -> None:
    """Save the maze to disk in the required output format.

    Each cell's wall bitmask (0-15) is written as one uppercase hex
    character. The grid is followed by a blank line, entry/exit
    coordinates, and the solution path.

    Args:
        maze: A fully generated MazeGrid instance.
        filepath: Destination file path.

    Raises:
        SystemExit: If the file cannot be written.
    """
    try:
        with open(filepath, "w", encoding="utf-8") as fh:
            for row in maze.grid:
                fh.write("".join(format(cell, "X") for cell in row) + "\n")

            fh.write("\n")
            fh.write(f"{maze.entry[0]},{maze.entry[1]}\n")
            fh.write(f"{maze.exit[0]},{maze.exit[1]}\n")

            if maze.solution:
                fh.write("".join(maze.solution) + "\n")
            else:
                fh.write("\n")

    except OSError as exc:
        print(f"[Output Error] Cannot write to {filepath!r}: {exc}",
              file=sys.stderr)
        sys.exit(1)
