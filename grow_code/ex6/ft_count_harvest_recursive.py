def recursive(n):
    i = 1
    while i <= n:
        print(f"Day {i}")
        i += 1


def ft_count_harvest_recursive():
    days_to_harvest = int(input("Days until harvest: "))
    recursive(days_to_harvest)
    print("Harvest time!")
