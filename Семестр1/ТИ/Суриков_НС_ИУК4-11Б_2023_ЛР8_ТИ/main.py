import numpy as np
import matplotlib.pyplot as plt

num_steps = 10  # Количество шагов моделирования
num_particles = 50  # Количество частиц газа каждого вида
diffusion_coefficient_gas1 = 0.1  # Коэффициент диффузии для первого газа
diffusion_coefficient_gas2 = 0.3  # Коэффициент диффузии для второго газа

positions_gas1 = np.ones(num_particles) * 0.5
positions_gas2 = np.ones(num_particles) * 0.5

# Моделирование процесса диффузии для каждого газа на каждом шаге
all_positions_gas1 = []
all_positions_gas2 = []
for step in range(num_steps):
    displacements_gas1 = np.random.normal(
        scale=np.sqrt(2 * diffusion_coefficient_gas1), size=num_particles
    )
    positions_gas1 += displacements_gas1
    positions_gas1 = np.maximum(-5, np.minimum(5, positions_gas1))
    all_positions_gas1.append(positions_gas1.copy())

    displacements_gas2 = np.random.normal(
        scale=np.sqrt(2 * diffusion_coefficient_gas2), size=num_particles
    )
    positions_gas2 += displacements_gas2
    positions_gas2 = np.maximum(-5, np.minimum(5, positions_gas2))
    all_positions_gas2.append(positions_gas2.copy())

all_positions_gas1 = np.array(all_positions_gas1)
all_positions_gas2 = np.array(all_positions_gas2)

# Визуализация результатов для каждого газа на отдельном графике
plt.figure(figsize=(10, 5))

plt.subplot(1, 2, 1)
plt.hist(all_positions_gas1.flatten(), bins=30, density=True, color="blue", alpha=0.7)
plt.xlabel("Положение")
plt.ylabel("Плотность вероятности")
plt.title("Распределение частиц газа 1")

plt.subplot(1, 2, 2)
plt.hist(all_positions_gas2.flatten(), bins=30, density=True, color="red", alpha=0.7)
plt.xlabel("Положение")
plt.ylabel("Плотность вероятности")
plt.title("Распределение частиц газа 2")

plt.show()
