#!/usr/bin/env python3


from typing import Generator, Tuple
import random


def get_event() -> Generator[Tuple[str, str], None, None]:
    while True:
        players_list = ["alice", "bob", "charlie", "dylan"]
        action_list = [
            "eat", "sleep", "grab", "climb", "move",
            "use", "swim", "run", "release"
            ]
        player = random.choice(players_list)
        action = random.choice(action_list)
        yield player 
        yield action