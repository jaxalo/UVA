import sys
from collections import defaultdict


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


def solve(line_in):
    n, q = map(int, line_in.strip().split())
    tab = rn()
    occ = {}
    rep_query = {}
    for i in range(len(tab)):
        e = tab[i]
        if e in occ:
            occ[e] += 1
        else:
            occ[e] = 1
        rep_query[(occ[e], e)] = i + 1

    for _ in range(q):
        k, v = rn()
        if (k, v) not in rep_query:
            print(0)
        else:
            print(rep_query[(k, v)])


if __name__ == '__main__':
    for line in sys.stdin:
        solve(line)
