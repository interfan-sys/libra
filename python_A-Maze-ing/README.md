*This project has been created as part of the 42 curriculum by cbogale, agkicina.*

---

# A-Maze-ing

## Description

A-Maze-ing is a terminal-based maze generator and solver built as part of the 42 curriculum.
The program generates a random, perfectly connected maze, embeds a visible **"42"** pattern
formed by fully-closed cells, computes the shortest path between entry and exit using BFS,
and provides an interactive ASCII terminal display with live user controls.

The core generation logic is packaged as a standalone, pip-installable Python module
(`mazegen`) so it can be reused in future projects.

---

## Instructions

### Requirements

- Python 3.10+
- `pip` (for installing the `mazegen` package and dev tools)

### Setting up a virtual environment (recommended)

It is recommended to use a virtual environment for dependency isolation during
development. The quickest way is the Makefile shortcut:

```bash
make venv
source .venv/bin/activate
```

This creates a `.venv/` directory, installs all dependencies, and installs the
`mazegen` package in editable mode.

**Manual setup** (if you prefer not to use `make`):

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install --upgrade pip
pip install -r requirements.txt
pip install -e ".[dev]"
```

> **Note:** All subsequent commands (`make run`, `make test`, `make lint`, etc.)
> should be run with the virtual environment activated.

### Install dependencies

```bash
pip install -r requirements.txt
```

Or install in development mode with the `mazegen` package available for import:

### Run the maze

```bash
python3 a_maze_ing.py            # uses config.txt by default
python3 a_maze_ing.py myconfig.txt
```

Or via the Makefile:

```bash
make run
```

### Interactive controls

| Key | Action |
|-----|--------|
| `r` | Re-generate a new maze |
| `p` | Show / hide the shortest solution path |
| `c` | Cycle through wall colours |
| `4` | Toggle "42" pattern highlight |
| `q` / `Esc` / `Ctrl-C` | Quit |

### Run the test suite

```bash
make test
# or
pytest
```

### Build the `mazegen` package

```bash
make build
# Produces: mazegen-1.0.0-py3-none-any.whl
#       and: mazegen-1.0.0.tar.gz
```

To install the built package in a virtualenv:

```bash
python -m venv .venv
source .venv/bin/activate
pip install setuptools wheel build
make build
pip install mazegen-1.0.0-py3-none-any.whl
```

---

## Configuration File

The program reads a `KEY=VALUE` configuration file (default: `config.txt`).
Lines starting with `#` and blank lines are ignored.

| Key | Type | Required | Description | Example |
|---|---|---|---|---|
| `WIDTH` | int | ✅ | Number of columns | `WIDTH=20` |
| `HEIGHT` | int | ✅ | Number of rows | `HEIGHT=15` |
| `ENTRY` | x,y | ✅ | Entry cell coordinates | `ENTRY=0,0` |
| `EXIT` | x,y | ✅ | Exit cell coordinates | `EXIT=19,14` |
| `OUTPUT_FILE` | str | ✅ | Path for the output file | `OUTPUT_FILE=maze.txt` |
| `PERFECT` | bool | ✅ | Enforce single path (True/False) | `PERFECT=True` |
| `SEED` | int | ❌ | RNG seed for reproducibility | `SEED=42` |

Example `config.txt`:

```
WIDTH=20
HEIGHT=15
ENTRY=0,0
EXIT=19,14
OUTPUT_FILE=maze.txt
PERFECT=True
SEED=42
```

---

## Output File Format

The output file contains:

1. **Grid section**: one row per line, one uppercase hex digit per cell.
   Each digit encodes which walls are **closed** (bit = 1):

   | Bit | Direction |
   |-----|-----------|
   | 0 (LSB) | North |
   | 1 | East |
   | 2 | South |
   | 3 (MSB) | West |

   Example: `3` (binary `0011`) → North and East walls closed.

2. **Empty line** separator.

3. **Entry coordinates** (`col,row`).

4. **Exit coordinates** (`col,row`).

5. **Shortest path** as a string of `N`, `E`, `S`, `W` letters.

All lines end with `\n`.

---

## Generation Algorithm

**Recursive Backtracking (Depth-First Search)**

The generator initialises every cell as fully walled (`0xF`), then carves passages using
a randomised DFS from the entry cell. At each step it picks a random unvisited non-pattern
neighbour, removes the shared wall, and recurses. When all neighbours are visited it
backtracks.

### Why this algorithm?

- **Guaranteed perfect maze**: DFS visits every cell exactly once, producing a spanning
  tree with no loops — exactly one path between any two cells.
