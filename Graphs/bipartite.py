# pehle apne saare children, put in queue, phir unke sare children
# implemented using queues
# O(V + E)
from collections import defaultdict, deque
class Graph :
    def __init__(self) :
        self.adjl = defaultdict(list)

    def add_edge(self, x, y) :
        self.adjl[x].append(y)
        self.adjl[y].append(x)

    def isBipartite(self) :
        color = defaultdict(lambda : -1)
        queue = deque()
        for i in self.adjl :
            if color[i] != -1 :
                continue
            queue.append(i)
            color[i] = 0
            while len(queue) > 0:
                front = queue.popleft()
                for j in self.adjl[front] :
                    if color[j] == -1 :
                        color[j] = color[front]^1
                        queue.append(j)
                    elif color[j] == color[front] :
                        return 0
        return 1

g = Graph()
# g.add_edge(1, 3)
# g.add_edge(0, 2)
# g.add_edge(1, 3)
# g.add_edge(0, 2)
x = [
  [8, 7],
  [8, 6],
  [8, 2],
  [4, 9],
  [11, 10],
  [5, 10],
  [1, 10],
  [3, 7],
  [3, 6],
  [11, 7],
  [5, 7],
  [1, 6],
  [3, 2],
  [8, 9],
  [4, 10],
  [5, 6],
  [4, 7],
  [4, 6],
]
for i in x :
    g.add_edge(i[0], i[1])
print(g.isBipartite())