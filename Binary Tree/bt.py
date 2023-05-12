from collections import deque
class Node :
    def __init__(self, key) :
        self.left = None
        self.right = None
        self.data = key

def preOrder(root, a) :
    if root :
        a.append(root.data)
        # print(root.data, end = " ")
        preOrder(root.left, a)
        preOrder(root.right, a)

def preOrderIterative (root) :
    if root is None:
        return []
    nodeStack = []
    ans = []
    nodeStack.append(root)
    while len(nodeStack) > 0:
        node = nodeStack.pop()
        ans.append(node.data)
        if node.right is not None:
            nodeStack.append(node.right)
        if node.left is not None:
            nodeStack.append(node.left)
    return ans
        
def inOrder(root) :
    if root :
        inOrder(root.left)
        print(root.data, end = " ")
        inOrder(root.right)

def inOrderIterative(root) :
    current = root
    stack = []
    ans = []
    while 1 :
        if current is not None:
            stack.append(current)
            current = current.left
        elif len(stack) > 0 :
            current = stack.pop()
            ans.append(current.data)
            current = current.right
        else:
            break
    return ans

def postOrder(root) :
    if root :
        postOrder(root.left)
        postOrder(root.right)
        print(root.data, end = " ")

def postOrderIterative (root) :
    if root is None:
        return []
    stack = []
    ans = []
    stack.append(root)
    while len(stack) > 0 :
        node = stack.pop()
        ans.append(node.data)
        if node.left is not None :
            stack.append(node.left)
        if node.right is not None :
            stack.append(node.right)
    ans.reverse()
    return ans

# O(n)
def construct_by_pre_in(preorder, inorder, iddic, start, end) :
    if start > end :
        return None
    global idx;
    curr = preorder[idx]
    idx += 1
    node = Node(curr)
    if start == end :
        return node
    pos = iddic[curr]
    node.left = construct_by_pre_in(preorder, inorder, iddic, start, pos - 1)
    node.right = construct_by_pre_in(preorder, inorder, iddic, pos + 1, end)
    return node

def levelOrder(root) :
    ans = []
    if root == None:
        return ans
    q = deque()
    q.append(root)
    q.append(None)
    while 1 :
        a = q.popleft()
        if a == None:
            if len(q) == 0:
                break
            q.append(None)
            continue
        ans.append(a.data)
        if a.left != None :
            q.append(a.left)
        if a.right != None :
            q.append(a.right)
    return ans

a = {}
def height(root) :
    if root == None :
        a[root] = 0
        return 0
    # if (h.find(root) != h.end()){
    #     return h[root];
    # }
    ans = max(height(root.left), height(root.right)) + 1
    a[root] = ans
    return ans
def diameter(root) :
    if root == None :
        return 0
    return max(diameter(root.left), diameter(root.right), a[root.left] + a[root.right])
# height(root)
# or
def diameter2(root) :
    global a
    if root == None :
        return 0
    rl = diameter2(root.left)
    rr = diameter2(root.right)
    a = max(rl + rr, a)
    return max(rl, rr) + 1

# incrementing each node by sum of its subtrees
# O(n)
def sum_replace(root) :
    if root == None :
        return
    sum_replace(root.left)
    sum_replace(root.right)
    if root.left != None:
        root.data += root.left.data
    if root.right != None:
        root.data += root.right.data
        
def getPath(root, n, path) :
    if root == None:
        return 0
    path.append(root.data)
    if root.data == n :
        return 1
    if getPath(root.left, n, path) or getPath(root.right, n, path) :
        return 1
    path.pop()
    return 0

def LCA(root, n1, n2) :
    path1 = []
    path2 = []
    if (not getPath(root, n1, path1) or not getPath(root, n2, path2)) :
        return -1
    for i in range(min(len(path1), len(path2))) :
        if path1[i] != path2[i] :
            break
    else :
        return path1[i]
    return path1[i - 1]

def LCA2(root, n1, n2) :
    if not root :
        return None
    if root.data == n1 or root.data == n2:
        return root
    leftLCA = LCA2(root.left, n1, n2)
    rightLCA = LCA2(root.right, n1, n2)
    if leftLCA and rightLCA :
        return root
    if leftLCA :
        return leftLCA
    return rightLCA

def flatten(root) :
    if root == None or (root.right == None and root.left == None) :
        return
    if root.left :
        flatten(root.left)
        temp = root.right
        root.right = root.left
        root.left = None
        tail = root.right
        while tail.right :
            tail = tail.right
        tail.right = temp
    flatten(root.right)
    

#         1
#     /        \  
#    2          3  
#  /  \        /  \
# 4    5      6    7
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.right = Node(7)
root.right.left = Node(6)

# a = []
# preOrder(root, a)
# print(a)
# print(preOrderIterative(root))
# inOrder(root)
# print(inOrderIterative(root))
# postOrder(root)
# print(postOrderIterative(root))
# print(levelOrder(root))

# inorder = [4, 2, 5, 1, 6, 3, 7]
# preorder = [1, 2, 4, 5, 3, 6, 7]
# a = {}
# for i in range(len(inorder)) :
#     a[inorder[i]] = i
idx = 0
# root2 = construct_by_pre_in(preorder, inorder, 0, 6)
# preOrder(root2)
# sum_replace(root)
# preOrder(root)
# print(LCA(root, 6, 7))
# print(LCA2(root, 6, 7).data)

# inOrder(root)
# flatten(root)
# inOrder(root)