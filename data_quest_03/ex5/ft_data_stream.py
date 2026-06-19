#!/usr/bin/env python3


from typing import Generator, Tuple, List
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
        yield player, action


def consume_event(events: List[Tuple[str, str]]
                  ) -> Generator[Tuple[str, str], None, None]:
    for i in range(10):
        random_index = random.randint(0, len(events) - 1)
        item = events[random_index]
        del events[random_index]
        yield item


def main():
    event = get_event()
    i = 0
    while i < 1000:
        player, action = next(event)
        print(f"Event {i}: Player {player} did action {action}")
        i += 1
    my_list_10 = []
    for x in range(10):
        my_list_10.append(next(event))
    print(my_list_10)
    event_list = consume_event(my_list_10)
    for item in event_list:
        print(f"Got event from list: {item}")
        print(f"Remains in the list: {my_list_10}")


if __name__ == "__main__":
    main()
