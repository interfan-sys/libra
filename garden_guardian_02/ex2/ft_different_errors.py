#!/usr/bin/env python3

def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        try:
            int("abc")
        except ValueError as e:
            print(f"Caught ValueError: {e}")
    elif operation_number == 1:
        try:
            (10 / 0)
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
    elif operation_number == 2:
        try:
            open("/non/extisten/file")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
    elif operation_number == 3:
        try:
            ("abc" + 3)
        except TypeError as e:
            print(f"Caught TypeError: {e}")
    else:
        print("Operation completed successfully")
        return


def test_error_types():
    print("=== Garden Error Types Demo ===")
    print("Testing operation 0...")
    garden_operations(0)
    print("Testing operation 1...")
    garden_operations(1)
    print("Testing operation 2...")
    garden_operations(2)
    print("Testing operation 3...")
    garden_operations(3)
    print("Testing operation 4...")
    garden_operations(4)
    print("\nAll error types tested successfully!")


def main():
    test_error_types()


if __name__ == "__main__":
    main()
