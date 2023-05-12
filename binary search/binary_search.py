# if a subarray i to j is good then i to j - 1 is also good can use binary search on answer
# sorted array
a = list(range(0, 100000000, 4))
l = len(a)
def binary_search(arr, n, x):
    low = 0
    high = n - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1
# print(binary_search(a, len(a), 10000))

def nthRoot(number, precision, p):
    start = 0
    end, ans = number, 1
    # For computing integral part of square root of number
    while (start <= end):
        mid = int((start + end) / 2)
        k = pow(mid, p)
        if (k == number):
            ans = mid
            break
        if (k < number):
            start = mid + 1
            ans = mid
        else:
            end = mid - 1
    # For computing the fractional part of square root upto given precision
    increment = 0.1
    for _ in range(0, precision):
        while (pow(ans, p) <= number):
            ans += increment
        ans -= increment
        increment /= 10 
    return ans
# print(round(squareRoot(10**18 - 100, 2), 2))
# print(round(squareRoot(10, 4), 4))


# Search an element in a sorted and rotated array eg 3 4 5 1 2
# so it has two sorted arrays
# CASE 1 :
# MID IN FIRST SORTED ARRAY
#     PART 1: ELEMENT BEFORE MID  -: NORMAL BINARY SEARCH IN START - MID
#     PART 2: ELEMENT AFTER MID  -: 
#         A SMALLER ROTATED ARRAY AGAIN CHECK MID AND CASES AND PARTS
# CASE 2 :
# MID IN SECOND SORTED ARRAY
#     PART 1: ELEMENT BEFORE MID  -:
#         A SMALLER ROTATED ARRAY AGAIN CHECK MID AND CASES AND PARTS
#     PART 2: ELEMENT AFTER MID   -: -: NORMAL BINARY SEARCH IN MID - END

# all elements in the array should be distinct

def rotated_search(arr, start, end, key) :
    # when all elements are distinct
    if start > end :
        return -1
    mid = (start + end)//2
    if arr[mid] == key :
        return mid
    # if arr[start] == arr[mid] and arr[end] == arr[mid] :  # when array contain duplicates # the first half could be out of order (i.e. not in the ascending order, e.g. {3, 1, 2, 3, 3, 3, 3}) and we have to deal this case separately. 
    #     return rotated_search(arr, start + 1, end - 1, key)
    # CASE 1
    if arr[start] <= arr[mid] :
        # PART 1
        if key >= arr[start] and key < arr[mid] :
            return rotated_search(arr, start, mid - 1, key)
        # PART 2
        return rotated_search(arr, mid + 1, end, key)
    # CASE 2
    # no need to write else as agar upar wala hai toh return ho chuka hoga
    if key > arr[mid] and key <= arr[end] :
        return rotated_search(arr, mid + 1, end, key)
    return rotated_search(arr, start, mid - 1, key)

# a = [5, 6, 7, 1, 2, 3, 4]
a = list(range(100000))
a = a[995:] + a[: 995]
# print(rotated_search(a, 0, len(a) - 1, 78))


# finding pivot element i.e. in 4 5 1 2 3; 5 is the pivot element, it will also be the highest element
def rotated_max(arr, n) :
    start = 0
    end = n - 1
    while start <= end:
        mid = (start + end)//2
        if mid < end and arr[mid] > arr[mid + 1] :
            return mid
        if mid > start and arr[mid] < arr[mid - 1] :
            return mid - 1
        if arr[start] > arr[mid] :
            end = mid - 1
        else :
            start = mid + 1
    return n - 1 # no pivot element so array is not rotated hence last element is max
# can find min which will be just next after pivot
# in case of duplicates - if arr[start] == arr[mid] and arr[end] == arr[mid] : end -= 1
a = [5, 6, 7, 8, 9, 10]
# print(rotated_max(a, 6))


# if you know the range of answer that answer will be between start and end then can use binary search
# use for in real numbers
# when finding minimum value of maximum of some other value or the other way
# eg. 
# min time meeting different coordinates
# so binary search in time
# we have to find maximum time of all the individual coordinates as the coordinate which will reach last after that meeting will start

# finding maximum average of segment of any length

def reverse_right(a, val) : # in reverse sorted gives upper bound
    if len(a) == 0:
        return 0
    start = 0
    end = len(a) - 1
    while start <= end :
        mid = (start + end)//2
        if a[mid] >= val :  # remove equality for reverse_left
            start = mid + 1
        else :
            end = mid - 1
    return start
a = [3, 2, 2, 0]
print(reverse_right(a, 3))