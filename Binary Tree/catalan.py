# Cn = C0Cn-1 + C1Cn-2 + .......... + Cn-1C0
def catalan (n, store) :
    if n <= 1 :
        return 1
    if store[n] != 0 :
        return store[n]
    ans = 0
    for i in range(n) :
        ans += catalan(i, store)*catalan(n - i - 1, store)
    store[n] = ans
    return ans
n = 19
# OR
# 1 1 2 5 14 .......
catalan = [0]*(n + 1)
catalan[0] = 1
catalan[1] = 1
for i in range(2, n + 1) :
    for j in range(i) :
        catalan[i] += catalan[j]*catalan[i - j - 1]

# reducing to catalan number check till C3

# figuring out
# no of bst length 3
# A<B<C
#       A       B       C
#        \     / \     /
#        BC   A   C   AB
#      C0C2   C1C1   C2C0
# A -: 0 left 2 right
# B -: 1 left 1 right
# C -: 2 left 0 right 
# if unlabeled i.e. don't know which bigger which smaller; ans = n!*Cn

# arranging parenthesis, even if characters given answer is same
# 2 -: () 2 ways other inside or outside
# 3 -: () 0 inside 2 outside
#         1 inside 1 outside
#         2 inside 0 outside

# dyck words number of x always greater than number of y -: xy xxy xyxy; yx(wrong)
# 2: put outside x   y remaining xy inside or outside

# mountain range go up n times and down n times
# 2: / \     /\
# inside    / \
# outside /\/\

# number of paths such that you always stay above or below diagonals
# for staying below number of horizontal moves >= vertical egs. HHH, HHV, HVHV, similar to dyck words
# for above Verical moves >= horizontal moves

# triangulating a convex polygon
# choose a base make all possible triangle including that base solve for remaining; ans = Cn-2

# connecting non interseccting chords
# 3: join two points 
# left
# 0 pair 2 pair
# 1 pair 1 pair
# 2 pair 0 pair