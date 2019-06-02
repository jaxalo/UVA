import sys
from collections import defaultdict


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


class Graph:

    def __init__(self, nbVertex):
        self.graph = defaultdict(list)
        self.nbVertex = nbVertex

    def addEdge(self, src, dest):
        self.graph[src].append(dest)

    def DFS(self, src):

        parent = [-1] * self.nbVertex
        visited = [False] * self.nbVertex
        toVisit = [i for i in range(self.nbVertex) if i != src] + [src]
        visited[src] = True
        entered = False
        v = -1

        while (toVisit):
            u = toVisit.pop()
            for dest in self.graph[u]:
                if (visited[dest] == False):
                    entered = True
                    v = dest
                    visited[dest] = True
                    print(dest)
                    parent[v] = u
                    break
            if (entered):
                toVisit.append(v)
            entered = False

        print('parent')
        for i in range(self.nbVertex):
            print(i, ':', parent[i])


def solve(line):
    n, m = map(int, line.strip().split())
    graph = Graph(n)

    # build graph
    for i in range(n):
        nzs = list(map(int, rl().split()[1::]))
        elems = rn()
        if elems:
            for j in range(len(elems)):
                graph.addEdge(i + 1, (elems[j], nzs[j]))
        else:
            graph.addEdge(i + 1, (None, 0))

    # build rev_graph
    rev_graph = Graph(m)
    for src, dests in graph.graph.items():
        for dest in dests:
            if dest:
                rev_graph.addEdge(dest[1], (dest[0], src))

    # ans
    print(m, n)
    for i in range(1, m + 1):
        if rev_graph.graph[i]:
            dests = rev_graph.graph[i]
            r = [len(dests)] + [dest[1] for dest in dests]
            print(' '.join(map(str, r)))
            r = [dest[0] for dest in dests]
            print(' '.join(map(str, r)))
        else:
            print(0)
            print()


if __name__ == '__main__':
    for line in sys.stdin:
        solve(line)
