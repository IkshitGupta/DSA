# Weighted Graoh
# Shortest Path
# O(ELogV) 
from collections import defaultdict, deque # (required for path)
from heapq import *
inf = 10**20
class Graph :
    def __init__(self) :
        self.adjl = defaultdict(list)

    def add_edge(self, x, y, w) :
        self.adjl[x].append((y, w))
        # self.adjl[y].append((x, w))

    def dijkstra(self, src) :
        distance = defaultdict(lambda : inf)
        parent = {}
        visited = set()
        distance[src] = 0
        parent[src] = src
        heap = []  # min heap, as we need the next minimum always and then when its done pop and get next minimum
        heappush(heap, (0, src))
        while len(heap) > 0:
            first = heappop(heap)
            dist = first[0]
            node = first[1]
            if node in visited: # if some node's visited, it means that shortest path to reach that node already found
                continue
            visited.add(node)
            # Iterating neighbours of first
            for i in self.adjl[node] :
                if i[0] in visited:
                    continue
                new = dist + i[1]
                if new < distance[i[0]] :
                    distance[i[0]] = new
                    heappush(heap, (new, i[0]))
                    parent[i[0]] = node
        return distance
        return parent # if need path, then we can return parent
    
    def path(self, a, b) :
        parent = self.dijkstra(a)
        path = deque()
        path.append(b)
        while parent[b] != b :
            b = parent[b]
            path.appendleft(b)
        return path

g = Graph()
# g.add_edge("Amritsar", "Jaipur", 4)
# g.add_edge("Delhi", "Jaipur", 2)
# g.add_edge("Mumbai", "Jaipur", 8)
# g.add_edge("Mumbai", "Bhopal", 3)
# g.add_edge("Delhi", "Agra", 1)
# g.add_edge("Agra", "Bhopal", 2)
# g.add_edge("Amritsar", "Delhi", 1)
# print(dict(g.dijkstra("Amritsar")))
# print(g.path("Amritsar", "Jaipur"))

g = Graph()
# g.add_edge(1, 2, 1)
# g.add_edge(1, 3, 4)
# g.add_edge(2, 3, 1)
# g.add_edge(3, 4, 2)
# g.add_edge(1, 4, 7)
# print(g.dijkstra(1))

g.add_edge(1, 2, 4)
g.add_edge(1, 3, 3)
g.add_edge(1, 1, 0)
g.add_edge(1, 5, 8)
g.add_edge(2, 1, 3)
g.add_edge(2, 2, 0)
g.add_edge(2, 3, 2)
g.add_edge(2, 4, 2)
g.add_edge(2, 5, 6)
g.add_edge(3, 1, 2)
g.add_edge(3, 3, 0)
g.add_edge(3, 5, 2)
g.add_edge(4, 2, 2)
g.add_edge(4, 4, 0)
g.add_edge(4, 5, 1)
g.add_edge(5, 1, 7)
g.add_edge(5, 2, 2)
g.add_edge(5, 3, 5)
g.add_edge(5, 4, 3)
g.add_edge(5, 5, 0)
# print(g.dijkstra(1))
# print(g.path(1, 2))

# Not working as negative edges
# g.add_edge(0, 1, -1)
# g.add_edge(0, 2, 4)
# g.add_edge(1, 2, 3)
# g.add_edge(1, 3, 2)
# g.add_edge(1, 4, 2)
# g.add_edge(3, 2, 5)
# g.add_edge(3, 1, 1)
# g.add_edge(4, 3, -3)
# print(g.dijkstra(0))