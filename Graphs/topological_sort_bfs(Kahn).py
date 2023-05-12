# if there is a edge from vertex u to vertex v, then vertex u comes before vertex v in ordering
# Work only in DAG
# O(V + E)
# Kahn's Algorithm

from collections import defaultdict, deque
inf = 10**15
class Graph :
    def __init__(self) :
        self.adjl = defaultdict(list)

    def add_edge(self, x, y) :
        self.adjl[x].append(y)

    def topological_bfs(self) :
        queue = deque()
        indegree = defaultdict(int)
        ans = []
        for i in self.adjl.values() :
            for j in i :
                indegree[j] += 1
        for i in self.adjl :
            if indegree[i] == 0:
                queue.append(i)
        while len(queue) > 0 :
            node = queue.popleft()
            ans.append(node)
            for i in self.adjl[node] :
                indegree[i] -= 1
                if indegree[i] == 0 :
                    queue.append(i)
        
        # dist[s] = 0   # where s is source
        while len(queue) > 0:
            i = queue.pop()
            dist = defaultdict(lambda:inf)
            for node, weight in self.adjl[i] :
                dist[node] = min(dist[node], dist[i] + weight)
        return ans

g = Graph()
g.add_edge("English", "Programming")
g.add_edge("English", "HTML")
g.add_edge("Maths", "Programming")
g.add_edge("Programming", "HTML")
g.add_edge("HTML", "CSS")
g.add_edge("CSS", "JS")
g.add_edge("Programming", "Python")
g.add_edge("Python", "Web")
g.add_edge("Java", "Web")
g.add_edge("JS", "Web")
g.add_edge("Programming", "Java")
g.add_edge("Programming", "JS")
print(g.topological_bfs())