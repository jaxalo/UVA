import sys
from collections import defaultdict

cur = 0

def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


class UnionFind:
    """Weighted quick-union with path compression.
        The original Java implementation is introduced at
        https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
        >>> uf = UnionFind(10)
        >>> for (p, q) in [(3, 4), (4, 9), (8, 0), (2, 3), (5, 6), (5, 9),
        ...                (7, 3), (4, 8), (6, 1)]:
        ...     uf.union(p, q)
        >>> uf._id
        [8, 3, 3, 3, 3, 3, 3, 3, 3, 3]
        >>> uf.find(0, 1)
        True
        >>> uf._id
        [3, 3, 3, 3, 3, 3, 3, 3, 3, 3]
        """

    def __init__(self, n):
        self._id = list(range(n))
        self._sz = [1] * n

    def root(self, i):
        j = i
        while j != self._id[j]:
            self._id[j] = self._id[self._id[j]]
            j = self._id[j]
        return j

    def find(self, p, q):
        return self.root(p) == self.root(q)

    def union(self, p, q):
        i = self.root(p)
        j = self.root(q)
        if i == j:
            return
        if self._sz[i] < self._sz[j]:
            self._id[i] = j
            self._sz[j] += self._sz[i]
        else:
            self._id[j] = i
            self._sz[i] += self._sz[j]

    def get_size(self):
        return self._sz

    def get_id(self):
        return self._id

    def __str__(self):
        res = ' | '.join(map(str, range(len(self._id))))
        res += '\n'
        res += ' | '.join(map(str, self._id))
        res += '\n'
        res += ' | '.join(map(str, self._sz))
        return res


def solve(line_in, test):
    global cur
    nbComputer = int(line_in)
    succ, nosucc = 0, 0
    uf = UnionFind(nbComputer)
    for line in sys.stdin:
        line = line.strip()
        if not line:
            break
        q, a, b = line.strip().split()
        a, b = int(a)-1, int(b)-1
        if q == 'c':
            uf.union(a, b)
        elif q == 'q':
            if uf.find(a, b):
                succ += 1
            else:
                nosucc += 1
    print('{},{}'.format(succ, nosucc))
    cur += 1
    if test != cur:
        print()


if __name__ == '__main__':
    test = int(rl())
    rl()
    for line in sys.stdin:
        solve(line, test)

