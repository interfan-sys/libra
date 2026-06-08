#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature():
    print("Input data is '25'")
    try:
        temp = input_temperature("25")
        print(f"Temperature is now {temp}°C\n")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

    print("Input data is 'abc'")
    try:
        temp = input_temperature("abc")
        print(f"Temperature is now {temp}")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")

    print("All tests completed - program didn't crash!")


def main():
    print("=== Garden Temperature ===\n")
    test_temperature()


if __name__ == "__main__":
    main()
