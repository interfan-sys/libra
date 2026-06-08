#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "The tomato plant is wilting!") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Not enough water in the tank!") -> None:
        super().__init__(message)


def input_tests(days: int) -> int:
    if days <= 2:
        raise WaterError()
    elif days >= 5:
        raise PlantError()
    return days


def test_error_types(days: int) -> None:
    try:
        input_tests(days)
    except PlantError as e:
        print(f"Caught PlantError: {e}\n")
    except WaterError as e:
        print(f"Caught WaterError: {e}\n")


def test_garden_error(days: int) -> None:
    try:
        input_tests(days)
    except GardenError as e:
        print(f"Caught GardenError: {e}\n")


def main():
    print("=== Custom Garden Errors Demo ===\n")
    print("Testing PlantError...")
    test_error_types(6)
    print("Testing WaterError...")
    test_error_types(2)
    print("Testing catching all garden errors...")
    test_garden_error(6)
    test_garden_error(2)
    print("All custom error types work correctly!")


if __name__ == "__main__":
    main()