- **Long, winding corridors**: The aesthetic result is visually interesting compared to
  Prim's or Kruskal's algorithms, which tend to produce shorter, bushier corridors.
- **Simple implementation**: Easy to audit, test, and explain at evaluation.
- **Predictable complexity**: O(width × height) time and space.

### Additional constraints enforced

1. **"42" pattern**: Selected cells are pre-blocked before DFS so they remain fully walled,
   forming the visual glyph.
2. **Interior pocket repair**: Cells fully enclosed by pattern cells (e.g., the hole inside
   the "4") are detected via border flood-fill and merged into the pattern set.
3. **Isolated cell repair**: After DFS, a BFS from entry detects any unreachable
   non-pattern cells and punches a passage to the nearest reachable neighbour.
4. **No 3×3 open areas**: A post-generation scan seals random walls inside any 3×3 open
   region until none remain.
5. **Imperfect mode** (`PERFECT=False`): Five random extra passages are added after DFS,
   creating loops.

---

## Reusable Module (`mazegen`)

The maze generation logic lives entirely in the `mazegen/` package. It is **independent**
of the main program and can be installed via `pip`.

### Installation

```bash
pip install mazegen-1.0.0-py3-none-any.whl
```

### Basic usage

```python
from mazegen.generator import MazeGenerator

# Create and generate a 20×15 perfect maze
gen = MazeGenerator(width=20, height=15)
gen.generate()

# Access the raw grid (list[list[int]], bitmask 0–15 per cell)
grid = gen.maze.grid

# Entry and exit coordinates (col, row)
print(gen.maze.entry)   # e.g. (0, 0)
print(gen.maze.exit)    # e.g. (19, 14)

# Shortest path from entry to exit
print(gen.maze.solution)  # ['E', 'S', 'S', 'E', ...]

# Set of (col, row) cells forming the "42" pattern
print(gen.maze.pattern_cells)
```

### Custom parameters

```python
gen = MazeGenerator(
    width=30,
    height=20,
    entry=(0, 0),
    exit=(29, 19),
    perfect=True,   # False = imperfect maze with loops
    seed=42,        # Omit for random; set for reproducibility
)
gen.generate()
```

### Solving independently

```python
from mazegen.solver import solve

path = solve(gen.maze)   # returns list[str] | None
```

### Public API summary

| Symbol | Module | Description |
|---|---|---|
| `MazeGenerator` | `mazegen.generator` | Main class — generate and access maze |
| `solve` | `mazegen.solver` | BFS solver, returns list of N/E/S/W letters |
| `MazeGrid` | `mazegen.models` | Dataclass holding grid, entry, exit, solution, pattern_cells |
| `Wall` | `mazegen.models` | IntEnum bitmask constants (NORTH, EAST, SOUTH, WEST, ALL, NONE) |
| `Direction` | `mazegen.models` | IntEnum for cardinal directions |

---

## Resources

### Algorithm references

- [Maze Generation: Recursive Backtracking — jamisbuck.org](https://weblog.jamisbuck.org/2010/12/27/maze-generation-recursive-backtracking)
- [Mazes for Programmers — Jamis Buck (book)](http://www.mazesforprogrammers.com/)
- [Wikipedia — Maze generation algorithm](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
- [Wikipedia — Flood fill](https://en.wikipedia.org/wiki/Flood_fill)

### AI usage

- **Research**: looking up algorithm details (recursive backtracking, BFS, flood-fill)
  and bitwise operations.
- **Explaining concepts**: clarifying how bitmask wall encoding works, how DFS guarantees
  a spanning tree, and how to detect interior pockets via border flood-fill.

---

## Team & Project Management

### Roles

| Login | Role |
|---|---|
| cbogale | Coding, research, and project architecture |
| agkicina | Coding, research, and project architecture |

### Planning

We initially focused on understanding the specifications and designing the architecture. Then, we developed the core maze generation algorithm and solved any connectivity issues. Finally, we polished the output file format, terminal renderer, and test suite to ensure robust performance.

### What worked well

- Using bitmask walls (`0–15`) made coherence checking and rendering straightforward.
- Separating `mazegen/` from `src/` kept the reusable module truly independent.

### What could be improved

- A second algorithm (Prim's or Wilson's) could be added for bonus marks.
- We could use MLX for a machine-learning-driven maze generator variant.
- A separate graphical visualiser (e.g., Pygame or a web front-end) would make
  the maze easier to explore outside the terminal.

### Tools used

- **Python 3.10+**
- **VS Code**
