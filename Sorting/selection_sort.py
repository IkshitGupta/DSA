# find minimum replace it with first then find minimum in rest of list and replace it with second
# In less than n replacements
# Time O(n^2)
# Space O(1)

def selection_sort(lis, n) :
    for j in range(n - 1) :
        replacement_index = j
        value = lis[j]
        for i in range(j + 1, n) :
            current = lis[i]
            if current < value :
                value = current
                replacement_index = i
        lis[j], lis[replacement_index] = lis[replacement_index], lis[j]  
    return lis