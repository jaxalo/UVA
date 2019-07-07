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

    t = int(input())
    for _ in range(t):
        deg = list(map(int, input().split()))[1::]
        d = int(input())
        k = int(input())

        pos = 1
        n = 1
        while pos < k:
            pos += n * d
            if pos > k:
                break
            n += 1

        res = 0
        for i in range(len(deg)):
            res += (n ** i) * deg[i]

        print(res)

