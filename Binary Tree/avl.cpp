#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    int height;
    struct Node* left;
    struct Node* right;
    Node (int val) {
        data = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int ht (Node* root){
    if (root == NULL){
        return 0;
    }
    return root -> height;
}

Node* ll (Node* root){
    Node* x = root -> left;
    Node* temp = x -> right;
    x -> right = root;
    root -> left = temp;
    root -> height = max(ht(root -> left), ht(root -> right)) + 1;
    x -> height = max(ht(x -> left), ht(x -> right)) + 1;
    return x;
}

Node* rr (Node* root){
    Node* x = root -> right;
    Node* temp = x -> left;
    x -> left = root;
    root -> right = temp;
    root -> height = max(ht(root -> left), ht(root -> right)) + 1;
    x -> height = max(ht(x -> left), ht(x -> right)) + 1;
    return x;
}

int balanceFactor (Node* root){
    if (root == NULL){
        return 0;
    }
    return ht(root -> left) - ht(root -> right);
}

Node* insertAVL (Node* root, int key){
    if (root == NULL){
        return new Node(key);
    }
    if (key < root -> data){
        root -> left = insertAVL(root -> left, key);
    }
    else {
        root -> right = insertAVL(root -> right, key);
    }
    root -> height = max(ht(root -> left), ht(root -> right)) + 1;
    int balance = balanceFactor(root);
    // ll
    if (balance > 1 && key < root -> left -> data){
        return ll(root);
    }
    // rr
    if (balance < -1 && key > root -> right -> data){
        return rr(root);
    }
    // lr
    if (balance > 1 && key > root -> left -> data){
        root -> left = rr(root -> left);
        return ll(root);
    }
    // rl
    if (balance < -1 && key < root -> right -> data){
        root -> right = ll(root -> right);
        return rr(root);
    }
    return root;
}

void preOrder(Node* root){
    if (root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while (curr && curr -> left != NULL){
        curr = curr -> left;
    }
    return curr;
}

// same as in BST
Node* deleteAVL (Node* root, int key){
    if (root == NULL){
        return NULL;
    }
    if (key < root -> data){
        root -> left = deleteAVL(root -> left, key);
    }
    else if (key > root -> data){
        root -> right = deleteAVL(root -> right, key);
    }
    else {
        // CASE 1 & 2
        if (root -> left == NULL){
            Node* temp = root -> right;
            // free(root);  // not working in leetcode
            delete root;
            return temp;
        }
        else if (root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // CASE 3
        Node* temp = inorderSucc(root -> right);
        root -> data = temp -> data;    // Copy the inorder successor's content to this node
        root -> right = deleteAVL(root->right, temp ->data);    // Delete the inorder successor
    }

    if (root == NULL){
        return root;
    }
    root -> height = max(ht(root -> left), ht(root -> right)) + 1;
    int balance = balanceFactor(root);
    // ll
    if (balance > 1 && balanceFactor(root -> left) >= 0){
        return ll(root);
    }
    // rr
    if (balance < -1 && balanceFactor(root -> right) <= 0){
        return rr(root);
    }
    // lr
    if (balance > 1 && balanceFactor(root -> left) < 0){
        root -> left = rr(root -> left);
        return ll(root);
    }
    // rl
    if (balance < -1 && balanceFactor(root -> right) > 0){
        root -> right = ll(root -> right);
        return rr(root);
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insertAVL(root, 9);
    root = insertAVL(root, 5);
    root = insertAVL(root, 10);
    root = insertAVL(root, 0);
    root = insertAVL(root, 6);
    root = insertAVL(root, 11);
    root = insertAVL(root, -1);
    root = insertAVL(root, 1);
    root = insertAVL(root, 2);
    preOrder(root);
    cout << endl;
    root = deleteAVL(root, 10);
    preOrder(root);

    return 0;
}