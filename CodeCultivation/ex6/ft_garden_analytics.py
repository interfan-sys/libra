#!/usr/bin/env python3

class Plant:

    class _Analytics:
        def __init__(self):
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0
            self._shade_calls = 0

        def get_grow_calls(self):
            self._grow_calls += 1

        def get_age_calls(self):
            self._age_calls += 1

        def get_show_calls(self):
            self._show_calls += 1

        def get_shade_calls(self):
            self._shade_calls += 1

        def display(self):
            print(
                f"Stats: {self._grow_calls} grow, "
                f"{self._age_calls} age, "
                f"{self._show_calls} show"
            )

        def display_tree(self):
            print(
                f"Stats: {self._grow_calls} grow, "
                f"{self._age_calls} age, "
                f"{self._show_calls} show\n"
                f"{self._shade_calls} shade"
            )

    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._stats = Plant._Analytics()
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
        self._stats.get_show_calls()
        plant_height = round(self._height, 1)
        return (f"{self._name}: {plant_height}cm, {self._age} days old")

    def grow(self, amount: int) -> None:
        self._height = round(self._height + amount, 2)
        self._stats.get_grow_calls()

    def age(self, days: int) -> None:
        self._age += days
        self._stats.get_age_calls()

    @staticmethod
    def olderthen_oneyear(age_old: int) -> bool:
        return age_old > 365

    @classmethod
    def anonymous_class(cls):
        anonymous_obj = cls("Unknown plant", 0.0, 0)
        return anonymous_obj


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        color: str
    ) -> None:
        super().__init__(name, height, age)
        self.color = color

    def show(self) -> str:
        return f"{super().show()}\nColor: {self.color}"

    def bloom(self) -> None:
        print(self.show())
        print(f"{self._name} is blooming beautfully!")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def show(self):
        diameter = round(self.trunk_diameter, 1)
        return f"{super().show()}\nTrunk Diameter: {diameter}cm"

    def produce_shade(self):
        self._stats.get_shade_calls()

        h = self._height
        d = self.trunk_diameter
        print(f"Tree Oak now produces a shade of {h}cm long and {d}cm wide")


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        color:
        str,
        seeds: int
    ) -> None:
        super().__init__(name, height, age, color)
        self.seeds = seeds

    def show(self) -> str:
        return f"{super().show()} \nSeeds: {self.seeds}"

    def sun_bloom(self):
        self.seeds = 42
        return f"{super().bloom()}\n {self.seeds}"


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant._name}]")
    plant._stats.display()


def main():
    Plant.olderthen_oneyear(30)
    Plant.olderthen_oneyear(400)
    print("""
    === Flower""")
    flower1 = Flower("Rose", 15.0, 10, "red")
    print(flower1.show())
    print("Rose has not bloomed yet")
    display_statistics(flower1)
    flower1.grow(8.0)
    flower1.bloom()
    display_statistics(flower1)
    print("""
    === Tree""")
    tree1 = Tree("Oak", 200.0, 365, 5.0)
    print(tree1.show())
    tree1._stats.display_tree()
    print("asking the oak to produce shade")
    tree1.produce_shade()
    tree1._stats.display_tree()
    print("""
    === Seed""")
    sunflow = Seed("Sunflower", 80.0, 45, "yellow", 0)
    print(sunflow.show())
    print("Sunflower has not bloomed yet")
    print("[make sunflower grow, age and bloom]")
    sunflow.grow(30)
    sunflow.age(20)
    sunflow.sun_bloom()
    display_statistics(sunflow)
    print("""
    === Anonymous""")
    plant_unknown = Plant.anonymous_class()
    print(plant_unknown.show())
    display_statistics(plant_unknown)


if __name__ == "__main__":
    main()
