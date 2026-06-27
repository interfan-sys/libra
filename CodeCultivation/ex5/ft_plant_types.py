#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> str:
        plant_height = round(self.height, 1)
        return (f"{self.name}: {plant_height}cm, {self.age} days old")


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        color: str
    ) -> None:
        super().__init__(name, height, age)
        self.color = color

    def show(self) -> str:
        return f"=== Flower\n{super().show()} \n Color: {self.color}"

    def bloom(self) -> None:
        print("Rose has not bloomed yet")
        print("[asking the rose to bloom]")
        print(self.show()cd )
        print("Rose is blooming beautfully!\n")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def show(self):
        diameter = round(self.trunk_diameter, 1)
        return f"=== Tree\n{super().show()}\nTrunk Diameter: {diameter}cm"

    def produce_shade(self):
        print("[aksing the oak to produce shade]")
        h = self.height
        d = self.trunk_diameter
        print(f"Tree Oak now produces a shade of {h}cm long and {d}cm wide\n")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        harvest_season: str,
        nutritional_value: int
    ) -> None:
        super().__init__(name, height, age)
        self.harvest: str = harvest_season
        self.n_value: int = nutritional_value

    def show(self) -> str:
        harvest = self.harvest
        nutri = self.n_value
        season = "Harvest season"
        nutri_value = "Nutritional value"
        return f"{super().show()}\n{season}: {harvest}\n{nutri_value}: {nutri}"

    def grow(self, days: int) -> None:
        print("[make tomato grow and age for 20 days]")
        for growth in range(days):
            self.age += 1
            self.height += 2.1
            self.n_value += 1


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    flower1 = Flower("Rose", 15.0, 10, "red")
    print(flower1.show())
    flower1.bloom()
    tree1 = Tree("Oak", 200.0, 365, 5.0)
    print(tree1.show())
    tree1.produce_shade()
    print("=== Vegetable")
    vegetable1 = Vegetable("Tomato", 5.0, 10, "April", 0)
    print(vegetable1.show())
    vegetable1.grow(20)
    print(vegetable1.show())
