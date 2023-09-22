# application of stack
from collections import deque
a = list()  # given list
n = len(a)
# stores indices
# deque because may need to pop front in window problems
ma = deque()
mi = deque()
for j in range(n) :
    while (len(ma) != 0) and (a[ma[-1]] < a[j]) :
        ma.pop()
    ma.append(j)
    while (len(mi) != 0) and (a[mi[-1]] > a[j]) :
        mi.pop()
    mi.append(j)
# next max/min on removing a element (moving window)

# for each element we can calculate smaller/bigger element just before the ith element
# deque<int> mi;
# int n = arr.size();
# vector<int> min_before(n);
# for(int j = 0; j < n; j++){
#     // if min which is not equal required than equality sign
#     while ((mi.size() != 0) && (arr[mi.back()] > arr[j])){
#         mi.pop_back();
#     }
#     if (mi.size() == 0){
#         min_before[j] = -1;
#     }
#     else{
#         min_before[j] = mi.back();
#     }
#     mi.emplace_back(j);
# }