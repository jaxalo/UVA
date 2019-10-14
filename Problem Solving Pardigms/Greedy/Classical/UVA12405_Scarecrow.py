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


def find_last(res, start):
    for i in range(start, len(res)):
        if res[i] == '#':
            return i - 1
    return len(res) - 1


if __name__ == '__main__':
    tc = int(input())
    for t in range(tc):
        n = int(input())
        res = input()
        i = 0
        nb_elem = 0
        twice = 0
        while i < n:
            if res[i] == '.':
                nb_elem += 1
                i += 2
            i += 1
        print('Case {}: {}'.format(t + 1, nb_elem))
