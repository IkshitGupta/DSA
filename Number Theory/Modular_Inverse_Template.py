from math import sqrt
def xgcd(a, b) :
    x0, x1 = 0, 1
    while a != 0:
        (q, a), b = divmod(b, a), a
        x0, x1 = x1, x0 - q*x1
    return b, x0
def modInverse (a, m) :
    g, x = xgcd(a, m)
    if g != 1:
        return 0
    x = (x%m + m)%m # The resulting x from the extended Euclidean algorithm may be negative, so x % m might also be negative, and we first have to add m to make it positive.
    return x
# print(modInverse(16, 2))

# A modular multiplicative inverse of an integer a is an integer x such that
# a⋅x ≡ 1 mod m
# 1 <= x <= m - 1 (so one way can be loop in 1 to m and check)
# We will also denote x simply with a^−1
# modular inverse exists if and only if a and m are relatively prime
# a⋅x+m⋅y=1 (extended Euclidean algorithm)
# if we take modulo m of both sides, we can get rid of m⋅y, and the equation becomes:
# a⋅x ≡ 1 mod m

# another method
# a ^ (phi m) = 1 (mod m)
# multiply by a^-1
# a^(phi m - 1) = a^-1 (mod m)  # now can apply binary exponentiation

# if m prime, then by fermet theorem phi m  = m - 1
# a^(m - 2) = a^-1 (mod m)
def modInv(a, m):
    return pow(a, m - 2, m)

# modular inverse for every number in the range [1,m−1]
# algorithm with complexity O(m). However for this specific algorithm we require that the modulus m is prime. If it is not prime then we can do in O(mlogm) using above algorithm
def invmodRange(m) :        # m is prime
    inv = [0]*m
    inv[1] = 1
    for i in range (2, m) :
        inv[i] = m - (m//i)*inv[m%i]%m
    return inv

# print(invmodRange(7))

# (a/b)%m = ((a%m)*(b^-1%m))%m, used in ncr, ncp

# for calculating phi(m)
# Euler’s Totient function phi(n) for an n is the count of numbers in {1, 2, …, n} that are relatively prime to n
# one way is to iterate in 1, n
# other way to use formula n*(1 - 1/p)*.... , but will have floating point calculations
# other way is to count all prime factors and their multiples and subtract this count from n to get the totient function value (Prime factors and multiples of prime factors won’t have gcd as 1) 
def phi(n):
    result = n
    if n & 1 == 0 :
        while n & 1 == 0:
            n //= 2
        result -= result//2    # agar 16 tha toh total 8 factors
    for i in range(3, int(sqrt(n)) + 1, 2) :
        if n % i == 0:
            while n % i == 0:
                n //= i
            result -= result//i
        if n == 1:
            break
    if n > 2:
        result -= result//n
    return result

# for many numbers pre calculate by sieve
MAXN = 20
spf = [0 for _ in range(MAXN + 1)]
def sieve():
    for i in range(1, MAXN + 1):
        spf[i] = i
    for i in range(2, MAXN + 1, 2):
        spf[i] -= spf[i]//2
    for i in range(3, MAXN + 1, 2):
        if spf[i] == i:
            for j in range(i, MAXN + 1, i):
                spf[j] -= spf[j]//i
sieve()
print(spf)