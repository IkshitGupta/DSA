# return (g, x, y) such that a*x + b*y = g = gcd(a, b)
def xgcd(a, b) :
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a != 0:
        (q, a), b = divmod(b, a), a
        y0, y1 = y1, y0 - q*y1
        x0, x1 = x1, x0 - q*x1
    return b, x0, y0
print(xgcd(15,40))