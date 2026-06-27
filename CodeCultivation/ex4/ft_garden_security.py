#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        if height < 0:
            print(f"{name}: Error, height can't be negative")
            self._height = 0
        else:
            self._height = height
        if age < 0:
            print(f"{name}: Error, age can't be negative")
            self._age = 0
        else:
            self._age = age

    def set_height(self, height: int) -> None:
        if height < 0:
            print(
                f"{self._name}: Error, height can't be negative\n"
                "Height update rejected"
            )
        else:
            self._height = height

    def get_height(self) -> int:
        return self._height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age

    def get_age(self) -> int:
        return self._age

    def show(self) -> str:
        tall = round(self._height, 1)
        return (f"{self._name}: {tall}cm, {self._age} days old")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant1 = Plant("Rose", 15.0, 10)
    print("Plant Created: ", plant1.show())
    plant1.set_height(25.0)
    plant1.set_age(30)
    print(f"Height updated: {plant1.get_height()}cm")
    print(f"Age updated: {plant1.get_age()} days")
    plant1.set_height(-1)
    plant1.set_age(-1)
    print("Current state: ", plant1.show())