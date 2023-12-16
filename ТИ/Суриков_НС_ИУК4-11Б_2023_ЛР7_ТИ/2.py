from itertools import product

print('A B | F')
for A, B in product((0, 1), repeat=2):
    print(A, B, '|', int(not (not (A) and not (B))))

