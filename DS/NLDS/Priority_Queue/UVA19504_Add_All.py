import sys
import heapq


def rl():
    return sys.stdin.readline().rstrip('\n')


def rn():
    return list(map(int, sys.stdin.readline().split()))


if __name__ == '__main__':
    for line in sys.stdin:
        line = line.strip()
        n = int(line)
        if n == 0:
            break
        tab = rn()
        heapq.heapify(tab)
        c = 0
        while len(tab) != 1:
            a = heapq.heappop(tab)
            b = heapq.heappop(tab)
            c += a + b
            heapq.heappush(tab, a + b)
        print(c)


