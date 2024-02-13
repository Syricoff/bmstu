from itertools import product


def F1(x1, x2, x3, x4):
    return int(not (x1 and x2 and x3 and x4))


def F2(x1, x2, x3, x4):
    return int(
        not (
            (not (((not (x1 and x2)) and (not (x1 and x2)))))
            and (not (((not (x3 and x4)) and (not (x3 and x4)))))
        )
    )


print("X1 X2 X3 X4 | F1 | F2")
for X1, X2, X3, X4 in product((0, 1), repeat=4):
    print(
        f"{X1}  {X2}  {X3}  {X4}  \
          | {F1(X1, X2, X3, X4)}  \
          | {F2(X1, X2, X3, X4)}"
    )
