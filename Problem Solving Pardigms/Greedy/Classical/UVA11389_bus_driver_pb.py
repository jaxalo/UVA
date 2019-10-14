import sys


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


if __name__ == '__main__':
    for line in sys.stdin:
        a, b, c = map(int, line.split())
        if a == b == c == 0:
            break
        morning = rn()
        after = rn()
        morning.sort()
        after.sort(reverse=True)
        p = 0
        for i in range(a):
            p += max((after[i] + morning[i]) - b, 0)
        print(p * c)
