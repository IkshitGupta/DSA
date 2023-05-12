from random import randint
n = randint(1, 100)
m = 10
print(n, m)
for _ in range(m) :
    q = randint(1, 2)
    print(q, end = ' ')
    if q == 1:
        a = randint(0, n - 1)
        b = randint(a + 1, n)
        print(a, b, end = ' ')
        print()
    else :
        a = randint(0, n - 1)
        print(a)