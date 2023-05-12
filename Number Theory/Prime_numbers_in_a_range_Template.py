from math import sqrt
def primes(n) :
    prime = [1 if i & 1 == 1 else 0 for i in range(n + 1)]
    prime[2] = 1
    prime[1] = 0
    for i in range(3, int(sqrt(n)) + 1, 2) :
        if prime[i] == 1:
            for j in range(i*i, n + 1, i) :
                prime[j] = 0
    prime = [2] + [i for i in range(3, n + 1, 2) if prime[i]]
    return prime
def segmented(l, r) :
    limit = int(sqrt(r))
    prime = primes(limit)
    mark = [1 for _ in range(r - l + 1)]
    for i in prime :
        lol = (l//i)*i
        if lol < l :
            lol += i
        for j in range(lol, r + 1, i) :
            mark[j - l] = 0
    k = l
    if k & 1 == 0 :
        k += 1
    mark = [i for i in range(k, r + 1, 2) if mark[i - l]]
    return mark

# sieve -: O(nloglogn)
# O((R - L + 1)loglogR + sqrt(R)loglogsqrt(R))