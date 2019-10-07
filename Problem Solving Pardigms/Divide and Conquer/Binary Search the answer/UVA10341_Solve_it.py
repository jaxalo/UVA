import sys
from math import *


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


def continuous_binary_search(f, lo, hi, gap=1e-5):
    while hi - lo > gap:
        mid = (lo + hi) / 2.0
        if f(mid) < 0:
            hi = mid
        else:
            lo = mid
    return lo


def func(x):
    global p, q, r, s, t, u
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u


def closest(val):
    center = abs(func(val))
    center_ex = abs(func(val + 0.0001))
    center_def = abs(func(val - 0.0001))
    if center < min(center_def, center_ex):
        return val
    elif center_ex < min(center, center_def):
        return val + 0.0001
    elif center_def < min(center, center_def):
        return val - 0.0001
    else:
        return val


if __name__ == '__main__':
    for line in sys.stdin:
        p, q, r, s, t, u = map(int, line.split())
        if p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u > 1e-9 or p + r + u < 0:
            print('No solution')
            continue

        lo = 0.0
        hi = 1.0
        res = continuous_binary_search(func, lo, hi)
        res = closest(round(res, 4))
        if abs(func(res)) <= 10 ** -2:
            print('{:.4f}'.format(res))
        else:
            print('No solution')
