#include <bits/stdc++.h>
#define endl '\n'
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

Node* balance_root(Node* root, int key){
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

Node* insertAVL (Node* root, int key){
    if (root == NULL){
        return new Node(key);
    }
    if (key < root -> data){
        if (root -> left == NULL){
            cout << root -> data << " ";
        }
        root -> left = insertAVL(root -> left, key);
    }
    else {
        if (root -> right == NULL){
            cout << root -> data << " ";
        }
        root -> right = insertAVL(root -> right, key);
    }
    return balance_root(root, key);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, val;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++){
        cin >> val;
        root = insertAVL(root, val);
    }
    return 0;
}