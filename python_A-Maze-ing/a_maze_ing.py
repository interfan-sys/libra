import sys
from src.config_parser import parse_config
from src.output_writer import write_output
from src.renderer import MazeRenderer
from src.interactive import run_interactive_loop
from mazegen.generator import MazeGenerator


def _build(config: dict) -> MazeRenderer:
    """Generate a maze, save it to disk, and return a renderer.

    Args:
        config: Dictionary of maze settings from the config file.

    Returns:
        A MazeRenderer wrapping the newly generated maze.

    Raises:
        SystemExit: If the configuration contains invalid values.
    """
    try:
        gen = MazeGenerator(
            width=config["WIDTH"],
            height=config["HEIGHT"],
            entry=config["ENTRY"],
            exit=config["EXIT"],
            perfect=config["PERFECT"],
            seed=config.get("SEED"),
        )
        gen.generate()
    except ValueError as exc:
        print(f"[Error] {exc}", file=sys.stderr)
        sys.exit(1)

    write_output(gen.maze, config["OUTPUT_FILE"])
    return MazeRenderer(gen.maze)


def main() -> None:
    """Load config, display the first maze, then enter the interactive loop."""
    config_path = sys.argv[1] if len(sys.argv) > 1 else "config.txt"
    config = parse_config(config_path)

    renderer = _build(config)

    def handle_regen() -> None:
        nonlocal renderer
        old_color = renderer.wall_color_idx
        old_show_sol = renderer.show_solution
        old_show_pat = renderer.show_pattern
        renderer = _build(config)
        renderer.wall_color_idx = old_color
        renderer.show_solution = old_show_sol
        renderer.show_pattern = old_show_pat

    run_interactive_loop(
        on_regen=handle_regen,
        on_toggle_path=lambda: renderer.toggle_solution(),
        on_cycle_color=lambda: renderer.cycle_wall_color(),
        on_toggle_pattern=lambda: renderer.toggle_pattern(),
        on_render=lambda: renderer.render(),
    )


if __name__ == "__main__":
    main()
