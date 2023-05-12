// template for dfs & cycle finding
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
#define mx(a) prev(a.end())

int n;
template<typename T>
class Graph{
    int cycle_start, cycle_end;
    vector<vi> adjl;
    public:
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(T x, T y, bool check = 1) {
        adjl[x].eb(y);
        if (check) adjl[y].eb(x);
    }

    void dfs_tree(T v, T p){
        for(auto& u : adjl[v]){
            if (u != p){
                dfs_tree(u, v);
            }
        }
    }

    void dfs_help2(T v, vi& color){
        color[v] = 1;
        for(auto& u : adjl[v]){
            if (color[u] == 0) {
                // parent[u] = v;
                dfs_help2(u, color);
                // distance[v] = max(distance[u] + 1, distance[v]); // max distance to any leaf node
                // child[v] += child[u] + 1;
            }
        }
        color[v] = 2;
    }

    void dfs2(){
        vi color(n + 1);
        // vi parent(n + 1, -1);
        // vi child(n + 1);
        fr(i, 1, n + 1){
            if (color[i] == 0){
                dfs_help2(i, color);
                // component++;
            }
        }
        // for trees
        // dfs_tree(1, 0);
    }

    bool dfs_help(T v, vi& color, vi& time_in, vi& time_out, int& timer, vi& parent){
        time_in[v] = timer++;
        color[v] = 1;
        for(auto u : adjl[v]){
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs_help(u, color, time_in, time_out, timer, parent)) return true;
            }
            else if (color[u] == 1) {   // if undirected also check v != parent[u]
                cycle_end = v;
                cycle_start = u;
                return true;
            }
        }
        color[v] = 2;
        time_out[v] = timer++;
        return false;
    }

    void dfs(){
        vi color(n + 1);
        vi time_in(n + 1);
        vi time_out(n + 1);
        vi parent(n + 1, -1);
        int timer = 0;
        cycle_start = -1;
        fr(i, 1, n + 1){
            if (color[i] == 0){
                if (dfs_help(i, color, time_in, time_out, timer, parent)) break;
                // component++;
            }
        }
        if (cycle_start == -1){
            cout << -1 << endl;
            return;
        }
        deque<int> path;
        path.emplace_front(cycle_start);
        while(cycle_end != cycle_start){
            path.emplace_front(cycle_end);
            cycle_end = parent[cycle_end];
        }
        path.emplace_front(cycle_start);
        cout << len(path) << endl;
        for(auto& i : path){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    Graph<str> g;   // str is template argument
    g.add_edge("Amritsar", "Jaipur");
    g.add_edge("Delhi", "Jaipur");
    g.add_edge("Mumbai", "Jaipur");
    g.add_edge("Mumbai", "Bhopal");
    g.add_edge("Mumbai", "Bengalore");
    g.add_edge("Delhi", "Agra");
    g.add_edge("Delhi", "Bhopal");
    g.add_edge("Amritsar", "Delhi");
    g.add_edge("Andaman", "Nicobar");
    g.add_edge("I", "K");
    g.dfs();

    return 0;
}

// O(V + E) dfs from source
// but we do dfs from every node (i.e. checking each vertex) hence O(V(V + E))

// bool, if else, break, parent not needed if not checking cycle

                                //  Types of edges
// If v is not visited:

// Tree Edge - if v is visited for the first time and u is currently being visited then (u, v) is called tree edge. These edges form a DFS tree and hence the name tree edges.

// If v is visited before u:

// Back edges - If v is an ancestor of u, then the edge (u, v) is a back edge. v is an ancestor exactly if we already entered v, but not exited it yet. Back edges complete a cycle as there is a path from ancestor v to descendant u (in the recursion of DFS) and an edge from descendant u to ancestor v (back edge), thus a cycle is formed.

// Forward Edges - If v is a descendant of u, then edge (u, v) is a forward edge. In other words, if we already visited and exited v and entry[u] < entry[v] then the edge (u, v) forms a forward edge.

// Cross Edges: if v is neither an ancestor or descendant of u, then edge (u, v) is a cross edge. In other words, if we already visited and exited v and entry[u] > entry[v] then (u, v) is a cross edge.

// Note: Forward edges and cross edges only exist in directed graphs.
                                //

// if want order as lexicographic store vertices in set
// i ancestor of j if entry[i] < entry[j] and exit[i] > exit[j]

// can find if path between start as source from 1 vertex and if end comes in dfs then true
// not everytime adjl formation necessary as its fixed for all i.e. har edge up, right ja sakti hai

// in connected components also include single points i.e. not connected to any

// in the undirected version, if a vertex v gets colored black, it will never be visited again by the DFS. This is because we already explored all connected edges of v when we first visited it. The connected component containing v (after removing the edge between v and its parent) must be a tree, if the DFS has completed processing v without finding a cycle. So we don't even need to distinguish between 1 and 2 state. we can turn the int vector visited into a boolean vector but then have to consider parent case individually.