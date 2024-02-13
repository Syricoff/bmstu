from itertools import product

print('A B C | F')
for A, B, C in product((0, 1), repeat=3):
    print(A, B, C, '|', int(A and B or not C))
