import sys
import tty
import termios
from typing import Callable


def _getch() -> str:
    """Read a single character from stdin without waiting for Enter.

    Temporarily switches the terminal to raw mode, reads one byte,
    then restores the original terminal settings.

    Returns:
        The single character that was pressed.
    """
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(fd)
        ch = sys.stdin.read(1)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch


def run_interactive_loop(
    on_regen: Callable[[], None],
    on_toggle_path: Callable[[], None],
    on_cycle_color: Callable[[], None],
    on_toggle_pattern: Callable[[], None],
    on_render: Callable[[], None],
) -> None:
    """Run the interactive key-listening loop until the user quits.

    Args:
        on_regen: Callback to regenerate a new maze.
        on_toggle_path: Callback to show/hide the solution path.
        on_cycle_color: Callback to cycle the wall colour.
        on_toggle_pattern: Callback to show/hide the "42" highlight.
        on_render: Callback to redraw the screen.
    """
    on_render()

    key_map: dict[str, Callable[[], None]] = {
        "1": on_regen,
        "r": on_regen,
        "2": on_toggle_path,
        "p": on_toggle_path,
        "3": on_cycle_color,
        "c": on_cycle_color,
        "4": on_toggle_pattern,
        "5": lambda: _quit(),
        "q": lambda: _quit(),
    }

    def _quit() -> None:
        print("\n\033[0mBye!\n")
        sys.exit(0)

    try:
        while True:
            key = _getch()

            if key in ("\x03", "\x1b"):
                _quit()

            if key in key_map:
                key_map[key]()
                on_render()

    except KeyboardInterrupt:
        print("\n\033[0mInterrupted. Bye!\n")
        sys.exit(0)
