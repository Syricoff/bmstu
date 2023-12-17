def fibonacci_generator(m, x, n):
    for i in range(len(x) - 1, n):
        next_value = (x[i] + x[i - 1]) % m
        x.append(next_value)
    return x


def middle_square_generator(seed, n):
    random_numbers = []
    k = int(len(str(seed)))
    for _ in range(n):
        square = seed * seed
        seed_str = str(square).zfill(2 * k)
        middle = seed_str[k // 2: -k // 2]
        seed = int(middle)
        random_numbers.append(seed / 10**k)
    return random_numbers


def main():
    while True:
        print("Выберите метод генерации псевдослучайных чисел:")
        print("1. Аддитивный генератор Фибоначчи")
        print("2. Метод середины квадрата")
        print("0. Выход из программы")

        choice = int(input("Введите ваш выбор: "))

        match choice:
            case 0:
                print("Выход из программы")
                return
            case 1:
                m = int(input("Введите m (четное число): "))
                initial_values = [
                    int(x)
                    for x in input(
                        "Введите начальные значения, разделенные пробелами: "
                    ).split()
                ]
                n = int(input("Введите количество генерируемых случайных чисел: "))
                print(fibonacci_generator(m, initial_values, n))
            case 2:
                seed = int(input("Введите начальное значение: "))
                n = int(input("Введите количество генерируемых случайных чисел: "))
                print(middle_square_generator(seed, n))
            case _:
                print("Неверный выбор")


if __name__ == "__main__":
    main()
