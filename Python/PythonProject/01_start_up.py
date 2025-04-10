from typing import List

def print_arr(arr: List[int]):
    for i in arr:
        print(i)

def main():
    arr = [0] * 10
    for i in range(5):
        arr[i] = i

    print_arr(arr)

if __name__ == "__main__":
    main()
