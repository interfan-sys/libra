

#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "The tomato plant is wilting!") -> None:
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    """Tries to water a plant if the name is capitalized, otherwise raises PlantError."""
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system(plants_list: tuple[str, ...]) -> None:
    """Manages the lifecycle of watering multiple plants and guarantees resource cleanup."""
    print("Opening watering system")
    try:
        for plant in plants_list:
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
        return  # Stop the test immediately and return to main
    finally:
        print("Closing watering system")
        print("Cleanup always happens, even with errors!")


def main():
    print("=== Garden Watering System ===")
    
    print("Testing valid plants...")
    valid_plants = ("Tomato", "Lettuce", "Carrots")
    test_watering_system(valid_plants)
    
    print("\nTesting invalid plants...")
    mixed_plants = ("Tomato", "lettuce", "Carrots")
    test_watering_system(mixed_plants)


if __name__ == "__main__":
    main()
