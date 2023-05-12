#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fr(i, a, b) for(int i = a; i < b; i++)

int n;
template<typename T>
class Graph{
    vector<vi> adjl;
    public:
    Graph(){
        adjl.resize(n + 1);
    }

    void change_root(int old_root, int new_root){
        // Update data structures as if `new_root` was being removed as a child from `old_root`
        // Update data structures as if `old_root` was being added as a child to `new_root`
    }

    void reroot(int v, int p, vi& ans){  // v is current root, p parent
        // Data structures now reflect the tree as if `v` were the root
        for(auto& u : adjl[v]){
            if (u == p) continue;
            change_root(v, u);
            reroot(u, v, ans);
            // ans[u] = // store answer for the new root
            change_root(u, v);    // restore root
        }
    }

    void dfs2(){
        // Initialize data structures with respect to the initial root `root`
        vi ans(n + 1);
        if (!adjl[1].empty()){
            // ans[1] = // update answer of root
            reroot(1, 0, ans);
        }
    }
};

// Refer CSES Tree_Distances_I.cpp