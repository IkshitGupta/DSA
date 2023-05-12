class Heap :
    def __init__(self, type = True):
        self.v = []
        self.minHeap = type
    def compare(self, a, b) :
        if self.minHeap :
            return a < b
        return a > b
    def heapify(self, i) :
        left = 2*i + 1
        right = 2*i + 2
        minIndex = i
        if (left < len(self.v) and self.compare(self.v[left], self.v[i])) :
            minIndex = left
        if (right < len(self.v) and self.compare(self.v[right], self.v[minIndex])) :
            minIndex = right
        if (minIndex != i) :
            self.v[i], self.v[minIndex] = self.v[minIndex], self.v[i]
            self.heapify(minIndex)
    def push(self, data) :
        self.v.append(data)
        index = len(self.v) - 1
        parent = (index - 1)//2
        while (index > 0 and self.compare(self.v[index], self.v[parent])) :
            self.v[parent], self.v[index] = self.v[index], self.v[parent]
            index = parent
            parent = (index - 1)//2
    def top(self) :
        return self.v[0]
    def empty (self) :
        return len(self.v) == 0
    def pop(self) :
        self.v[0], self.v[len(self.v) - 1] = self.v[len(self.v) - 1], self.v[0]
        self.v.pop()
        self.heapify(0)    

h = Heap(False)
h.push(5)
h.push(15)
h.push(2)
h.push(20)
h.push(3)
while (not h.empty()) :
    print(h.top(), end = ' ')
    h.pop()

import heapq    # It is min heap
# heapify(iterable) :- This function is used to convert the iterable into a heap data structure. i.e. in heap order. O(n) time
# heappush(heap, ele) :- This function is used to insert the element mentioned in its arguments into heap. The order is adjusted, so as heap structure is maintained.
# heappop(heap) :- This function is used to remove and return the smallest element from heap. The order is adjusted, so as heap structure is maintained.
# heappushpop(heap, ele) :- This function combines the functioning of both push and pop operations in one statement, increasing efficiency. Heap order is maintained after this operation.
# heapreplace(heap, ele) :- This function also inserts and pops element in one statement, but it is different from above function. In this, element is first popped, then the element is pushed.i.e, the value larger than the pushed value can be returned. heapreplace() returns the smallest value originally in heap regardless of the pushed element as opposed to heappushpop().
# nlargest(k, iterable, key = fun) :- This function is used to return the k largest elements from the iterable specified and satisfying the key if mentioned.
# nsmallest(k, iterable, key = fun) :- This function is used to return the k smallest elements from the iterable specified and satisfying the key if mentioned.
# merge() merges sorted arrays
# For list of tuple or dictionary
# (1,2)
# Priority : 1
# Value/element : 2
# Note that if the first elements in a pair of tuples are equal, further elements will be compared. If this is not what you want, you need to ensure that each first element is unique.
# But we multiply each value by -1 so that we can use it as MaxHeap.

print()
x= [5, 6, 17, 18, 9, 11, 0, 3]
y = [1, 2, 8, 9, 10, 91, 1, 2]
l = []
# heapq.heapify(l)    # no need to heapify empty list
for i in range(8) :
    heapq.heappush(l, (x[i]*x[i] + y[i]*y[i], i))
for i in range(8) :
    print(heapq.heappop(l))

class Node :
    def __init__(self, freq, left = None, right = None) :
        self.freq = freq
        self.left = left
        self.right = right
    # lt denotes comparision operator
    # Overloading it
    #  so now we can compare Node using this
    def __lt__(self, a):    # stands for less than
        return self.freq < a.freq
    # now can directly add nodes to heap