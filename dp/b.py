import collections
d = collections.defaultdict(int)
d[0] = 1
c = 0
h = 0
nums = [1, 2, 3]
k = 3
for i in range(len(nums)) :
    h += nums[i]
    c += d[h - k]
    d[h] += 1