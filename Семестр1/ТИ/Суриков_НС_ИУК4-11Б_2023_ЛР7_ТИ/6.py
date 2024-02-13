from itertools import product


def S(a, b):
    return int(((not (a) and b) or (a and not (b))))


def C(a, b):
    return int(a and b)


print("A B | C | S")
for A, B in product((0, 1), repeat=2):
    print(f"{A} {B} | {C(A, B)} | {S(A, B)}")
