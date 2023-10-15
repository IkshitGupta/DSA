from math import sqrt
def primeFactoriztion(n):
    factors = []
    while n & 1 == 0:
        factors.append(2)
        n //= 2
    for i in range(3, int(sqrt(n)) + 1, 2) :
        while n % i == 0:
            factors.append(i)
            n //= i
        if n == 1:
            return factors
    if n > 2:
        factors.append(n)
    return factors
# if unique factors required then before for loop can apply if and append only once
# if there are multiple queries than better to find primes by sieve and then check which primes are divisible
# get minimum prime factor of each number
MAXN = 60000
spf = [0 for _ in range(MAXN + 1)]  # storing min prime factor
def sieve():
    for i in range(1, MAXN + 1):
        spf[i] = i
    for i in range(2, int(sqrt(MAXN)) + 1):
        if spf[i] == i:
            for j in range(i*i, MAXN + 1, i):
                if spf[j] == j:     # as we want factors in sorted manner
                    spf[j] = i
def getFactorization(x):
    ret = []
    while x != 1:
        ret.append(spf[x])
        x //= spf[x]
    return ret
sieve()
print(getFactorization(12344))
# Pollard’s Rho is a prime factorization algorithm, particularly fast for a large composite number with small prime factors

# const int MAXN = 1000001;
# vi spf;
# void sieve(){
#     spf.resize(MAXN + 1);
#     iota(all(spf), 0);
#     fr(i, 2, int(sqrt(MAXN)) + 1){
#         if (spf[i] == i){
#             for (int j = i*i; j <= MAXN; j += i){
#                 if (spf[j] == j){
#                     spf[j] = i;
#                 }
#             }
#         }
#     }
# }

# vi getFactorization(int x){
#     vi facs;
#     while (x != 1){
#         facs.eb(spf[x]);
#         x /= spf[x];
#     }
#     return facs;
# }