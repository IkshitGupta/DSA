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
    // map<T, vector<pair<T, bool>>> adjl;
    vector<vector<pair<int, bool>>> adjl;
    public:
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(T x, T y, bool w) {
        adjl[x].push_back({y, w});
        adjl[y].push_back({x, w});
    }

    void bfs(T s){
        map<T, bool> visited;
        deque<T> que;
        map<T, int> distance;
        que.eb(s);
        visited[s] = 1;
        while(!que.empty()){
            T v = que[0];
            que.pop_front();
            for(auto& i : adjl[v]){
                T u = i.F;
                bool w = i.S;
                if(!visited[u]){
                    visited[u] = 1;
                    distance[u] = distance[v] + w;
                    if(w) que.eb(u);
                    else que.emplace_front(u);
                }
            }
        }
    }
};

int main(){
    n = 9;
    Graph<int> g;
    // g.start();
    g.add_edge(0, 1, 0);
    g.add_edge(0, 7, 1);
    g.add_edge(1, 7, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(2, 3, 0);
    g.add_edge(2, 5, 0);
    g.add_edge(2, 8, 1);
    g.add_edge(3, 4, 1);
    g.add_edge(3, 5, 1);
    g.add_edge(4, 5, 1);
    g.add_edge(5, 6, 1);
    g.add_edge(6, 7, 1);
    g.add_edge(7, 8, 1);
    g.bfs(0);
    return 0;
}

// O(E) 
// the path found by breadth first search to any node is the shortest path to that node in undirected graph
// directed, undirected doesn't matter
// connected components can be find similarly
// We can append new vertices at the beginning if the corresponding edge has weight 0, i.e. if d[u] = d[v], or at the end if the edge has weight 1, i.e. if d[u] = d[v] + 1