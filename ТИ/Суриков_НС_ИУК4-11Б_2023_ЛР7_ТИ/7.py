from itertools import product


def S(a, b):
    return int(((not (a) and b) or (a and not (b))))


def C0(a, b):
    return int(a and b)


def F(a, b, c):
    s1 = S(a, b)
    c0 = C0(a, b)
    s2 = S(s1, c)
    c1 = C0(s1, c)
    return s2, (c0 or c1)


print("A B C | C0 | S")
for A, B, C in product((0, 1), repeat=3):
    print(f"{A} {B} {C} |  {F(A, B, C)[1]} | {F(A, B, C)[0]}")
