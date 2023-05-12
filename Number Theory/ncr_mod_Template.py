mod = 10**9 + 7
n = 2

def ncr_mod(n, r) :
    num = den = 1
    for i in range(r) :
        num = (num * (n - i)) % mod
        den = (den * (i + 1)) % mod
    ans = pow(den, mod - 2, mod)    # if mod prime
    ans %= mod
    ans *= num
    ans %= mod
    return ans

# if calculating multiple time then pre calculate num and den, same n differenr r
def ncr_mod(num, den) :
    ans = pow(den, mod - 2, mod)
    ans %= mod
    ans *= num
    ans %= mod
    return ans

up = [1]*(n - 1)
down = [1]*(n - 1)
for i in range(n - 1) :
    up[i] = (up[i - 1] * (n - i)) % mod
    down[i] = (down[i - 1] * (i + 1)) % mod

ncr_mod(up[i - 1], down[i - 1]) # for result