# sorting in a wave form
# Input {20, 10, 8, 6, 4, 2}      {2, 4, 6, 8, 10, 20}
# Output{20, 8, 10, 4, 6, 2}      {4, 2, 8, 6, 20, 10}
#       {10, 8, 20, 2, 6, 4}
#       or any other possibility
# make sure that all even positioned elements are greater than their adjacent odd elements
# if loop from 1 to n then all odd positioned elements are greater than their adjacent even elements
# Time Complexity O(n)
def sortInWave(arr, n):
	for i in range(0, n, 2):
		if (i > 0) and (arr[i] < arr[i - 1]):
			arr[i], arr[i - 1] = arr[i - 1], arr[i]
		if (i < n - 1) and (arr[i] < arr[i + 1]):
			arr[i], arr[i + 1] = arr[i + 1], arr[i]
arr = [10, 90, 49, 2, 1, 5, 23]
sortInWave(arr, len(arr))
print(arr)