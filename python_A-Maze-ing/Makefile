.PHONY: venv install run debug clean lint lint-strict test build

venv:
	python3 -m venv .venv
	.venv/bin/pip install --upgrade pip
	.venv/bin/pip install -r requirements.txt
	.venv/bin/pip install -e ".[dev]"
	@echo ""
	@echo "Virtual environment created. Activate it with:"
	@echo "  source .venv/bin/activate"

install:
	pip install -r requirements.txt

run:
	python3 a_maze_ing.py config.txt

debug:
	python3 -m pdb a_maze_ing.py config.txt

lint:
	flake8 . --exclude=.venv
	mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports \
		--disallow-untyped-defs --check-untyped-defs

lint-strict:
	flake8 .
	mypy . --strict

clean:
	find . -type d -name __pycache__ -exec rm -rf {} + 2>/dev/null; true
	find . -name "*.pyc" -delete
	rm -rf dist/ build/ *.egg-info *.whl *.tar.gz
	rm -rf .mypy_cache/ .pytest_cache/

build:
	pip install --quiet build
	python -m build --outdir .
