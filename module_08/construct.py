#!/usr/bin/env python3
import sys
import os
import site


def main() -> None:

    if sys.prefix != sys.base_prefix:
        print("MATRIX STATUS: Welcome to the constructor")
        print()
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {os.path.basename(sys.prefix)}")
        print(f"Environment Path: {sys.prefix}")
        print()
        print("Success you are in an isolated environment\n"
                "Safe to install packages without affecting\n"
                "the global system."
        )
  ``      print(f"Package installation path: {site.getsitepackages()[0]}")
    else:
        print("MATRIX STATUS: You're still plugged in")
        print()
        print(f"Current Python: {sys.executable}")
        print("Virtual Environment: None detected\n")
        print("WARNING: You're in the global environment!\n"
              "The machines can see everything you install."
              )
        print()
        print("To enter the construct, run:\n"
              "python -m venv matrix_env\n"
              "source matrix_env/bin/activate # On Unix\n"
              "matrix_env\\Scripts\\activate # On Windows\n"
              "Then run this program again."
        )

if __name__ == "__main__":
    main()
