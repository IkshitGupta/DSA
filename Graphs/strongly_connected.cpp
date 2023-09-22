#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<str> vs;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<char, int> mci;
typedef map<int, int> mii;
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define fr(i, a, b) for(int i = a; i < b; i++)
#define frr(i, b, a) for(int i = b; i > a; i--)
#define loop(i, n) for(int i = 0; i < n; i++)
#define eb emplace_back
#define mset0(x) memset(x, 0, sizeof(x))
#define mset1(x) memset(x, -1, sizeof(x))
#define len(x) x.size()
#define ump unordered_map
#define sum(x) accumulate(x.begin(), x.end(), 0)
int mod = 1e9 + 7;

template<typename T> void printlist(vector<T>& v){
    for (T& i : v){cout << i << " ";}
    cout << endl;
}

int n;
template<typename T>
class Graph{
    // map<T, vector<T>> adjl;
    // map<T, vector<T>> adjlr;
    // map<int, vi> adjs;
    // for int
    vvi adjl;
    vvi adjlr;
    vvi adjs;
    public:
    Graph(){
        adjl.resize(n + 1);
        adjlr.resize(n + 1);
        adjs.resize(n + 1);
    }

    void add_edge(T x, T y) {
        adjl[x].eb(y);
        adjlr[y].eb(x);
    }

    // void dfs1(T v, map<T, int>& color, deque<T>& ans){
    void dfs1(T v, vector<bool>& color, deque<T>& ans){
        color[v] = 1;
        for(auto u : adjl[v]){
            if (color[u] == 0) {
                dfs1(u, color, ans);
            }
        }
        ans.emplace_front(v);
    }

    void dfs2(T v, vector<bool>& color, vector<T>& component){
        color[v] = 1;
        component.eb(v);
        for(auto u : adjlr[v]){
            if (color[u] == 0) {
                dfs2(u, color, component);
            }
        }
    }


    void strongly(){
        // map<T, int> color;
        vector<bool> color(n + 1);
        deque<T> ans;
        fr(i, 1, n + 1){    // iterate in all vertices
            if (color[i] == 0){
                dfs1(i, color, ans);
            }
        }
        fill(all(color), 0);
        vector<T> component;
        vi roots(n + 1);    // indicates the root node for the SCC to which the node belongs
        vi root_nodes;  // list of all root nodes (one per component) in the condensation graph.
        for(auto& i : ans){
            if(color[i] == 0){
                dfs2(i, color, component);
                printlist(component);
                int root = component[0];    // root of each component as the first node in its list. This node will represent its entire SCC in the condensation graph. 
                for(auto& u : component){
                    roots[u] = root;
                }
                root_nodes.eb(root);
                component = {};
            }
        }
        // which strongly connected components are connected to each other
        // building condensation graph
        fr(v, 1, n + 1){
            int root_v = roots[v];
            for(auto u : adjl[v]) {
                int root_u = roots[u];
                if (root_u != root_v) adjs[root_v].eb(root_u);
            }
        }
    }
};

int main(){
    n = 3;
    Graph<int> g;
    // g.add_edge(1, 0);
    // g.add_edge(0, 2);
    // g.add_edge(2, 1);
    // g.add_edge(0, 3);
    // g.add_edge(3, 4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    // g.add_edge(0, 1);
    g.strongly();
    return 0;
}

// https://youtu.be/i6jRvjlsuC4S
// Strong Connectivity applies only to directed graphs. A directed graph is strongly connected if there is a directed path from any vertex to every other vertex. 
// Similar to connected components, a directed graph can be broken down into Strongly Connected Components.
// Brute:   O(V^3)
// first the strongly connected component including node 1 is found. Then, if node 2 is not included in the strongly connected component of node 1, similar process can be used for node 2
// Let there be a list which contains all nodes, these nodes will be deleted one by one once it is sure that the particular node does not belong to the strongly connected component of node v
// it can be checked if there is a directed path from v to u by a single DFS, and if there is a directed path from u to v, again by a single DFS. If not, u can be deleted from the list.
// At end the list has the following property: every element can reach v, and v can reach every element via a directed path. But the elements of this list may or may not form a strongly connected component, because it is not confirmed that there is a path from other vertices in the list excluding v to the all other vertices of the list excluding v. So to confirm a similar process is done on the next element of the list.
// Now similar process can be done for other v if they are not included in some other strongly connected component. 

// Kosaraju's Algorithm
// Sort all vertices by exit time (kind of topological sort but in directed graph not in DAG)
// reverse the graph
// again do dfs by poping out elements from kinda top sort
// all the comonents achieved will be strongly connected components
// O(n + m)

// condensation graph is always acyclic

// A strong orientation of an undirected graph is an assignment of a direction to each edge that makes it a strongly connected graph
// bridge in a graph, then graph cannot be made strongly connected
// In a bridgless connected graph, we can remove any DFS tree edge and still be able to go from below the edge to above the edge by using a path that contains at least one back edge.
// hence, from any vertex we can go to the root of the DFS tree. Also, from the root of the DFS tree we can visit any vertex we choose
// to strongly orient a bridgeless connected graph, run a DFS on it and let the DFS tree edges point away from the DFS root and all other edges from the descendant to the ancestor in the DFS tree
// can run algorithmm in a bridge graph also
// total SCC = total components initially + total bridges

// 2-SAT
// say we have an assignment, set x, y, z such that overall true
// (x v y) ^ (!y v z) ^ (!z v !x) ^ (!y v x)
// !x -> y  not x implies y
// !y -> x  not y implies x
// if x is false, then y must be true
// Total edges -> number of brackets*2

// we check for contradiction i.e. if x = 0 then x should not be 1
// x should not imply not x
// so for each variable there should not be a path to its complement, i.e. pair should not be in the same strongly connected components

// In the graph, we get strongly connected components and now the graph also acyclic
// Property for (u, v)
// edge u -> v
// edge !u <- !v
// we can say for two strongly connected components A and B, in condensation graph,
// edge A -> B
// edge !B <- !A

// we always get strongly connected components in topological order
// for each pair A, !A in topological order assign left as 0 and right as 1

// refer Giant_Pizza CSES for template

// Converting to conjunctive normal form
// a xor b = (a v b) ^ (!a v !b)
// (a ^ !b) v (!a ^ b)
// (a v (!a ^ b))^(!b v (!a ^ b))
// (1^(a ^ b))^((!b v !a)^1)
// (a ^ b)^(!b v !a)

// !(a xor b) = (!a v b) ^ (a v !b)
// !((a ^ !b) v (!a ^ b))
// !(a ^ !b) ^ !(!a ^ b)
// (!a v b) ^ (a v !b)  