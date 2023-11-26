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

Node* insertBST (Node* root, int val){
    if (root == NULL){
        return new Node(val);
    }
    if (val < root -> data){
        root -> left = insertBST(root -> left, val);;
    }
    else {
        root -> right = insertBST(root -> right, val);
    }
    return root;
}

void inOrder(Node* root){
    if (root == NULL) {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

int inorderSucc(Node* root){  // minimum value in right subtree
    Node* curr = root;
    while (curr && curr -> left != NULL){
        curr = curr -> left;
    }
    return curr -> data;
}

Node* deleteBST (Node* root, int key){
    if (root == NULL){
        return NULL;
    }
    if (key < root -> data){
        root -> left = deleteBST(root -> left, key);
    }
    else if (key > root -> data){
        root -> right = deleteBST(root -> right, key);
    }
    else {
        // CASE 1 & 2
        if (root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        else if (root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // CASE 3
        int temp = inorderSucc(root -> right);
        root -> data = temp;    // Copy the inorder successor's content to this node
        root -> right = deleteBST(root->right, temp);    // Delete the inorder successor
    }
    return root;
}

bool isBST (Node* root, Node* mi = NULL, Node* ma = NULL){
    if (root == NULL){
        return true;
    }
    if (mi != NULL && root -> data <= mi -> data){
        return false;
    }
    if (ma != NULL && root -> data >= ma -> data){
        return false;
    }
    bool lv = isBST(root -> left, mi, root);
    bool rv = isBST(root -> right, root, ma);
    return lv && rv;    // M2 by inorder (O(2n)) // here O(n)
}

Node* constructBST_by_pre (vector<int> preorder, int* idx, int mi = 0, int ma = 1001){
    if (*idx >= preorder.size()) {
        return NULL;
    }
    int key = preorder[*idx];
    Node* root = NULL;
    if (key > mi && key < ma){
        root = new Node(key);
        *idx += 1;  // important, better to give as reference, should not give static as in multiple test case value won't reset
        root -> left = constructBST_by_pre(preorder, idx, mi, key);
        root -> right = constructBST_by_pre(preorder, idx, key, ma);
        // return a|b;  // check if can be formed
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 1);
    root = insertBST(root, 3);
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 7);
    // inOrder(root);
    return 0;
}