class Node :
    def __init__(self, key) :
        self.left = None
        self.right = None
        self.data = key

def insertBST(root, n) :
    if root == None:
        return Node(n)
    if n < root.data :
        root.left = insertBST(root.left, n);
    else :
        root.right = insertBST(root.right, n);
    return root

def inOrder(root) :
    if root :
        inOrder(root.left)
        print(root.data, end = " ")
        inOrder(root.right)

def search(root, n) :
    if root == None :
        return None
    if root.data == n :
        return root
    if n > root.data :
        return search(root.right, n)
    return search(root.left, n)

def inorderSucc (root) :
    if root == None :
        return
    curr = root
    while curr.left:
        curr = curr.left
    return curr

def deleteBST(root, key) :
    if root == None :
        return
    if key < root.data :
        root.left = deleteBST(root.left, key)
    elif key > root.data :
        root.right = deleteBST(root.right, key)
    else :
        if root.left == None :
            temp = root.right
            del root
            return temp
        elif root.right == None :
            temp = root.left
            del root
            return temp
        temp = inorderSucc(root.right)
        root.data = temp.data
        root.right = deleteBST(root.right, temp.data)
    return root

root = None
root = insertBST(root, 5)
root = insertBST(root, 1)
root = insertBST(root, 3)
root = insertBST(root, 4)
root = insertBST(root, 2)
root = insertBST(root, 7)
# inOrder(root)