from itertools import product

print('X | F')
for X, in product((0, 1), repeat=1):
    print(X, '|', int(not (X and X)))


def F1(x1, x2):
    return int(not ((not (x1 and x2)) and (not (x1 and x2))))


print('X1 X2 | F')
for X1, X2 in product((0, 1), repeat=2):
    print(X1, X2, '|', F1(X1, X2))


def F2(x1, x2):
    return int(not ((not (x1 and x1)) and (not (x2 and x2))))


print('X1 X2 | F')
for X1, X2 in product((0, 1), repeat=2):
    print(f"{X1}  {X2}  | {F2(X1, X2)}")


def F3(x1, x2):
    return int(not ((F2(x1, x2) and F2(x1, x2))))


print('X1 X2 | F')
for X1, X2 in product((0, 1), repeat=2):
    print(f"{X1}  {X2}  | {F3(X1, X2)}")
