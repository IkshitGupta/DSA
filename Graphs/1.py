from collections import deque
n = 3
que = deque([1])
parent = {}
parent[1] = (0, '1')
s = set()
while 1 :
    v = que.popleft()
    if v in s :
        continue
    s.add(v)
    u = (v*10)%n
    while u in s:
        u += n
    parent[u] = (v, '0')
    if u == 0:
        ans = []
        while parent[u] != (0, '1') :
            ans.append(parent[u][1])
            u = parent[u][0]
        break
    else:
        que.append(u)
    u = (v*10 + 1)%n
    while u in s:
        u += n
    parent[u] = (v, '1')
    if u == 0:
        ans = []
        while parent[u] != (0, '1') :
            ans.append(parent[u][1])
            u = parent[u][0]
        break
    else:
        que.append(u)
ans.append('1')
ans.reverse()
# print(parent)
print(ans)