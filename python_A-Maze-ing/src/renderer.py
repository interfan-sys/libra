from mazegen.models import MazeGrid, Wall

RESET = "\033[0m"
BOLD = "\033[1m"

WALL_COLORS = [
    "\033[97m",
    "\033[91m",
    "\033[93m",
    "\033[92m",
    "\033[94m",
    "\033[95m",
    "\033[96m",
]

PATH_COLOR = "\033[46;30m"
ENTRY_COLOR = "\033[45;97m"
EXIT_COLOR = "\033[41;97m"
PATTERN_COLOR = "\033[100;37m"


class MazeRenderer:
    """Terminal renderer that draws a maze with ANSI colours.

    Supports toggling the solution path, cycling wall colours,
    and highlighting the "42" pattern.
    """

    def __init__(self, maze: MazeGrid) -> None:
        """Attach a maze and prepare default display options.

        Args:
            maze: A fully generated MazeGrid instance.
        """
        self.maze = maze
        self.show_solution: bool = False
        self.wall_color_idx: int = 0
        self.show_pattern: bool = True
        self._solution_set: set[tuple[int, int]] = set()
        self._build_solution_set()

    def _build_solution_set(self) -> None:
        """Convert the solution letter list into a set of (col, row) cells."""
        self._solution_set = set()
        if not self.maze.solution:
            return
        col, row = self.maze.entry
        self._solution_set.add((col, row))
        dx_map = {"N": (0, -1), "E": (1, 0), "S": (0, 1), "W": (-1, 0)}
        for letter in self.maze.solution:
            dc, dr = dx_map[letter]
            col += dc
            row += dr
            self._solution_set.add((col, row))

    def cycle_wall_color(self) -> None:
        """Advance to the next wall colour, wrapping at the end."""
        self.wall_color_idx = (self.wall_color_idx + 1) % len(WALL_COLORS)

    def toggle_solution(self) -> None:
        """Toggle the solution path visibility."""
        self.show_solution = not self.show_solution

    def toggle_pattern(self) -> None:
        """Toggle the "42" pattern highlight visibility."""
        self.show_pattern = not self.show_pattern

    def render(self) -> None:
        """Clear the terminal and draw the maze with the interactive menu."""
        print("\033[H\033[2J\033[3J", end="")
        grid = self.maze.grid
        wc = WALL_COLORS[self.wall_color_idx]
        height = self.maze.height
        width = self.maze.width

        lines: list[str] = []

        top_row = ""
        for col in range(width):
            top_row += wc + "+" + RESET
            top_wall = bool(grid[0][col] & Wall.NORTH)
            top_row += (wc + "--" + RESET) if top_wall else "  "
        top_row += wc + "+" + RESET
        lines.append(top_row)

        for row in range(height):
            mid_line = ""

            for col in range(width):
                cell = grid[row][col]
                left_wall = bool(cell & Wall.WEST)
                mid_line += (wc + "|" + RESET) if left_wall else " "
                mid_line += self._cell_interior(col, row)

            right_wall = bool(grid[row][width - 1] & Wall.EAST)
            mid_line += (wc + "|" + RESET) if right_wall else " "
            lines.append(mid_line)

            div_row = ""
            for col in range(width):
                div_row += wc + "+" + RESET
                south_wall = bool(grid[row][col] & Wall.SOUTH)
                div_row += (wc + "--" + RESET) if south_wall else "  "
            div_row += wc + "+" + RESET
            lines.append(div_row)

        print("\n".join(lines))
        self._print_menu()

    def _cell_interior(self, col: int, row: int) -> str:
        """Return the coloured interior string for a single cell.

        Args:
            col: Cell column.
            row: Cell row.

        Returns:
            A two-character string with appropriate ANSI colouring.
        """
        is_entry = (col, row) == self.maze.entry
        is_exit = (col, row) == self.maze.exit
        is_path = self.show_solution and (col, row) in self._solution_set
        is_pattern = (
            self.show_pattern
            and (col, row) in self.maze.pattern_cells
        )

        if is_entry:
            return f"{ENTRY_COLOR}  {RESET}"
        if is_exit:
            return f"{EXIT_COLOR}  {RESET}"
        if is_pattern:
            return f"{PATTERN_COLOR}  {RESET}"
        if is_path:
            return f"{PATH_COLOR}  {RESET}"
        return "  "

    def _print_menu(self) -> None:
        """Print the interactive menu below the maze."""
        print(f"\n{BOLD}=== A-Maze-ing ==={RESET}")
        print("  1. Re-generate a new maze")
        print("  2. Show/Hide path from entry to exit")
        print("  3. Rotate maze colours")
        print("  4. Toggle '42' pattern highlight")
        print("  5. Quit")
        print("Choice? (1-5): ", end="", flush=True)
