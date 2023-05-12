from math import sqrt
def findDivisors(n) :
    divisors = []
    store = []
    for i in range(1, int(sqrt(n)) + 1) :
        if n % i == 0:
            divisors.append(i)
            if n // i != i :
                store.append(n//i)
    divisors += store[::-1]
    return divisors

print(findDivisors(10**15))