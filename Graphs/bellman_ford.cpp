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
    // map<T, vector<pair<T, int>>> adjl;
    vector<pair<pair<T, T>, int>> edges;
    vector<vpi> adjl;
    Graph(){
        adjl.resize(n + 1);
    }
    void add_edge(T x, T y, int w, bool check = 1) {
        adjl[x].push_back({y, w});
        if (check) adjl[y].push_back({x, w});
    }

    void add_edge2(T x, T y, int w, bool check = 1) {
        edges.push_back({{x, y}, w});
        if(check) edges.push_back({{y, x}, w});
    }

    void bellman(T s){
        // map<T, ll> d;
        // fr(i, 1, n + 1){
        //     d[i] = INT_MAX;
        // }
        // map<T, T> parent;
        vl d(n + 1, LLONG_MAX);
        d[s] = 0;
        vector<T> parent(n + 1);
        parent[s] = -1;
        int check;  // stores last modified
        loop(i, n){ // 1 extra if don't know cycle there
            check = -1;
            for(auto& j : edges){
                T v = j.F.F;
                T u = j.F.S;
                int w = j.S;
                if(d[v] == LLONG_MAX) continue;
                if(d[v] + w < d[u]){
                    d[u] = d[v] + w;
                    parent[u] = v;
                    check = u;
                }
            }
            if (check == -1) break;
        }
        if (check != -1){    // Negative cycle
            cout << -1 << endl;
            loop(i, n){
                check = parent[check];
            }
            deque<T> path;
            path.emplace_front(check);
            T x = parent[check];
            while(x != check){
                path.emplace_front(x);
                x = parent[x];
            }
            path.emplace_front(x);
            for(auto& i : path){
                cout << i << " ";
            }
            return;
            // All distance 0 if negative cycle asked from any source
        }
        T dest = n;
        if (d[dest] == LLONG_MAX){
            cout << -1 << endl;
            return;
        }
        cout << d[dest] << endl;
        deque<T> path;
        while(dest != parent[s]){
            path.emplace_front(dest);
            dest = parent[dest];
        }
        for(auto& i : path){
            cout << i << " ";
        }
    }

    void spfa(T s){
        // map<T, ll> d;
        // fr(i, 1, n + 1){
        //     d[i] = INT_MAX;
        // }
        // map<T, T> parent;
        // map<T, int> cnt;
        // vector<T, bool> inQue;
        vl d(n + 1, LLONG_MAX);
        d[s] = 0;
        vector<T> parent(n + 1);
        parent[s] = -1;
        vector<T> cnt(n + 1);
        vector<bool> inQue(n + 1);
        deque<T> que = {s};
        inQue[s] = 1;
        while(!que.empty()){
            T v = que[0];
            que.pop_front();
            inQue[v] = 0;
            for(auto& x : adjl[v]){
                T u = x.F;
                int w = x.S;
                if(d[v] + w < d[u]){
                    d[u] = d[v] + w;
                    parent[u] = v;
                    if(!inQue[u]){
                        que.eb(u);
                        inQue[u] = 1;
                        cnt[u]++;
                        if(cnt[u] >= n){ // Negative cycle
                            cout << -1 << endl;
                            return;
                        }
                    }
                }
            }
        }
    }

};

int main(){

    return 0;
}

// # The graph may contain negative weight edges. 
// # Dijkstra doesn’t work for Graphs with negative weights, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems.
// # But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra. 
// # In complete graph n(n - 1)//2 edges, Hence O(n^3)
// # Shortest Path
// # n vertices
// # for n - 1 times do relaxation i.e., check for a edge (u, v) dist[u] + cost(u, v) < dist[v]
// # no possible answer for negative cycle (sum of weights in cycle is negative), it keeps on reducing
// Unlike many other graph algorithms, for Bellman-Ford algorithm, it is more convenient to represent the graph using a single list of all edges
// after n - 1 phases, if we run algorithm for one more phase, and it performs at least one more relaxation, then the graph contains a negative weight cycle that is reachable from s; otherwise, such a cycle does not exist.

// The above implementation looks for a negative cycle reachable from some starting vertex s; however, the algorithm can be modified to just looking for any negative cycle in the graph. For this we need to put all the distances to zero and not infinity — as if we are looking for the shortest path from all vertices simultaneously; the validity of the detection of a negative cycle is not affected.

// it is sufficient to remember the last vertex check for which there was a relaxation in nth phase. This vertex will either lie in a negative weight cycle, or is reachable from it. To get the vertices that are guaranteed to lie in a negative cycle, starting from the vertex check, pass through to the predecessors n times. Hence we will get the vertex y, namely the vertex in the cycle earliest reachable from source.

// SPFA
// SPFA is a improvement of the Bellman-Ford algorithm which takes advantage of the fact that not all attempts at relaxation will work. The main idea is to create a queue containing only the vertices that were relaxed but that still could further relax their neighbors. And whenever you can relax some neighbor, you should put him in the queue. This algorithm can also be used to detect negative cycles as the Bellman-Ford.
// The worst case of this algorithm is equal to the O(mn) of the Bellman-Ford, but in practice it works much faster in O(n) on average.
// algorithm continues forever if there is a negative cycle. To avoid this, it is possible to create a counter that stores how many times a vertex has been relaxed and stop the algorithm as soon as some vertex got relaxed for the n-th time. Note, also there is no reason to put a vertex in the queue if it is already in.