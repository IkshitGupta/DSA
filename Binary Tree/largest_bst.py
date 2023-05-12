class Node :
    def __init__(self, key) :
        self.left = None
        self.right = None
        self.data = key

INT_MIN = -2147483648
INT_MAX = 2147483647
def largestBst(root) :
    if root == None:
        return 0, INT_MIN, INT_MAX, 0, True
    if root.left == None and root.right == None :
        return 1, root.data, root.data, 1, True
    l = largestBst(root.left)
    r = largestBst(root.right)
    ret = [0]*5 # size, max, min, ans, isbst
    ret[0] = 1 + l[0] + r[0]
    if l[4] and r[4] and l[1] < root.data and r[2] > root.data :
        ret[2] = min(l[2], r[2], root.data)
        ret[1] = max(l[1], r[1], root.data)
        ret[4] = True
        ret[3] = ret[0]
        return ret
    ret[3] = max(l[3], r[3])
    ret[4] = False
    return ret

root = Node(15)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(5)
print(largestBst(root)[3])
print(-4*10**4)