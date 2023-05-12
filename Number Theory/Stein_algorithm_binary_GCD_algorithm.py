# Stein’s algorithm or binary GCD algorithm
# If both a and b are 0, gcd is zero gcd(0, 0) = 0.
# gcd(a, 0) = a and gcd(0, b) = b because everything divides 0.
# If a and b are both even, gcd(a, b) = 2*gcd(a/2, b/2) because 2 is a common divisor.
# If a is even and b is odd, gcd(a, b) = gcd(a/2, b). It is because 2 is not a common divisor.
# If both a and b are odd, then gcd(a, b) = gcd(|a-b|/2, b). Note that difference of two odd numbers is even

# Time Complexity: O(N*N) where N is the number of bits in the larger number = log2(max(a, b)**2)
# while time complexity of euclidean is log2(min(a, b))
# euclidean better mostly, sometimes this is better when mod functions take a lot of time
def hcf(a, b) :
    if a == 0 :
        return b
    if b == 0 :
        return a
    k = 0
    while (a|b)&1 == 0 :
        a >>= 1
        b >>= 1
        k += 1
    while a&1 == 0 :
        a >>= 1
    while b != 0 :
        while b&1 == 0 :
            b >>= 1
        if a > b :
            a, b = b, a
        b = b - a
    return a << k       # restore common factors of 2