#!/usr/bin/env python3
import math
from typing import Tuple


def get_player_pos() -> Tuple[float, float, float]:
    while True:
        arguments = input(
            "Enter new coordinates as floats in format 'x,y,z': "
            )
        coordinates = arguments.split(',')
        if len(coordinates) != 3:
            print('Invalid syntax')
            continue
        values = []
        for c in coordinates:
            c = c.strip()
            try:
                values.append(float(c))
            except ValueError:
                print(
                    f"Error on parameter '{c}':"
                    f"could not convert string to float: '{c}'"
                    )
                break
        else:
            x, y, z = values
            return x, y, z


def main():
    print("=== Game Coordinate System ===")
    print("Get a first set of coordinates")
    pos1 = get_player_pos()
    print(f"Got a first tuple: {pos1}")
    x1, y1, z1 = pos1
    print(f"It includes: X={x1}, Y={y1}, Z={z1}")
    distance_to_center = math.sqrt((0 - x1)**2 + (0 - y1)**2 + (0 - z1)**2)
    print(f"Distance to center: {distance_to_center:.4f}\n")
    print("Get a second set of coordinates")
    pos2 = get_player_pos()
    x2, y2, z2 = pos2
    distance_between = math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2)
    print(
        "Distance between the 2 sets of coordinates:"
        f"{distance_between:.4f}"
     )


if __name__ == "__main__":
    main()
