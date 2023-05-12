# pick last element as pivot (can take first also)
# put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x.
# O(nlogn)
# O(1) space

def partition(start, end, array) :  # algorithm in which all elements less than pivot comes on its left side and all greater comes on its right side; so now the pivot element comes at its correct position
    pivot = array[end]
    i = start   # at any point at all indices less than i elements arr less than pivot
    for j in range(start, end) :
        if array[j] <= pivot:
            array[i], array[j] = array[j], array[i]
            i += 1
    array[i], array[end] = array[end], array[i]
    return i

def quick_sort(start, end, array):
    if start < end:
        # p is partitioning index, array[p] is at right place
        p = partition(start, end, array)
        # Sort elements before partition and after partition
        quick_sort(start, p - 1, array)
        quick_sort(p + 1, end, array)

import random
a = list(range(20)) + [7, 7, 5, 6, 3]
random.shuffle(a)
print(a)
quick_sort(0, len(a) - 1, a)
print(a)