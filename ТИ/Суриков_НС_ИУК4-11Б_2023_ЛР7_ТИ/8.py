from itertools import product


def S(a, b):
    return int(((not (a) and b) or (a and not (b))))


def C0(a, b):
    return int(a and b)


def oSum(a, b, c):
    s1 = S(a, b)
    c0 = C0(a, b)
    s2 = S(s1, c)
    c1 = C0(s1, c)
    return s2, (c0 or c1)


def pSum(a, b):
    return S(a, b), C0(a, b)


print("A1 B1 A2 B2 A3 B3 | S1 | S2 | S3 | S4")
for A1, B1, A2, B2, A3, B3 in product((0, 1), repeat=6):
    s1, c0 = pSum(A1, B1)
    s2, c1 = oSum(c0, A2, B2)
    s3, s4 = oSum(c1, A3, B3)
    print(
        f"{A1}  {B1}  {A2}  {B2}  {A3}  {B3} \
          |  {s1} |  {s2} |  {s3} |  {s4}"
    )
