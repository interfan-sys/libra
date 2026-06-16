#!/usr/bin/env python3


import random
from typing import List, Set


def achievements_names() -> List:
    my_list = [
                'Crafting Genius', 'World Savior', 'Untouchable',
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


def player(name: str) -> Set:
    random_set = get_player_achievements()
    print(f"Player {name}: {random_set}")
    return random_set


def main():
    print("=== Achievement Tracker System ===")
    print()
    set_alice = player("Alice")
    set_bob = player("Bob")
    set_charlie = player("Charlie")
    set_dylan = player("Dylan")
    print()
    print(
        f"All distinct achievements: "
        f"{set_alice.union(set_bob, set_charlie, set_dylan)}"
        )
    print()
    print(
        f"Common ahievements: "
        f"{set_alice.intersection(set_bob, set_charlie, set_dylan)}"
        )
    print()
    print(
        f"Only Alice has: "
        f"{set_alice.difference(set_bob, set_charlie, set_dylan)}"
        )
    print(
        f"Only Bob has: "
        f"{set_bob.difference(set_alice, set_charlie, set_dylan)}"
        )
    print(
        f"Only Charlie has: "
        f"{set_charlie.difference(set_bob, set_alice, set_dylan)}"
        )
    print(
        f"Only Dylan has: "
        f"{set_dylan.difference(set_bob, set_charlie, set_alice)}\n"
        )
    converted_set = set(achievements_names())
    print()
    print(f"Alice is missing : {converted_set.difference(set_alice)}")
    print(f"Bob is missing : {converted_set.difference(set_alice)}")
    print(f"Charlie is missing : {converted_set.difference(set_alice)}")
    print(f"Dylan is missing : {converted_set.difference(set_alice)}")


if __name__ == "__main__":
    main()
