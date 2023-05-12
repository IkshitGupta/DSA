import sys
sys.setrecursionlimit(10**9)
# def findMax(a, n):
#     if n == 1:
#         # it will not come out of def as it will be returned to the previously called function
#         return a[0]
#     temp = findMax(a, n - 1)
#     if a[n - 1] > temp:
#         return a[n - 1]
#     else:
#         return temp


# a = [1, 2, 33, 4, 100, 67, 56, 999, 44]
# print(findMax(a, len(a)))

# Think how the whole problem (finding max of n elements in A) can be solved if you can solve the exact same problem on a smaller problem (finding max of first n-1 elements of the array). But then, do NOT think how the smaller problem will be solved, just call the function recursively and assume it will be solved
# the solution to the base case is provided and the solution of the bigger problem is expressed in terms of smaller problems.


# def printFun(test):
#     if (test < 1): return
#     else:
#         print(test, end=" ")
#         printFun(test-1)
#         print(test, end=" ")
#         return
# test = 3
# printFun(test)

# it works with stack i.e.
# in stack (bottom to top)- : f(3), f(2), f(1), f(0) then f(0) will be solved then f(1) and so on
# Output - 3 2 1 1 2 3

# Each function call will have its own set of variables, even if the name of the variable is the same as it is the same function being called
# The memory addresses for the variable data are different in different calls

# int fact(int data)
# { 
    # int val = 1, count = 0;
    # if (data>1) val = data*fact(data-1);
    # count++;  
    # printf(“count = %d, data = %d\n”, count, data);
    # return val;
# }
# Output -: 
# count = 1, data = 1
# count = 1, data = 2
# count = 1, data = 3
# count = 1, data = 4
# count does not changed Each call does it on its own copy, lost on return

# Hanoi -:
# Recursive statement of the general problem of n disks
# Step 1: Move the top (n-1) disks from LEFT to CENTER
# Step 2: Move the largest disk from LEFT to RIGHT
# Step 3: Move the (n-1) disks from CENTER to RIGHT

# void towers(int n, char from, char to, char aux)
    # { if (n==1) 
    # { printf ("Disk 1 : %c -> %c \n", from, to) ;
    # return ;
    # }
    # towers (n-1, from, aux, to) ;
    # printf ("Disk %d : %c -> %c\n", n, from, to) ;
    # towers (n-1, aux, to, from) ;
# }
# int main()
# { int n;
# scanf("%d", &n);
# towers(n,'A',‘C',‘B');
# return 0;
# }

# check if array is sorted
# bool isSorted(int *a, int n){
#     if (n == 1) return true;
#     if (a[0] < a[1] && isSorted(a + 1, n - 1)){
#         return true;
#     }
#     return false;
# }


def Power(a, n) :
    if n == 0 :
        return 1
    return a*Power(a, n - 1)
# print(Power(7, 3))

def printN(n) :
    if n == 1 :
        print(1)
        return 1
    printN(n - 1)       # for increasing
    print(n)
    # printN(n - 1)     # for decreasing
# printN(7)

def mul(a, b) :
    if b < 0 :
        a, b = b, a
    elif b == 0 : 
        return 0
    return a + mul(a, b - 1)
# print(mul(-7, 4))

# f(n) = f(n - 1) + f(n - 4) hori + verti
# tiles
# important
def tile(n) :
    if n < 4: 
        return 1
    if n == 4 :
        return 2
    return tile(n - 4) + tile(n - 1)
# print(tile(20))

# Friends pairing problem
# n friends, either keep friend alone or in a pair
# ans = pair(n - 1) + (n - 1)*pair(n - 2) # either friend alone (check rest n - 1) or in pair (choose any one to be in pair from rest n - 1 then check rest n - 2)

def hanoi(n, pick, nothing, place) :
    if n == 1 :
        print(pick, place)
        return
    hanoi(n - 1, pick, place, nothing)      # n - 1 discs ko left se center me rakh do
    print(pick, place)                      # n th disc ko left se right me karenge
    hanoi(n - 1, nothing, pick, place)      # now same problem but sari discs center me hai

# hanoi(3, 'A', 'B', 'C')
# The minimum number of moves required to solve a Tower of Hanoi puzzle is 2^n - 1, where n is the number of disks.

def substrings(s, start) :
    a = [s[start]]
    stri = s[start :]
    if len(stri) > 1 :
        st = substrings(s, start + 1)
        a += st
        a += [s[start] + i for i in st]
        return a
    return a

s = 'ikshit'
# from time import time
# ini = time()
# ans = substrings(s, 0) # not that fast
# for i in ans:
#     print(i)
# print(time() - ini)
# ini = time()
# from itertools import combinations
# for i in range(1, len(s) + 1) :
#     comb = combinations(s, i)
#     for j in comb :
#         print(''.join(j))
# print(time() - ini)

a = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
def phone(n, b) :
    if len(n) == 0:
        print(*b)
    if len(n) > 0 :
        st = a[int(n[0])]
        c = [i + k for i in b for k in st]
        phone(n[1:], c)
# phone('22', [''])

