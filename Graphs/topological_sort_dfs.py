# if there is a edge from vertex u to vertex v, then vertex u comes before vertex v in ordering
# Work only in DAG
# O(V + E)

from collections import defaultdict, deque
class Graph :
    def __init__(self) :
        self.adjl = defaultdict(list)

    def add_edge(self, x, y) :    # x to y
        self.adjl[x].append(y)

    def dfs_help(self, n, visited, ans):
        visited[n] = 1
        if n in self.adjl : # so that dictionary size don't change while iteration
            for i in self.adjl[n] :
                if visited[i] == 0 :
                    self.dfs_help(i, visited, ans)
        # At this point, all the children of current node has been visited
        ans.appendleft(n)

    def topological_dfs(self) :    # root node
        visited = defaultdict(int)
        ans = deque()
        for i in self.adjl :
            if visited[i] == 0:
                self.dfs_help(i, visited, ans)
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
print(g.topological_dfs())