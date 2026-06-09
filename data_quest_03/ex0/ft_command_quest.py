#!/usr/bin/env python3

import sys


def main():
    print("=== Command Quest ===")
    name: str = sys.argv[0]
    print(f"Program name: {name}")
    arg_len = len(sys.argv)
    if arg_len == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {arg_len}")
        i = 1
        while i < arg_len:
            print(f"Argument {i}: {sys.argv[i]}")
            i += 1
    print(f"Total arguments: {arg_len}")


if __name__ == "__main__":
    main()
