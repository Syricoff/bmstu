def is_simple_num(num):
    for i in range(2, (num // 2) + 1):
        if num % i == 0:
            return f"{num} составное число"
    return f"{num} простое число"


def main():
    x = int(input())
    print(is_simple_num(x))


if __name__ == "__main__":
    main()
