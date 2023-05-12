# HackerEarth
import sys
inpu = sys.stdin.buffer.readline
prin = sys.stdout.write
from functools import lru_cache
@lru_cache(maxsize = None)
def maxProfit(start, end) :
    global a
    if start > end :
        return 0
    q1 = a[start] + min(maxProfit(start + 2, end), maxProfit(start + 1, end - 1))
    q2 = a[end] + min(maxProfit(start + 1, end - 1), maxProfit(start, end - 2))
    return max(q1, q2)
for _ in range(int(inpu())) :
    n = int(inpu())
    a = list(map(int, inpu().split()))
    ans = maxProfit(0, n - 1)
    prin(str(ans) + '\n')
    maxProfit.cache_clear()