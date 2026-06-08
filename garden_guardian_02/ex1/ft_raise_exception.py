#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)
    if temp < 0:
        raise ValueError(f"{temp}°C is too cold for plants (min 0°C)")
    if temp > 40:
        raise ValueError(f"{temp}°C is too hot for plants (max 40°C)")
    return temp


def test_temperature():
    print("Input data is '25'")
    try:
        test_temp = input_temperature("25")
        print(f"Temperature is now {test_temp}°C\n")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

    print("Input data is 'abc'")
    try:
        test_temp = input_temperature("abc")
        print(f"Temperature is now {test_temp}")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")

    print("Input data is '-50'")
    try:
        test_temp = input_temperature("-50")
        print(f"Temperature is now {test_temp}°C\n")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")

    print("Input data is '100'")
    try:
        test_temp = input_temperature("100")
        print(f"Temperature is now {test_temp}°C\n")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")

    print("All tests completed - program didn't crash!")


def main():
    print("=== Garden Temperature Checker ===\n")
    test_temperature()


if __name__ == "__main__":
    main()
