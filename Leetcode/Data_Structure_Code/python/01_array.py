from typing import List

def print_arr(arr: List[int]):
    for i in arr:
        print(i, end=", ")

def print_two_d_arr(arr_arr: List[List[int]]):
    for row in arr_arr:
        print(", ".join(str(col) for col in row))
        print()


def main():
    arr = [0] * 10
    for i in range(5):
        arr[i] = i

    print_arr(arr)

    arr_arr = [[i] * 10 for i in range(10)]

    print_two_d_arr(arr_arr)


if __name__ == "__main__":
    main()
