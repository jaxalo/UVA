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


def letter_maj_to_int(letter):
    return ord(letter) - ord('A')


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


def solve():
    contiguous = {}
    edges = []
    actual = 0

    #edges
    for line in sys.stdin:
        if line[0] == '*':
            break
        line = line.strip().replace('(', '').replace(')', '').split(',')
        if line[0] in contiguous:
            p = contiguous[line[0]]
        else:
            p = actual
            contiguous[line[0]] = p
            actual += 1

        if line[1] in contiguous:
            q = contiguous[line[1]]
        else:
            q = actual
            contiguous[line[1]] = q
            actual += 1
        edges.append((p, q))

    #vertex
    line = sys.stdin.readline().strip().split(',')
    uf = UnionFind(len(line))
    for (p, q) in edges:
        uf.union(p, q)

    #ans
    acorn,tree = 0,0
    for i in range(len(line)):
        if i == uf.root(i) and uf.get_size()[i] == 1:
            acorn += 1
        elif i == uf.root(i) and uf.get_size()[i] > 1:
            tree += 1
    print('There are {} tree(s) and {} acorn(s).'.format(tree,acorn))


if __name__ == '__main__':
    test = int(sys.stdin.readline())
    for _ in range(test):
        solve()
