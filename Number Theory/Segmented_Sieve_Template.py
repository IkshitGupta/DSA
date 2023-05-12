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
def segmented(n) :      # for n >= 2
    if n == 2:
        return [2]
    if n == 3 :
        return [2, 3]
    limit = int(sqrt(n))
    prime = primes(limit)
    pa = prime.append
    low = limit
    high = limit*2
    while low <= n :
        if high > n :
            high = n
        mark = [1 for _ in range(high - low + 1)]
        for i in prime :
            lol = (low//i)*i
            if lol < low :
                lol += i
            for j in range(lol, high + 1, i) :
                mark[j - low] = 0
        r = low
        if low & 1 == 0 :
            r += 1
        for i in range(r, high + 1, 2) :
            if mark[i - low] :
                pa(i)
        low += limit
        high += limit
    return prime
print(segmented(10**9))
# less memory consumption, same time complexity O(nloglogn)
# It follows from the optimization "sieving till root" that there is no need to keep the whole array is_prime[1...n] at all time. For sieving it is enough to just keep the prime numbers until the root of n, i.e. prime[1... sqrt(n)]