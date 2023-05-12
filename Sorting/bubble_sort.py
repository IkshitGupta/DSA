# First Pass: 
# ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 )
# ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 )
# ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 )
# ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
# Then repeat until sorted
# Time O(n^2)
# Space O(1)

def bubble_sort (lis, n) :
    for i in range(n) :
        change = 0
        for j in range(n - i - 1) :
            if lis[j + 1] < lis[j] :
                change = 1
                lis[j + 1], lis[j] = lis[j], lis[j + 1]
        if change == 0 :
            return lis
    return lis