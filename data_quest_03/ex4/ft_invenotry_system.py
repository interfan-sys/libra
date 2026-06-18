#!/usr/bin/env python3


import sys
from typing import List
from typing import Dict


def build_inventory() -> Dict[str, int]:
    inventory: Dict[str, int] = {}
    for args in sys.argv[1:]:
        if ":" not in args:
            print(f"Error - invalid parameter: '{args}'")
            continue
        parts = args.split(":")
        item_name = parts[0]
        quantity = parts[1]
        if item_name in inventory:
            print(f"Redundant item '{item_name}' - discarding")
            continue
        try:
            quantity_int = int(quantity)
        except ValueError as e:
            print(f"Quantity error for '{item_name}': {e}")
            continue
        inventory[item_name] = quantity_int
    return inventory


def main():
    inventory = build_inventory()
    my_list: List[str] = list(inventory.keys())
    print("Got inventory: ", inventory)
    print("Item list: ", my_list)
    total = sum(inventory.values())
    print(f"Total quantity of {len(inventory.values())} items: {total}")
    for item in inventory:
        value = inventory[item]
        print(
            f"Item {item} represents "
            f"{(value / total):.1%}"
            )
    max_value = None
    abundant_item = None
    for item in inventory:
        value = inventory[item]
        if max_value is None or value > max_value:
            max_value = value
            abundant_item = item
    print(f"Most abundant item: {abundant_item} with quantity {max_value}")
    min_value = None
    min_item = None
    for item in inventory:
        value = inventory[item]
        if min_value is None or value < min_value:
            min_value = value
            min_item = item
    print(f"Item least abundant: {min_item} with quantity {min_value}")
    inventory.update({"magic_item": 1})
    print(f"Updated inventory : {inventory}")


if __name__ == "__main__":
    main()
