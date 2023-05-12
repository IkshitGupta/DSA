# knapsack Variation
import sys
inpu = sys.stdin.buffer.readline
prin = sys.stdout.write
arr = list(map(int, inpu().split()))
diff = int(inpu())
s = sum(arr)
if diff > s or (diff + s) & 1 :
    print(0)
dp = [0]*(s + 1)
dp[0] = 1
for i in range(1, len(arr) + 1) :
    for j in range(s, -1, -1) :     # till -1 if 0 can also be in array
        if arr[i - 1] <= j :
            dp[j]+=dp[j - arr[i - 1]]   # counting subset sums
# sum(s2) - sum(s1) = diff
# sum(s2) + sum(s1) = s
# add
# sum(s2) = (diff + s)//2
# sum(s1) = (s - diff)//2   # dono same hi honge as they are complementary
count = dp[(diff + s)//2]
prin(str(count) + '\n')