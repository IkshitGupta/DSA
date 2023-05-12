#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node* root){
    if (root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(Node* root){
    if (root == NULL) {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void postOrder(Node* root){
    if (root == NULL) {
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int searchinOrder(int inorder [], int start, int end, int curr){
    for (int i = start; i <= end; i++){
        if (inorder[i] == curr){
            return i;
        }
    }
    return -1;
}
// can create map

// O(n*n)
Node* construct_by_pre_in(int preorder [], int inorder [], int start, int end) {
    if (start > end){
        return NULL;
    }
    static int idx = 0;
    int curr = preorder[idx];
    idx ++;
    Node* node = new Node(curr);
    if (start == end){
        return node;
    }
    int pos = searchinOrder(inorder, start, end, curr);
    node -> left = construct_by_pre_in(preorder, inorder, start, pos - 1);
    node -> right = construct_by_pre_in(preorder, inorder, pos + 1, end);
    return node;
}

void levelorder(Node* root){
    if (root == NULL){
        return;
    }
    deque <Node*> q;
    q.emplace_back(root);
    q.push_back(NULL);   // ON POPING IF NULL COMES MEANS ONE LEVEL COMPLETED
    while (1){
        Node* a = q[0];
        q.pop_front();
        if (a == NULL){
            if (q.empty()){
                break;
            }
            q.push_back(NULL);
            continue;
        }
        cout << a -> data << " ";
        if (a -> left != NULL){
            q.emplace_back(a -> left);
        }
        if (a -> right != NULL){
            q.emplace_back(a -> right);
        }
    }
}

bool getPath(Node* root, int n, vector<int> &path) {
    if (root == NULL){
        return false;
    }
    path.push_back(root->data);
    if (root -> data == n){
        return true;
    }
    if (getPath(root->left, n, path) || getPath(root->right, n, path)){
        return true;
    }
    path.pop_back();
    return false;
}

// O(n) but requires three tree traversals plus extra spaces for path arrays
int LCA (Node* root, int n1, int n2){
    vector<int> path1, path2;
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() && pc < path2.size(); pc ++){
        if (path1[pc] != path2[pc]){
            break;
        }
    }
    // refer python
    return path1[pc - 1];
}

// O(n) single traversal of Binary Tree and without extra storage for path arrays 
// The idea is to traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both keys are present). If the root doesn’t match with any of the keys, we recur for the left and right subtree. The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. If both keys lie in the left subtree, then the left subtree has LCA also, otherwise, LCA lies in the right subtree.  
Node* LCA2 (Node* root, int n2, int n1){
    if (root == NULL) {
        return NULL;
    }
    if (root -> data == n1 || root -> data == n2){
        return root;
    }
    Node* leftLCA = LCA2(root -> left, n2, n1);
    Node* rightLCA = LCA2(root -> right, n2, n1);
    if (leftLCA && rightLCA){
        return root;
    }
    if (leftLCA) {
        return leftLCA;
    }
    return rightLCA;
}
// Note that the above method assumes that keys are present in Binary Tree. If one key is present and the other is absent, then it returns the present key as LCA (Ideally should have returned NULL). can check that by making 2 variables for each node and making them true false

// 1. Recursively flatten left & right sub-tree
// 2. Store left tail & right tail
// 3. Store right sub tree in temp & make left sub tree as right sub tree
// 4. Join right sub tree with left tail
void flatten (Node* root) {
    if (root == NULL || (root -> left == NULL && root -> right == NULL)){
        return;
    }
    if (root -> left != NULL){
        flatten(root->left);
        Node* temp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
        Node* tail = root -> right;
        while (tail -> right != NULL){
            tail = tail -> right;
        }
        tail -> right = temp;
    }
    flatten(root->right);
}

// Nodes at distance k
// Finding the first type of nodes (in sub-tree) is easy to implement. Just traverse subtrees rooted with the target node and decrement k in recursive call. When the k becomes 0, print the node currently being traversed
// For the output nodes not lying in the subtree with the target node as the root, we must go through all ancestors. For every ancestor, we find its distance from target node, let the distance be d, now we go to other subtree (if target was found in left subtree, then we go to right subtree and vice versa) of the ancestor and find all nodes at k-d distance from the ancestor

// Case 1
void d_in_subtree (Node* root, int k){
    if (root == NULL || k < 0) {
        return;
    }
    if (k == 0) {
        cout << root -> data << " ";
        return;
    }
    d_in_subtree(root -> left, k - 1);
    d_in_subtree(root -> right, k - 1);
}

// Case 2
int print_d_k (Node* root, Node* target, int k){
    if (root == NULL){
        return -1;
    }
    if (root == target){
        d_in_subtree(root, k);
        return 0;
    }
    int dl = print_d_k(root -> left, target, k);
    if (dl != -1){  // means target is in left subtree so ans at root or right subtree (on thinking that ans can be in left subtree as well it will be covered recursively when that point becomes root)
        if (dl + 1 == k){   // dl + 1 because dl is distance drom left subtree
            cout << root -> data << " ";   // ans in root
        }
        else{   // ans in right subtree
            d_in_subtree(root -> right, k - dl - 2);    // 2 is distance from left node to right node
        }
        return dl + 1;
    }
    int dr = print_d_k(root -> right, target, k);
    if (dr != -1){
        if (dr + 1 == k){
            cout << root -> data << " ";
        }
        else{
            d_in_subtree(root -> left, k - dr - 2);
        }
        return dr + 1;
    }
    return -1;
}

int main(){
    /*           1
            /        \  
           2          3  
         /  \        /  \
        4    5      6    7  */
    Node* root = new Node(1);
    root -> left = new Node(2);                 
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> right = new Node(7);
    root -> right -> left = new Node(6);
    // Traversals
    // preOrder(root);
    // inOrder(root);
    // postOrder(root);
    // levelorder(root);

    // Constructing by pre_in
    // int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    // int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    // Node* root2 = construct_by_pre_in(preorder, inorder, 0, 6);
    // inOrder(root2);
    // cout << LCA2(root, 4, 5)->data;
    // inOrder(root);
    // flatten(root);
    // inOrder(root);
    print_d_k(root, root -> left -> right, 2);
    return 0;
    // don/t forgot the method where you return the treenode as
    // root -> left = traverse(root -> left)
    // root -> right = traverse(root -> right)

    // can't emplace NULL, do push
}