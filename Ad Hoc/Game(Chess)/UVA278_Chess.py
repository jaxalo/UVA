import sys


def rl():
    return sys.stdin.readline().rstrip('\n')


def rn():
    return list(map(int, sys.stdin.readline().split()))


if __name__ == '__main__':
    test = int(input())
    for _ in range(test):
        piece, m, n = rl().split()
        m, n = int(m), int(n)
        if piece == 'r' or piece == 'Q':
            print(min(m, n))
        elif piece == 'k':
            print((m * n) // 2)
        elif piece == 'K':
            print(((m + 1) // 2) * ((n + 1) // 2))

