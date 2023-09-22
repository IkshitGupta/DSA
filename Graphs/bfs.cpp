// use CSES Labryinth for maze template
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
    public:
    map<T, vector<T>> adjl;
    // vvi adjl;
    Graph(){
        adjl.resize(n + 1);
    }
    void add_edge(T x, T y, bool check = 1) {
        adjl[x].eb(y);
        if (check) adjl[y].eb(x);
    }

    void bfs(T s){
        map<T, bool> visited;   // Don't use for int
        deque<T> que;
        map<T, T> parent;
        // vi parent(n + 1);
        map<T, int> distance;
        // vi distance(n + 1, INT_MAX);
        // distance[s] = 0;
        que.eb(s);
        visited[s] = 1;
        parent[s] = -1;
        // parent[s] = {-1, -1};
        while(!que.empty()){
            T v = que[0];
            que.pop_front();
            for(auto u : adjl[v]){
                // if(distance[u] > distance[v] + 1){
                if(!visited[u]){
                    visited[u] = 1;
                    que.eb(u);
                    distance[u] = distance[v] + 1;
                    parent[u] = v;
                }
            }
        }
        // if path required take another input t
        // T t = 5;
        // if (!visited[t]){
            // cout << "-1\n";
            // return;
        // }
        // deque<T> path;
        // T x = t;
        // while(x != parent[s]){
        //     path.emplace_front(x);
        //     x = parent[x];
        // }
        // for(auto i : path){
        //     cout << i << " ";
        // }
    }
};

template<typename T> void shortest_even_len(Graph<T>& g, T src){
    Graph<pair<T, bool>> gg;
    // for(auto& i : g.adjl){
    fr(i, 1, n + 1){
        for(auto& j : g.adjl[i]){
            gg.add_edge({i, 0}, {j, 1}, 0);
            gg.add_edge({i, 1}, {j, 0}, 0);
        }
    }
    gg.bfs({src, 0});

}

int main(){
    // Graph<int> g;
    // g.add_edge(0, 1);
    // g.add_edge(2, 1);
    // g.add_edge(0, 4);
    // g.add_edge(4, 3);
    // g.add_edge(4, 2);
    // g.add_edge(5, 3);
    // g.add_edge(3, 2);
    // g.bfs(1);
    Graph<int> g;
    n = 5;
    // g.start();
    g.add_edge(1, 2, 1);
    g.add_edge(3, 2, 1);
    g.add_edge(3, 5, 1);
    g.add_edge(2, 5, 1);
    g.add_edge(4, 5, 1);
    g.add_edge(4, 3, 1);
    shortest_even_len(g, 1);
    return 0;
}

// the path found by breadth first search to any node is the shortest path to that node in undirected graph
// directed, undirected doesn't matter
// connected components can be find similarly
// when distance needed can optimize space by removing visited and initializing distance to inf
// Finding the shortest cycle in a directed unweighted graph: Start a breadth-first search from each vertex. As soon as we try to go from the current vertex back to the source vertex, we have found the shortest cycle containing the source vertex. At this point we can stop the BFS, and start a new BFS from the next vertex.
// find edges that lie on any shortest path from a to b
// run two breadth first searches: one from a and one from b. Let da[] be the array containing shortest distances obtained from the first BFS (from a) and db[] be the array containing shortest distances obtained from the second BFS from b. Now for every edge (u, v) it is easy to check whether that edge lies on any shortest path between a and b: the criterion is the condition da[u] + db[v] + 1 = da[b]
// for checking if the vertex lies on any shortest path da[v] + db[v] = da[b]

// Find the shortest path of even or odd length from a source vertex s to a target vertex t in an unweighted graph: For this, we must construct an auxiliary graph, whose vertices are the state (v, c), where v - the current node, c = 0 or c = 1 - the current parity. Any edge (a, b) of the original graph in this new graph will turn into two edges ({a, 0}, {b, 1}) and ({a, 1}, {b, 0}). After that we run a BFS to find the shortest path from the starting vertex {s, 0}

// if min distance required from any of the multiple points put all of them in queue and rather than visited check if distance less than prev
// eg. if said 5 monsters to find for each cell min time for any of the monster to reach, rather than bfs for all just put all of them in one queue