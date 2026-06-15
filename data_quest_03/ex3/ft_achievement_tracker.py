#!/usr/bin/env python3


import random
from typing import List, Set

def achievements_names() -> List:
    my_list = ['Crafting Genius', 'World Savior', 'Untouchable',
                'Master Explorer', 'Collector Supreme',
                'Boss Slayer', 'Speed Runner', 'Survivor',
                'Unstoppable', 'First Steps', 'Hidden Path Finder',
                'Sharp Mind', 'Treasure Hunter'
                ]
    return my_list


def get_player_achievements() -> Set[str]:
    my_list = achievements_names()
    random_number = random.randint(1, len(my_list))
    my_set = set()
    for i in range(random_number):
        item = random.choice(my_list)
        my_set.add(item)
        my_list.remove(item)
    return my_set


def player(name : str) -> Set:
    random_set = get_player_achievements()
    print(f"Player {name}: {random_set}")
    return random_set


def main():
    player("Alice")
    player("Bob")
    player("Charlie")
    player("Dylan")


if __name__ == "__main__":
    main()