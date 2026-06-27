#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, days_old: int) -> None:
        self.name = name
        self.height = round(height, 2)
        self.days_old = days_old


    def show_result(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days_old} days old")


def main():
    print("=== Garden Plant Growth ===")
    rose = Plant("Rose", 25, 30)
    rose.show_result()
    before_increase = rose.height
    for Day in range(1, 8):
        rose.grow(0.8)
        rose.age(1)
        print(f"=== Day {Day} ===")
        rose.show_result()
    total_growth = rose.height
    total_growth = round(rose.height - before_increase, 2)
    print(f"Growth this week: {total_growth}cm")


if __name__ == "__main__":
    main()
