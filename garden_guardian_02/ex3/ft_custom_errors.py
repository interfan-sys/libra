#!/usr/bin/env python3

class GardenError(Exception):
    """A basic error for garden problems"""
    def __init__(self, message="Unknown garden error"):
        super().__init__(message)


class PlantError(GardenError):
    """For problems with plants (inherits from GardenError)"""
    def __init__(self, message="The tomato plant is wilting!"):
        super().__init__(message)


class WaterError(GardenError):
    """For problems with watering (inherits from GardenError)"""
    def __init__(self, message="Not enough water in the tank!"):
        super().__init__(message)


def input_tests(days: int) -> int:
    """Raises custom errors depending on the number of days."""
    if days <= 2:
        raise WaterError()
    elif days >= 5:
        raise PlantError()
    return days


def test_error_types(days: int) -> None:
    """Shows how to catch specific error types."""
    try:
        input_tests(days)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    except WaterError as e:
        print(f"Caught WaterError: {e}")


def test_garden_error(days: int) -> None:
    """Demonstrates that catching GardenError catches all garden-related errors."""
    try:
        input_tests(days)
    except GardenError as e:
        print(f"Caught GardenError: {e}")


def main():
    print("=== Custom Garden Errors Demo ===")
    
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
