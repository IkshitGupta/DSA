# O(n logn)
# not sorting y coordinates again and again

from operator import itemgetter
from math import sqrt, inf

def dist(x, y) :
    return sqrt(pow(x[0]-y[0], 2) + pow(x[1]-y[1], 2))

def brute(P) :
    minval = inf
    for i in range(len(P)) :
        for j in range(i + 1, len(P)) :
            minval = min(dist(P[i], P[j]), minval)
    return minval

def solveStrip (strip, d) :
    minval = d
    for i in range(len(strip)) :
        j = i + 1
        while j < len(strip) and strip[j][1] - strip[i][1] < d :
            minval = min(minval, dist(strip[i], strip[j]))
            j += 1
    return minval

def solve(P, Q) :
    if len(P) <= 3:
        return brute(P)
    mid = len(P)//2
    midP = P[mid]
    Pl = P[:mid]
    Pr = P[mid:]
    Ql = []
    Qr = []
    for i in range(len(P)) :
        if Q[i][0] < midP[0] or (Q[i][0] == midP[0] and Q[i][1] < midP[1]) :
            Ql.append(Q[i])
        else :
            Qr.append(Q[i])
    dl = solve(Pl, Ql)
    dr = solve(Pr, Qr)
    d = min(dl, dr)
    strip = []  # it will never include points on same side as we are checking less than d
    for i in range(len(P)):
        if abs(Q[i][0] - midP[0]) < d : # both x and y coordinates should be less than d
            strip.append(Q[i])
    return min(d, solveStrip(strip, d))
    
P = [(2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (3, 4)]
print(brute(P))
P.sort(key = itemgetter(0))
Q = sorted(P, key = itemgetter(1))
print(solve(P, Q))