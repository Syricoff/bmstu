# Лабораторная работа №1 "Представление, измерение и преобразование информации"
# Вариант 21


# Задание 1
with open('res/input_№1.txt') as inp:
    for num in map(int, inp.readline().split()):
        print(f"10CC: {num}, 2CC: {bin(num)[2:]}, 16CC: {hex(num)[2:]}")

# Задание 2
with open('res/input_№2.txt') as inp:
    for num in map(str.strip, inp.readlines()):
        print(f"\n2CC: {num}"
              f"\n10CC: {int(num, 2)}"
              f"\n16CC: {hex(int(num, 2))[2:]}")
