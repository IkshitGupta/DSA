def merge(arr, l, mid, r, temp) :
    inv = 0
    i = l
    j = mid + 1
    k = l
    while (i <= mid) and (j <= r) :
        if (arr[i] <= arr[j]) :
            temp[k] = arr[i]
            i += 1
            k += 1
        else :
            temp[k] = arr[j]
            inv += mid - i + 1
            k += 1
            j += 1
    for idx in range(i, mid + 1) :
        temp[k] = arr[idx]
        k += 1
    for idx in range(j, r + 1) :
        temp[k] = arr[idx]
        k += 1
    for i in range(l, r + 1) :
        arr[i] = temp[i]
    return inv
def mergeSort(arr, l, r, temp) :
    inv = 0
    if l < r :
        mid = (l + r)//2
        inv += mergeSort(arr, l, mid, temp)
        inv += mergeSort(arr, mid + 1, r, temp)
        inv += merge(arr, l, mid, r, temp)
    return inv

# c++ impementation in gfg folder
# similar leetcode question reverse pair