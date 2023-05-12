# used to find minimum cost spanning tree
# Start with an empty MST
# Find minimum cost edge
# then each time find a edge with minimum cost which is connected to the already included vertices
# greedy

from heapq import *
from collections import defaultdict
inf = 10**20
class Graph :
    def __init__(self) :
        self.adjl = defaultdict(list)

    def add_edge(self, x, y, w) :
        self.adjl[x].append((y, w))
        self.adjl[y].append((x, w))
    
    def primsMst(self) :
        src = 2
        key = defaultdict(lambda:inf)
        parent = {}
        inMst = set()
        minheap = []    # (weight, edge)
        heappush(minheap, (0, src)) # take any vertex which is in graph as src
        key[src] = 0
        while len(minheap) > 0:
            v = heappop(minheap)[1]
            if v in inMst :
                continue
            inMst.add(v)
            for x in self.adjl[v] :
                # if vertex is in inMst or key of the vertex is less than weight it means particular vertex already included
                # not checking for number of edges, just checking that all vertices are included and cycle can't be there as each vertex only once
                if x[0] not in inMst and x[1] < key[x[0]]:
                    key[x[0]] = x[1]
                    heappush(minheap, (x[1], x[0]))
                    parent[x[0]] = v
        for i in parent :
            print(parent[i], i) # edged present in mst
g = Graph()
g.add_edge(0, 1, 4)
g.add_edge(0, 7, 8)
g.add_edge(1, 2, 8)
g.add_edge(1, 7, 11)
g.add_edge(2, 3, 7)
g.add_edge(2, 8, 2)
g.add_edge(2, 5, 4)
g.add_edge(3, 4, 9)
g.add_edge(3, 5, 14)
g.add_edge(4, 5, 10)
g.add_edge(5, 6, 2)
g.add_edge(6, 7, 1)
g.add_edge(6, 8, 6)
g.add_edge(7, 8, 7)
g.primsMst()
print()
h = Graph()
h.add_edge(1, 6, 10)
h.add_edge(5, 6, 25)
h.add_edge(5, 7, 24)
h.add_edge(2, 7, 14)
h.add_edge(2, 1, 28)
h.add_edge(2, 3, 16)
h.add_edge(4, 3, 12)
h.add_edge(5, 4, 22)
h.add_edge(7, 4, 18)
h.primsMst()