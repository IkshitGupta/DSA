# O(n*(log n)^2)
# 1) Find the middle point in the sorted array, we can take P[n/2] as middle point. 
# 2) Divide the given array in two halves. The first subarray contains points from P[0] to P[n/2]. The second subarray contains points from P[n/2+1] to P[n-1].
# 3) Recursively find the smallest distances in both subarrays. Let the distances be dl and dr. Find the minimum of dl and dr. Let the minimum be d.
# 4) Now we need to consider the pairs such that one point in pair is from the left half and the other is from the right half. Consider the vertical line passing through P[n/2] and find all points whose x coordinate is closer than d to the middle vertical line. Build an array strip[] of all such points. 
# 5) Sort the array strip[] according to y coordinates
# 6) Find the smallest distance in strip[]. 
# 7) return the minimum of d and distance calculated in strip

# The code uses quick sort which can be O(n^2) in the worst case. To have the upper bound as O(n (Logn)^2), a O(nLogn) sorting algorithm like merge sort or heap sort can be used 

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

# Note that this method seems to be a O(n^2) method, but it's a O(n) method as the inner loop runs at most 6 times
def solveStrip (strip, d) :
    minval = d
    strip.sort(key = itemgetter(1))
    for i in range(len(strip)) :
        j = i + 1
        while j < len(strip) and strip[j][1] - strip[i][1] < d :
            minval = min(minval, dist(strip[i], strip[j]))
            j += 1
    return minval

def solve(P) :
    if len(P) <= 3:
        return brute(P)
    mid = len(P)//2
    midP = P[mid]
    Pl = P[:mid]
    Pr = P[mid:]
    dl = solve(Pl)
    dr = solve(Pr)
    d = min(dl, dr)
    strip = []  # it will never include points on same side as we are checking less than d
    for i in range(len(P)):
        if abs(P[i][0] - midP[0]) < d : # both x and y coordinates should be less than d
            strip.append(P[i])
    return min(d, solveStrip(strip, d))
    
P = [(2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (3, 4)]
print(brute(P))
P.sort(key = itemgetter(0))
print(solve(P))