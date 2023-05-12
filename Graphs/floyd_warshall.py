# O(n^3)
# ALL PAIR SHORTEST PATH PROBLEM
# The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph
# can do by dijkstra for all but not optimum
# as all pairs required better to use adjacency matrix
# in the matrix, we upate by taking each vertex as a intermediate i.e. f(3, 2) taking intermediate 4 means going fron 3 to 2 via 4 = f(3, 4) + f(4, 2)
# row and column containing the intermediate vertex is not needed to be changed
# directed graph
# dp
# Floyd Warshall works for negative edge but not for negative cycle
# This algorithm works for both the directed and undirected weighted graphs

# we just have to check the nodes distance from itself and if it comes out to be negative, we will detect the required negative cycle.
# A negative cycle is one in which the overall sum of the cycle comes negative. Hence, for shortest path algorithms an undirected graph cannot have any negative weight edges

# when vertices 0 to v - 1
# can change range (1, v + 1) if vertices 1 to v
from collections import defaultdict
inf = 10**14
v, e = map(int, input().split())
adjm = [[inf]*v for _ in range(v)]
for _ in range(e) :
    a, b, w = map(int, input().split())
    adjm[a][b] = w
for i in range(v) :
    adjm[i][i] = 0
for i in range(v) : # intermediate vertex
    for j in range(v):
        for k in range(v) :  # j to k
            adjm[j][k] = min(adjm[j][k], adjm[j][i] + adjm[i][k])
for i in adjm:
    print(*i)

# general case for all types of vertices
vertices = set()
vl = []
adjl = defaultdict(lambda : inf)
for _ in range(int(input())) :
    a, b, w = map(int, input().split())
    if a not in vertices:
        vertices.add(a)
        vl.append(a)
    if b not in vertices:
        vertices.add(b)
        vl.append(b)
    adjl[(a, b)] = w
for i in vl :
    adjl[(i, i)] = 0
for i in vl : # intermediate vertex
    for j in vl:
        for k in vl :  # j to k
            adjl[(j, k)] = min(adjl[(j, k)], adjl[(j, i)] + adjl[(i, k)])
print(adjl)