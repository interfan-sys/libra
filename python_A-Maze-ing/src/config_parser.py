import sys
from typing import Any, Dict, Tuple

_REQUIRED: Dict[str, type] = {
    "WIDTH": int,
    "HEIGHT": int,
    "ENTRY": str,
    "EXIT": str,
    "OUTPUT_FILE": str,
    "PERFECT": str,
}


def _parse_coord(value: str, key: str) -> Tuple[int, int]:
    """Parse a coordinate string like "col,row" into a tuple.

    Args:
        value: Raw string value from the config file.
        key: Config key name, used in error messages.

    Returns:
        A (col, row) integer tuple.
    """
    parts = value.split(",")
    if len(parts) != 2:
        _error(f"'{key}' must be in the format x,y - got: {value!r}")
    try:
        return int(parts[0].strip()), int(parts[1].strip())
    except ValueError:
        _error(f"'{key}' coordinates must be integers - got: {value!r}")
    return (0, 0)


def _parse_bool(value: str, key: str) -> bool:
    """Parse a boolean string into a Python bool.

    Args:
        value: Raw string value (case-insensitive "true" or "false").
        key: Config key name, used in error messages.

    Returns:
        The parsed boolean value.
    """
    if value.strip().lower() == "true":
        return True
    if value.strip().lower() == "false":
        return False
    _error(f"'{key}' must be True or False - got: {value!r}")
    return False


def _error(msg: str) -> None:
    """Print a config error to stderr and exit.

    Args:
        msg: The error message to display.
    """
    print(f"[Config Error] {msg}", file=sys.stderr)
    sys.exit(1)


def parse_config(filepath: str) -> Dict[str, Any]:
    """Read a config file and return typed maze settings.

    Args:
        filepath: Path to the configuration file.

    Returns:
        A dictionary with keys WIDTH, HEIGHT, ENTRY, EXIT,
        OUTPUT_FILE, PERFECT, and optionally SEED.

    Raises:
        SystemExit: If the file is missing, malformed, or incomplete.
    """
    raw: Dict[str, str] = {}

    try:
        with open(filepath, "r", encoding="utf-8") as fh:
            for lineno, line in enumerate(fh, start=1):
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                if "=" not in line:
                    _error(
                        f"Line {lineno}: expected KEY=VALUE, got: {line!r}"
                    )
                key, _, value = line.partition("=")
                key = key.strip().upper()
                value = value.strip()
                if "#" in value:
                    value = value[: value.index("#")].strip()
                if key in raw:
                    _error(f"Line {lineno}: duplicate key: {key!r}")
                raw[key] = value
    except FileNotFoundError:
        _error(f"Configuration file not found: {filepath!r}")

    for key in _REQUIRED:
        if key not in raw:
            _error(f"Missing required key: '{key}'")

    config: Dict[str, Any] = {}

    try:
        config["WIDTH"] = int(raw["WIDTH"])
        config["HEIGHT"] = int(raw["HEIGHT"])
    except ValueError as exc:
        _error(f"WIDTH and HEIGHT must be integers: {exc}")

    config["ENTRY"] = _parse_coord(raw["ENTRY"], "ENTRY")
    config["EXIT"] = _parse_coord(raw["EXIT"], "EXIT")
    config["OUTPUT_FILE"] = raw["OUTPUT_FILE"]
    config["PERFECT"] = _parse_bool(raw["PERFECT"], "PERFECT")

    if "SEED" in raw:
        try:
            config["SEED"] = int(raw["SEED"])
        except ValueError:
            _error(f"SEED must be an integer - got: {raw['SEED']!r}")
    else:
        config["SEED"] = None

    return config
