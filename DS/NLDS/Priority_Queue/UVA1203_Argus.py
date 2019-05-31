import sys
import heapq


def rl():
    return sys.stdin.readline().rstrip('\n')


def rn():
    return list(map(int, sys.stdin.readline().split()))


if __name__ == '__main__':
    argus = []
    periods = {}
    for line in sys.stdin:
        line = line.strip()
        if line == '#':
            break
        line = line.split()
        ide, per = map(int, line[1::])
        argus.append((per, ide))
        periods[ide] = per
    heapq.heapify(argus)
    n = int(input())
    for _ in range(n):
        per, ide = heapq.heappop(argus)
        print(ide)
        heapq.heappush(argus, (per + periods[ide], ide))
        heapq.heapify(argus)

