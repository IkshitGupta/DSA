# time efficient
# submitted method is memory efficient
import sys
inpu = sys.stdin.buffer.readline
prin = sys.stdout.write
from collections import deque
m, n = map(int, inpu().split())
text1 = list(map(int, inpu().split()))
text2 = list(map(int, inpu().split()))
dp = [[0]*(n + 1) for _ in range(m + 1)]
for i in range(1, m + 1) :
    for j in range(1, n + 1) :
        if text1[i - 1] == text2[j - 1] :
            dp[i][j] = 1 + dp[i - 1][j - 1]
        else :
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
# get dp table
# now move along the table
i = m
j = n
ans = deque()
while i > 0 and j > 0 :
    if text1[i - 1] == text2[j - 1] :
        ans.appendleft(text1[i - 1])
        i -= 1
        j -= 1
    else :
        if dp[i - 1][j] > dp[i][j - 1] :
            i -= 1
        else:
            j -= 1
print(ans)