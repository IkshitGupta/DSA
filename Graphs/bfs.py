# pehle apne saare children, put in queue, phir unke sare children
# implemented using queues
# O(V + E)
from collections import defaultdict, deque
inf = 10**25
class Graph :
    def __init__(self) :
        self.adjl = defaultdict(list)
        self.cycle = set()  # for undirected

    def add_edge(self, x, y) :
        self.adjl[x].append(y)
        self.adjl[y].append(x)

    def bfs(self, n) : # n = node from where travelsal will start
        # here it is not checking different components
        visited = set()
        queue = deque()
        parent = {}
        ans = []    # contains traversal
        distance = defaultdict(lambda : inf)    # shortest distance from source
        queue.append(n)
        visited.add(n)
        distance[n] = 0
        parent[n] = n
        while len(queue) > 0:
            front = queue.popleft()
            ans.append(front)
            for i in self.adjl[front] :
                if i not in visited: 
                    # if distance needed than rather than checking visited can just check if distance is inf
                    queue.append(i)
                    visited.add(i)
                    distance[i] = distance[front] + 1
                    parent[i] = front
                elif parent[front] != i :
                    self.cycle.add(tuple(sorted([front, i])))
        return distance

h = Graph()
edges = ['AB', 'AE', 'BF', 'CG', 'DE', 'DH', 'EH', 'FG', 'FI', 'FJ', 'GJ', 'HI']
for i in edges :
    h.add_edge(i[0], i[1])
# print(h.bfs('A'))

g = Graph()
g.add_edge(0, 1)
g.add_edge(2, 1)
g.add_edge(0, 4)
g.add_edge(4, 3)
g.add_edge(4, 2)
g.add_edge(5, 3)
g.add_edge(3, 2)
print(g.bfs(1))
print(g.cycle)