s = 'abc'
def permStr(s, start = 0, n = len(s), ans = []) :  # not fast as perm module
    current = s[0 : start]
    st = s[start :]
    if len(st) == 1 :
        ans.append(''.join(current + s[start :]))
        return ans
    for i in range(start, n) :
        s[i], s[start] = s[start], s[i]
        ans = permStr(s, start + 1, n, ans)
        s[i], s[start] = s[start], s[i]
    return ans
# ans = permStr(list(s))
# for i in ans:
#     print(i, end = ' ')

# board (no snakes) find no. of ways to reach end by dice
def countPath(start, end) :
    if start == end :
        return 1
    if start > end:
        return 0
    count = 0
    for i in range(1, 7) :
        count += countPath(start + i, end)
    return count
# print(countPath(1, 10))

# N Queen # Backtracing

def isSafe(board, row, column, n) :
    # can be done in O(1) maintain arrays col, difference of row and col and sum of row and col make index 1 when it has queen
    for i in range(row) :
        distance = row - i
        if board[i][column] == 1:
            return False
        if column - distance >= 0 and board[i][column - distance] == 1:
            return False
        if column + distance < n and board[i][column + distance] == 1:
            return False
    return True

n = 5
board = [[0]*n for _ in range(n)]
def nQueen (board, n, current = 0) :
    if current == n:
        for i in range(n) :
            for j in range(n) :
                if board[i][j] == 1 :
                    print("Q", end = ' ')
                else:
                    print("_", end = ' ')
            print()
        # print()
        return True
    for i in range(n):
        if isSafe(board, current, i, n) :
            board[current][i] = 1
            # check ki next queen rakh pa rahe hai
            if nQueen(board, n, current + 1) :
                return True    # if we comment this and uncomment pass we will get all possible configurations or if we only return false in base case and leave this as it is then also we will get all configurations
                # pass
            # agar return nahi hua toh upar wali position safe nahi hai so
            board[current][i] = 0   # Backtracing
    return False    # kahi nahi rakh paye
# nQueen(board, n)

# maze = ["0000", "00X0", "000X", "0X00"]
maze = ["0X0X0", "00000", "X0X00", "0XX00", "000X0"]
solution = [[0]*5 for _ in range(5)]
def ratMaze(maze, solution, row, col, last_row, last_col) :
    if (row == last_row) and (col == last_col) :
        solution[last_row][last_col] = 1
        for i in range(last_row + 1) :
            for j in range(last_col + 1) :
                print(solution[i][j], end = ' ')
            print()
        print()
        return True
    if row > last_row or col > last_col :
        return False
    if maze[row][col] == 'X' :
        return False
    # Assume solution exist by current cell
    solution[row][col] = 1
    right =  ratMaze(maze, solution, row, col + 1, last_row, last_col)
    down = ratMaze(maze, solution, row + 1, col, last_row, last_col)
    # Backtracing
    # Ab phir piche ja rahe hai baki solutions ke liye toh is position ko 0
    solution[row][col] = 0
    if right or down :
        return True
    return False
if not ratMaze(maze, solution, 0, 0, 4, 4) :
    print("NO Path")

# sudoku solver
sudoku =   [[5, 3, 0, 0, 7, 0, 0, 0, 0], 
            [6, 0, 0, 1, 9, 5, 0, 0, 0], 
            [0, 9, 8, 0, 0, 0, 0, 6, 0],
            [8, 0, 0, 0, 6, 0, 0, 0, 3],
            [4, 0, 0, 8, 0, 3, 0, 0, 1],
            [7, 0, 0, 0, 2, 0, 0, 0, 6],
            [0, 6, 0, 0, 0, 0, 2, 8, 0],
            [0, 0, 0, 4, 1, 9, 0, 0, 5],
            [0, 0, 0, 0, 8, 0, 0, 7, 9]]
from math import sqrt
def canPlace(sudoku, row, col, n, number, subgrid_len) :
    # starting points of the subgrid
    sx = (row//subgrid_len)*subgrid_len
    sy = (col//subgrid_len)*subgrid_len
    for i in range(n) :
        if sudoku[row][i] == number or sudoku[i][col] == number :
            return False
    for i in range(sx, sx + subgrid_len) :
        for j in range(sy, sy + subgrid_len) :
            if sudoku[i][j] == number :
                return False
    return True
def solveSudoku (sudoku, row, col, n) :
    if row == n : # (index wise ab sab hogayi) 
        for i in range(n) :
            for j in range(n) :
                print(sudoku[i][j], end = ' ')
            print()
        return True
    if col == n :
        return solveSudoku(sudoku, row + 1, 0, n)
    if sudoku[row][col] != 0 :
        return solveSudoku(sudoku, row, col + 1, n)
    # filling
    for i in range(1, n + 1) :
        if canPlace(sudoku, row, col, n, i, int(sqrt(n))) :
            sudoku[row][col] = i
            if solveSudoku(sudoku, row, col + 1, n):
                return True
    # here backtrace meaning koi number se bacha hua sudoku solve nahi ho raha toh purana change karo
    # yaha tab aayega jab upar se kuch return nahi hua
    sudoku[row][col] = 0
    return False

# solveSudoku(sudoku, 0, 0, 9)