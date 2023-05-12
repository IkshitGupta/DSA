# take a node, move completely in its depth, than come back
# implemented using stacks (3 traversals)
# can't find shortest path
# O(V + E)
# a program can have two graphs, so better to implement in class
from collections import defaultdict

class Graph() :
    def __init__(self) :
        self.adjl = defaultdict(list)

    def add_edge(self, x, y) :
        self.adjl[x].append(y)
        self.adjl[y].append(x)

    def dfs_help(self, n, visited, ans):
        ans.append(n)
        visited.add(n)
        for i in self.adjl[n] :
            if i not in visited:
                self.dfs_help(i, visited, ans)

    def dfs(self) :    # root node
        visited = set()
        ans = []
        # dfs_help(n, visited, ans)
        component = 0
        for i in self.adjl :
            if i not in visited:
                self.dfs_help(i, visited, ans)
                component += 1
        return ans

    def dfs_iterative_help(self, n, visited, ans) :
        stack = [n]
        while len(stack) > 0 :
            s = stack.pop()
            if s not in visited:
                ans.append(s)
                visited.add(s)
                for i in self.adjl[s] :
                    if i not in visited:
                        stack.append(i)

    def dfs_iterative(self) :
        visited = set()
        ans = []
        # dfs_iterative_help(n, visited, ans)
        component = 0
        for i in self.adjl :
            if i not in visited:
                self.dfs_iterative_help(i, visited, ans)
                component += 1
        return ans
        
g = Graph()
g.add_edge("Amritsar", "Jaipur")
g.add_edge("Delhi", "Jaipur")
g.add_edge("Mumbai", "Jaipur")
g.add_edge("Mumbai", "Bhopal")
g.add_edge("Mumbai", "Bengalore")
g.add_edge("Delhi", "Agra")
g.add_edge("Delhi", "Bhopal")
g.add_edge("Amritsar", "Delhi")
g.add_edge("Andaman", "Nicobar");
g.add_edge("I", "K");
print(g.dfs())
print(g.dfs_iterative())

h = Graph()
h.add_edge(1, 0)
h.add_edge(2, 1)
h.add_edge(3, 4)
h.add_edge(4, 0)
print(h.dfs())
print(h.dfs_iterative())