import sys
from collections import defaultdict


class Graph:

    def __init__(self, nbVertex):
        self.graph = defaultdict(list)
        self.nbVertex = nbVertex

    def addEdge(self, src, dest):
        self.graph[src].append(dest)
        self.graph[dest].append(src)


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


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


def connected(graphi, u, pwaked):
    neighbors = graphi[u]
    counting = 0
    for elem in neighbors:
        if elem in pwaked:
            counting += 1
    return counting >= 3


def solve(line):
    nb_vertex = int(line)
    nb_vertices = int(rl())
    waked = rl()
    unwaked = []

    graph = Graph(nb_vertex)
    uf = UnionFind(26)

    for _ in range(nb_vertices):
        temp = rl()
        p = ord(temp[0]) - ord('A')
        q = ord(temp[1]) - ord('A')
        graph.addEdge(p, q)
        uf.union(p, q)

    exist = sum([1 if e > 1 else 0 for e in uf.get_size()]) >= 1
    if nb_vertex <= 3:
        print('WAKE UP IN, 0, YEARS')
    elif not exist:
        print('THIS BRAIN NEVER WAKES UP')
    else:
        toWake = []
        waked = list(map(lambda x: ord(x) - ord('A'), waked))
        for e in graph.graph.keys():
            if e not in waked:
                toWake.append(e)
        solved = False
        count = 0
        while toWake:
            to_delete = []
            for u in toWake:
                if connected(graph.graph, u, waked):
                    to_delete.append(u)
            if not to_delete:
                print('THIS BRAIN NEVER WAKES UP')
                solved = True
                break
            else:
                waked += to_delete
                for e in to_delete:
                    toWake.remove(e)
            count += 1
        if not solved:
            print('WAKE UP IN, {}, YEARS'.format(count))


if __name__ == '__main__':
    for line in sys.stdin:
        solve(line)
        rl()


