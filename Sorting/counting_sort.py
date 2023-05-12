# Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values
# Take a count array to store the count of each unique object.
# Modify the count array such that each element at each index stores the sum of previous counts. 
# The modified count array indicates the position of each object in 
# the output sequence.
# Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted.
# Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input. 
def count_sort(arr, n):
    ma = max(arr)
    mi = min(arr)
    range_of_elements = ma - mi + 1
    count_arr = [0]*range_of_elements
    output_arr = [0]*n
    for i in range(0, n):
        count_arr[arr[i] - mi] += 1         # count of each element
    for i in range(1, range_of_elements):
        count_arr[i] += count_arr[i - 1]    # count + previous count to get position
    for i in range(n - 1, -1, -1):
        output_arr[count_arr[arr[i] - mi] - 1] = arr[i] # checking for each array element ki woh kaha aayega
        count_arr[arr[i] - mi] -= 1     # subtracting so that agla same ek value niche aaye
    return output_arr

# arr = [-5, -10, 0, -3, 8, 5, -1, 10]
arr = [1, 4, 1, 2, 7, 5, 2]
ans = count_sort(arr, len(arr))
print(ans)