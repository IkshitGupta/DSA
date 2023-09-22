// Everything for DAG
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

template<typename T> void printlist(vector<T>& v){
    for (T& i : v){cout << i << " ";}
    cout << endl;
}

int n;
template<typename T>
class Graph{
    // map<T, vector<pair<T, int>>> adjl;
    bool check = 0;
    vector<vpi> adjl;
    public:
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(T x, T y, int w = 1) {
        adjl[x].push_back({y, w});
    }

    // void dfs_help(T v, map<T, int>& color, deque<T>& ans){
    void dfs_help(T v, vi& color, deque<T>& ans){
        color[v] = 1;
        for(auto& u : adjl[v]){
            if (color[u.F] == 0) {
                dfs_help(u.F, color, ans);
            }
            else if (color[u.F] == 1) {
                check = 1;
                return;
            }
        }
        ans.emplace_front(v);
        color[v] = 2;
    }

    void topological(deque<T>& ans){
        // map<T, int> color;  // color 0, if we haven't visited them, color 1 if we visited them, and color 2, if we already exited the vertex.
        vi color(n + 1);
        fr(i, 0, n){    // iterate in all vertices
            if (color[i] == 0){
                dfs_help(i, color, ans);
            }
        }
        if (check){
            cout << -1 << endl;
            return;
        }
        for(auto& i : ans){
            cout << i << " ";
        }
        cout << endl;
    }

    void shortest_path(T s){
        deque<T> ans;
        topological(ans);
        // map<T, int> distance;   // for all vertices set to LLong_MAX
        vl distance(n + 1, LLONG_MAX);
        distance[s] = 0;
        while(!ans.empty()){
            T v = ans[0];
            ans.pop_front();
            if (distance[v] == LLONG_MAX) continue;
            for(auto& j : adjl[v]){
                T u = j.F;
                int w = j.S;
                distance[u] = min(distance[u], distance[v] + w);
            }
        }
        printlist(distance);
    }

    // another way is to negate all weights and find shortest path
    void longest_path(T s){
        deque<T> ans;
        topological(ans);
        // map<T, int> distance;   // for all vertices set to LLong_MAX
        vl distance(n + 1, LLONG_MIN);
        distance[s] = 0;
        vi parent(n + 1);
        parent[s] = -1;
        for(auto& v : ans){
            if (distance[v] == LLONG_MIN) continue;
            for(auto& j : adjl[v]){
                T u = j.F;
                int w = j.S;
                if (distance[v] + w > distance[u]){
                    distance[u] = distance[v] + w;
                    parent[u] = v;
                }
            }
        }
        if (distance[n] == LLONG_MIN){
            cout << -1 << endl;
            return;
        }
        deque<T> path;
        T x = n;
        while(x != -1){
            path.emplace_front(x);
            x = parent[x];
        }
        cout << len(path) << endl;
        for(auto& i : path){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    // Graph<str> g;
    // g.add_edge("English", "Programming");
    // g.add_edge("English", "HTML");
    // g.add_edge("Maths", "Programming");
    // g.add_edge("Programming", "HTML");
    // g.add_edge("HTML", "CSS");
    // g.add_edge("CSS", "JS");
    // g.add_edge("Programming", "Python");
    // g.add_edge("Python", "Web");
    // g.add_edge("Java", "Web");
    // g.add_edge("JS", "Web");
    // g.add_edge("Programming", "Java");
    // g.add_edge("Programming", "JS");
    // g.topological();
    Graph<int> g;
    n = 6;
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 5, 1);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);
    // g.shortest_path(1);
    g.longest_path(1);

    // g.add_edge(0, 1, 2);
    // g.add_edge(0, 4, 1);
    // g.add_edge(1, 2, 3);
    // g.add_edge(4, 2, 2);
    // g.add_edge(2, 3, 6);
    // g.add_edge(4, 5, 4);
    // g.add_edge(5, 3, 1);
    // g.shortest_path(0);
    // g.longest_path(0);
    return 0;
}

// ordering of nodes such that before performing a task all its pre-requisites are performed
// # if there is a edge from vertex u to vertex v, then vertex u comes before vertex v in ordering
// # Work only in DAG
// # O(V + E)

// Application in calculating shortest path for DAG in O(E + V)
// edges on adding will still remain DAG
// all possible left to right combinations in topological sort

// if we want all the dependencies to be finished before 1, then can run dfs from 1 and add the elements when visited[i] = 2