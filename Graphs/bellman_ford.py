# The graph may contain negative weight edges. 
# Dijkstra doesn’t work for Graphs with negative weights, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems.
# But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra. 
# In complete graph n(n - 1)//2 edges, Hence O(n^3)
# Shortest Path
# n vertices
# for n - 1 times do relaxation i.e., check for a edge (u, v) dist[u] + cost(u, v) < dist[v]
# no possible answer for negative cycle (sum of weights in cycle is negative), it keeps on reducing
from collections import defaultdict
inf = 10**20
class Graph :
    def __init__(self, veritices) :
        self.v = veritices
        self.graph = []

    def add_edge(self, x, y, w) :
        self.graph.append((x, y, w))

    def bellman_ford(self, src) :
        dist = defaultdict(lambda : inf)
        dist[src] = 0
        for _ in range(self.v - 1) :
            for x, y, w in self.graph :
                if dist[x] + w < dist[y] :
                    dist[y] = dist[x] + w
        for x, y, w in self.graph :
            if dist[x] + w < dist[y] :
                print("Negative cycle")
                return
        return dist
                
g = Graph(5)
g.add_edge(0, 1, -1)
g.add_edge(0, 2, 4)
g.add_edge(1, 2, 3)
g.add_edge(1, 3, 2)
g.add_edge(1, 4, 2)
g.add_edge(3, 2, 5)
g.add_edge(3, 1, 1)
g.add_edge(4, 3, -3)
print(g.bellman_ford(0))

# while detecting negative cycle, if disconnected then can create visited and run bellman ford for each unvisited node