#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Info {
    int size;
    int ma;
    int mi;
    int ans;
    bool isBST;
};
// Using struct to return multiple things
Info largestBST (Node* root){
    if (root == NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root -> left == NULL && root -> right == NULL){
        return {1, root -> data, root -> data, 1, true};
    }
    Info l = largestBST(root -> left);
    Info r = largestBST(root -> right);
    Info curr;
    curr.size = 1 + l.size + r.size;
    if (l.isBST && r.isBST && l.ma < root -> data && r.mi > root -> data){
        curr.mi = min({l.mi, r.mi, root -> data});
        curr.ma = max({r.ma, l.ma, root -> data});
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(l.ans, r.ans);
    curr.isBST = false;
    return curr;
}

int main(){
    Node* root = new Node(15);
    root -> left = new Node(20);
    root -> left -> left = new Node(5);
    root -> right = new Node(30);
    cout << largestBST(root).ans;
    return 0;
}