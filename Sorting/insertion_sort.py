# Iterate from arr[1] to arr[n] over the array.
# Compare the current element to its predecessor.
# If the current element is smaller than its predecessor, compare it to the elements even before it and place it on desired positon.
# Move the greater elements one position up to make space for the swapped element.
# Time O(n^2)
# Space O(1)

def insertion_sort (lis, n) :
    for i in range(1, n) :
        current = lis[i]
        prev = lis[i - 1]
        if current < prev :
            lis[i] = prev
            j = i - 1
            while j >= 0 and current < lis[j] :
                lis[j + 1] = lis[j]
                j -= 1
            lis[j + 1] = current
    return lis