# Time Complexity O(n)
# Space Complexity O(1)
# for array consisting of 0, 1, 2 or 3 distinct elements
def dnf(arr, n) :
    low = 0
    mid = 0
    high = n - 1
    while mid <= high:
        if arr[mid] == 0:
            arr[mid], arr[low] = arr[low], arr[mid]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1
arr = [1, 1, 2, 0, 0, 1, 2, 2, 1, 0]
dnf(arr, len(arr))
print(arr)