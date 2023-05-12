# Time O(nLogn)
# Space O(n)
# Recursive
# It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves.
# Find the middle point to divide the array into two halves
# Call mergeSort for first half   
# Call mergeSort for second half
# Merge the two halves sorted in step 2 and 3
# The lower bound for Comparison based sorting algorithm (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(n Log n), i.e., they cannot do better than nLogn. 

def merge(left, right):
    # assuming sort ho chuki in every half arrays 2 pointers i and j check from starting in both which is smaller and place in result
	if (not len(left)) or (not len(right)):
		return left or right
	result = []
	i, j = 0, 0
	while len(result) < len(left) + len(right):
		if left[i] < right[j]:
			result.append(left[i])
			i += 1
		else:
			result.append(right[j])
			j += 1
		if i == len(left) or j == len(right):
			result.extend(left[i:] or right[j:])    # dono me se ek khali hoga
			break
	return result

def merge_sort(lis):
	if len(lis) < 2:
		return lis
	middle = len(lis)//2
	left = merge_sort(lis[:middle])
	right = merge_sort(lis[middle:])
	return merge(left, right)
	
# import random
# a = list(range(15))
# random.shuffle(a)
# print(a)
# a = merge_sort(a)
# print(a)