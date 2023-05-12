#include <bits/stdc++.h>
using namespace std;

enum Color {red, black};    // red represents 0 and black 1, hover

struct Node {
    int data;
    bool color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = red;
    }
};

Node* insert (Node* root, Node* pt){
    if (root == NULL){
        return pt;
    }
    if (pt -> data < root -> data){
        root -> left = insert(root -> left, pt);
        root -> left -> parent = root;
    }
    else {
        root -> right = insert(root -> right, pt);
        root -> right -> parent = root;
    }
    return root;
}

Node* rotateLeft (Node* root, Node* pt){
    Node *pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != NULL){
        pt->right->parent = pt;
    }
    pt_right->parent = pt->parent;
    if (pt->parent == NULL){
        root = pt_right;
    }
    else if (pt == pt->parent->left){
        pt->parent->left = pt_right;
    }
    else{
        pt->parent->right = pt_right;
    }
    pt_right->left = pt;
    pt->parent = pt_right;
    return root;
}

Node* rotateRight (Node* root, Node* pt){
    Node *pt_left = pt->left;
    pt->left = pt_left->right;
    if (pt->left != NULL){
        pt->left->parent = pt;
    }
    pt_left->parent = pt->parent;
    if (pt->parent == NULL){
        root = pt_left;
    }
    else if (pt == pt->parent->left){
        pt->parent->left = pt_left;
    }
    else{
        pt->parent->right = pt_left;
    }
    pt_left->right = pt;
    pt->parent = pt_left;
    return root;
}

Node* fixViolations(Node* root, Node* pt){
    Node* parent_pt = NULL;
    Node* grand_parent_pt = NULL;
    while ((pt != root) && (pt -> color != black) && (pt -> parent -> color == red)){
        parent_pt = pt -> parent;
        grand_parent_pt = parent_pt -> parent;
        // CASE A Parent of pt is left child of Grand-parent of pt
        if (parent_pt == grand_parent_pt -> left){
            Node* uncle_pt = grand_parent_pt -> right;
            // CASE 1 Uncle also red so only recolouring required
            if (uncle_pt != NULL && uncle_pt -> color == red){
                grand_parent_pt -> color = red;
                parent_pt -> color = black;
                uncle_pt -> color = black;
                pt = grand_parent_pt;
            }
            else {
                // CASE 2 pt is right child of its parent Left-rotation required
                // lr
                if (pt == parent_pt -> right){
                    root = rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Case : 3 pt is left child of its parent
                // ll
                root = rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        // Case : B Parent of pt is right child of Grand-parent of pt
        else{
            Node *uncle_pt = grand_parent_pt->left;
            // Case : 1 The uncle of pt is also red Only Recoloring required
            if (uncle_pt != NULL && uncle_pt->color == red){
                grand_parent_pt->color = red;
                parent_pt->color = black;
                uncle_pt->color = black;
                pt = grand_parent_pt;
            }
            else{
                // Case : 2 pt is left child of its parent
                // rl
                if (pt == parent_pt->left){
                    root = rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Case : 3 pt is right child of its parent
                // rr
                root = rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root -> color = black;
    return root;
}

Node* insertRB (Node* root, int key){
    Node* pt = new Node(key);
    root = insert(root, pt);
    root = fixViolations(root, pt);
    return root;
}

void inOrder(struct Node* root){
    if (root == NULL) {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void levelorder(Node* root){
    if (root == NULL){
        return;
    }
    queue <Node*> q;
    q.push(root);
    q.push(NULL);   // ON POPING IF NULL COMES MEANS ONE LEVEL COMPLETED
    for (;;){
        Node* a = q.front();
        q.pop();
        if (a == NULL){
            if (q.empty()){
                break;
            }
            q.push(NULL);
            continue;
        }
        cout << a -> data << " ";
        if (a -> left != NULL){
            q.push(a -> left);
        }
        if (a -> right != NULL){
            q.push(a -> right);
        }
    }
}

int main(){
    Node* root = NULL;
    root = insertRB(root, 1);
    root = insertRB(root, 6);
    root = insertRB(root, 5);
    root = insertRB(root, 4);
    root = insertRB(root, 3);
    root = insertRB(root, 2);
    root = insertRB(root, 7);
    inOrder(root);
    cout << endl;
    levelorder(root);
    return 0;
}