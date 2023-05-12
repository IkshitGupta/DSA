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

int catalan (int n, int store []) {
    if (n <= 1){
        return 1;
    }
    if (store[n] != 0){
        return store[n];
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += catalan(i, store)*catalan(n - i - 1, store);
    }
    store[n] = ans;
    return ans;
}

vector<Node*> constructTress(int start, int end){
    vector<Node*> bsts;
    if (start > end){
        bsts.emplace_back(NULL);
        return bsts;
    }
    for (int i = start; i <= end; i++){
        vector<Node*> left = constructTress(start, i - 1);
        vector<Node*> right = constructTress(i + 1, end);
        for (int j = 0; j < left.size(); j++){
            Node* l = left[j];
            for (int k = 0; k < right.size(); k++){
                Node* r = right[k];
                Node* node = new Node(i);
                node -> left = l;
                node -> right = r;
                bsts.emplace_back(node);
            }
        }
    }
    return bsts;
}

int main(){
    int n = 4;
    int store[n + 1] = {};
    cout << catalan(n, store);
    return 0;
}