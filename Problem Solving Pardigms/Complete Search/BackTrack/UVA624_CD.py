#!/bin/python3

import sys

max_sum = 0
max_comb = []


def solve_help(cur, sum, N, n, tab, chosen):
    global max_sum, max_comb

    if cur == n:
        if max_sum < sum <= N:
            max_sum = sum
            max_comb = chosen.copy()
    else:
        chosen.append(tab[cur])
        solve_help(cur + 1, sum + tab[cur], N, n, tab, chosen)
        chosen.pop()
        solve_help(cur + 1, sum, N, n, tab, chosen)


def solve(N, n, tab):
    global max_sum, max_comb

    max_sum = 0
    max_comb = []
    solve_help(0, 0, N, n, tab, [])
    print(' '.join(map(str,max_comb)) + ' sum:' + str(max_sum))


if __name__ == '__main__':

    out = sys.stdout
    sys.stdout = open('output.txt', 'w')

    for line in sys.stdin:
        line = line.split()
        N = int(line[0])
        n = int(line[1])
        tab = list(map(int, line[2::]))
        solve(N, n, tab)

