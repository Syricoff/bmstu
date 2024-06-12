from math import sqrt

inp = []
with open("/home/syricoff/bmstu/Семестр2/Физика/лр1/inp.txt") as f:
    for line in f:
        inp.append(float(line.strip()))

# size = len(inp)
# sr = round(sum(inp) / size, 2)
# print(f"срзнач={sr}")
# sqrt_sum = []
# for i in inp:
#     print(f"i={i}  sr-i={sr-i:0.2f}  (sr-i)^2={(sr-i)**2:0.4f}")
#     sqrt_sum.append((sr-i)**2)


# print(f"dtS={sqrt((1/(size * (size-1))) * sum(sqrt_sum))}")

print(sum([1 for i in inp if 1.48 <= i < 1.52]))
print(sum([1 for i in inp if 1.52 <= i < 1.56]))
print(sum([1 for i in inp if 1.56 <= i < 1.60]))
print(sum([1 for i in inp if 1.60 <= i < 1.64]))
print(sum([1 for i in inp if 1.64 <= i < 1.68]))
print(sum([1 for i in inp if 1.68 <= i < 1.72]))
print(sum([1 for i in inp if 1.72 <= i < 1.76]))
print(sum([1 for i in inp if 1.76 <= i < 1.80]))
print(sum([1 for i in inp if 1.80 <= i < 1.84]))

import matplotlib.pyplot as plt
import numpy as np

# Создаем массив вещественных чисел для примера
data = inp.copy()

# Задаем шаги по осям x и y
bin_width = 0.04
y_step = 2

# Фильтруем значения меньше 148
filtered_data = [x for x in data if x >= 1.48]

# Рассчитываем количество значений с учетом заданного шага
y_values = [len([x for x in filtered_data if x >= val and x < val + bin_width]) for val in np.arange(1.48, max(filtered_data), bin_width)]

# Создаем массив значений по оси x для гистограммы
x_values = np.arange(1.48, max(filtered_data), bin_width)

# Строим гистограмму
plt.bar(x_values, y_values, width=bin_width)
plt.xticks(np.arange(1.48, max(filtered_data) + bin_width, bin_width))
plt.yticks(np.arange(0, max(y_values) + y_step, y_step))
plt.xlabel('Значения')
plt.ylabel('Количество значений с шагом 0.04 (значения >= 1.48)')
plt.show()




