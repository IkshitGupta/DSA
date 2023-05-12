import sys
inpu = sys.stdin.readline
from functools import lru_cache
count = 0
n = int(inpu())
a = list(map(int, inpu().split(' ')))
# b = [[-1]*n for _ in range(n)]
@lru_cache(maxsize = None)
def maxProfit(start, end, year) :
    global count
    count += 1
    if start > end :
        return 0
    # top down
    # if b[start][end] != -1 :
    #     return b[start][end]
    q1 = a[start]*year + maxProfit(start + 1, end, year + 1)
    q2 = a[end]*year + maxProfit(start, end - 1, year + 1)
    ans = max(q1, q2)
    # b[start][end] = ans
    return ans
# print(maxProfit(0, len(a) - 1, 1))
# print(count)

# using recurssion 63 calls
# using dp 31 calls
# using functools 21 calls


# bottom up     # Check 5th video
def maxProfit2(a, n) :
    # sabse pehle ek bottle aur final year, as recursion me year + 1 is required
    lis = [[0]*n for _ in range(n)]
    year = n
    for i in range(n) : # year n, len(l) 1
        lis[i][i] = year*a[i]
    year -= 1
    for l in range(2, n + 1) :
        start = 0
        end = n - l
        for srt in range(start, end + 1):
            endWindow = srt + l - 1
            lis[srt][endWindow] = max(a[srt]*year + lis[srt + 1][endWindow], a[endWindow]*year + lis[srt][endWindow - 1])
        year -= 1
    return lis[0][-1]
print(maxProfit2(a, n))