#include <bits/stdc++.h>
#define mod 1000000007
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<int>> vvi;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
typedef string str;
#define fr(i, a, b) for(int i = a; i < b; i++)
#define frr(i, a, b) for(int i = b; i > a; i--)
#define loop(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mset(x, y) memset(x, y, sizeof(x))
#define len(x) x.size()
#define mp(a, b) make_pair(a, b)
#define ump unordered_map

int n;
class Graph{
    // map<int, vi> adjl;
    int time = 0;
    vector<vi> adjl;
    public:
    Graph(){
        adjl.resize(n + 1);
    }
    void add_edge(int x, int y) {
        adjl[x].eb(y);
        adjl[y].eb(x);
    }

    void dfs_help(int n, vector<bool>& visited, vi& discovery, vi& low, int& parent, vector<bool>& isAp){
        int children = 0;
        visited[n] = true;
        discovery[n] = time;
        low[n] = time;
        time++;
        for (auto v : adjl[n]){
            if (!visited[v]){   // the edge is part of DFS tree;
                children++;
                dfs_help(v, visited, discovery, low, n, isAp);
                low[n] = min(low[n], low[v]);
                if (parent != -1 && low[v] >= discovery[n]){    // n is not root and satisfy condition
                    isAp[n] = true;
                }
                // for bridges remove parent != -1 and bottom else if condition
                // if (low[v] > discovery[n]){
                //     bridges.push_back({v, n});
                // }
            }
            else if (v != parent){  // already visited, hence backedge
                low[n] = min(low[n], discovery[v]);
            }
        }
        if (parent == -1 && children > 1){
            isAp[n] = true;
        }
    }

    void ap(){
        vector<bool> visited(n + 1);
        vi discovery(n + 1);
        vi low(n + 1);
        vector<bool> isAp(n + 1);
        int parent = -1;
        fr(i, 0, n){
            if (!visited[i]){
                dfs_help(i, visited, discovery, low, parent, isAp);
            }
        }
        fr(i, 0, n){
            if (isAp[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 5;
    Graph g;
    // g.start();
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);
    g.ap();
    
    n = 4;
    Graph h;
    // h.start();
    h.add_edge(1, 0);
    h.add_edge(3, 2);
    h.add_edge(2, 1);
    h.ap();

    n = 7;
    Graph p;
    // p.start();
    p.add_edge(0, 1);
    p.add_edge(1, 2);
    p.add_edge(2, 0);
    p.add_edge(1, 3);
    p.add_edge(1, 4);
    p.add_edge(1, 6);
    p.add_edge(3, 5);
    p.add_edge(4, 5);
    p.ap();

    return 0;
}

// A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it (and edges through it) disconnects the graph. 
// Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network into 2 or more components. They are useful for designing reliable networks. 
// For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.

// By DFS, a vertex u is articulation point if one of the following two conditions is true.
// 1) u is root of DFS tree and it has at least two children. 
// 2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.

// For every node u, we need to find out the earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with u. So we maintain an additional array low[]

// tin[v] denote entry time for node v.
// low[v] = min(tin[v], tin[p], low[to])
// tin[p] for all p for which (v, p) is a back edge
// low[to] for all to for which (v, to) is a tree edge
// baically these all are v and vertices connected to v

// Now, there is a back edge from vertex v or one of its descendants to one of its ancestors if and only if vertex v has a child to for which low[to] < tin[v].
// Equality if connected to itself, will not help as that edge will also be removed
// Thus, the vertex v in the DFS tree is an articulation point if and only if low[to] >= tin[v] (i.e.; no back edge hence break into two different components).

// Time Complexity O(V + E)

// for bridges
// A bridge is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph)
// The current edge (v, to) is a bridge if and only if none of the vertices to and its descendants in the DFS traversal tree has a back-edge to vertex v or any of its ancestors.

// If a graph has no articulation point then it is Biconnected
// to find biconnected components maintain stack when ap found pop all