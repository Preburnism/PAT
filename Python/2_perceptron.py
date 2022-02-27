import numpy as np
"""
def AND(x1, x2):
    w1, w2, theta = 0.5, 0.5, 0.7
    tmp = w1 * x1 + w2 * x2
    if tmp <= theta:
        return 0
    else:
        return 1
"""


# (0.5, 0.5, 0.7)
def AND(x1, x2):
    x = np.array([x1, x2])
    w = np.array([0.5, 0.5])
    b = -0.7
    tmp = np.sum(w * x) + b
    if tmp <= 0:
        return 0
    else:
        return 1


# (-0.5,-0.5,0.7)
def NAND(x1, x2):
    x = np.array([x1, x2])
    w = np.array([-0.5, -0.5])
    b = 0.7
    tmp = np.sum(w * x) + b
    if tmp <= 0:
        return 0
    else:
        return 1


# (0.5,0.5,-0.2)
def OR(x1, x2):
    x = np.array([x1, x2])
    w = np.array([0.5, 0.5])
    b = -0.2
    tmp = np.sum(w * x) + b
    if tmp <= 0:
        return 0
    else:
        return 1


# multi-layered perceptron
def XOR(x1, x2):
    s1 = NAND(x1, x2)
    s2 = OR(x1, x2)
    y = AND(s1, s2)
    return y


print("感知机实现门电路：")
print("\t与门")
print("x1(0.5) x2(0.5)  y\t bias")
b = 0.7
print(0, "\t", 0, "\t", AND(0, 0), "\t", b)
print(0, "\t", 1, "\t", AND(0, 1), "\t", b)
print(1, "\t", 0, "\t", AND(1, 0), "\t", b)
print(1, "\t", 1, "\t", AND(1, 1), "\t", b)

print("\t与非门")
print("x1(-0.5) x2(-0.5)  y\t bias")
b = 0.7
print(0, "\t", 0, "\t", NAND(0, 0), "\t", b)
print(0, "\t", 1, "\t", NAND(0, 1), "\t", b)
print(1, "\t", 0, "\t", NAND(1, 0), "\t", b)
print(1, "\t", 1, "\t", NAND(1, 1), "\t", b)

print("\t或门")
print("x1(0.5) x2(0.5)  y\t bias")
b = -0.2
print(0, "\t", 0, "\t", OR(0, 0), "\t", b)
print(0, "\t", 1, "\t", OR(0, 1), "\t", b)
print(1, "\t", 0, "\t", OR(1, 0), "\t", b)
print(1, "\t", 1, "\t", OR(1, 1), "\t", b)

print("\t异或门\nAND(NAND(x1,x2), OR(x1,x2))")
print("x1  x2 | s1  s2 | y")
print(0, " ", 0, " |", NAND(0, 0), " ", OR(0, 0), " |", XOR(0, 0))
print(0, " ", 1, " |", NAND(0, 1), " ", OR(0, 1), " |", XOR(0, 1))
print(1, " ", 0, " |", NAND(1, 0), " ", OR(1, 0), " |", XOR(1, 0))
print(1, " ", 1, " |", NAND(1, 1), " ", OR(1, 1), " |", XOR(1, 1))
