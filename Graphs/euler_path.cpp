#ifndef LOCAL
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,lzcnt,popcnt")
#endif
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef string str;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<str> vs;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<char, int> mci;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define fr(i, a, b) for(int i = a; i < b; i++)
#define frr(i, b, a) for(int i = b; i > a; i--)
#define loop(i, n) for(int i = 0; i < n; i++)
#define eb emplace_back
#define pb pop_back
#define mset0(x) memset(x, 0, sizeof(x))
#define mset1(x) memset(x, -1, sizeof(x))
#define len(x) int(x.size())
#define sum(x) accumulate(x.begin(), x.end(), 0)
#define sumll(x) accumulate(x.begin(), x.end(), 0LL)
#define out(x) cout << x << endl
#define outl(x) cout << x << " "
#define out2(x, y) cout << x << " " << y << endl
#define printpair(x) cout << x.F << " " << x.S << endl
#define out3(x, y, z) cout << x << " " << y << " " << z << endl
#define out4(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl
#define lisin(x, n) loop(xx, n){cin >> x[xx];}
#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)
#define ump unordered_map
int mod = 1e9 + 7;
void yes(bool a = 1){
    if (a == 1) out("YES");
    else out("NO");}

template<typename T1, typename T2> void printmap(map<T1, T2>& m){
    cout << "{";
    for(auto& i : m){cout << i.F << " : " << i.S << ", ";}
    cout << "}\n";}

template<typename T1, typename T2> void printmaplist(map<T1, T2>& mv){
    cout << "{";
    for (auto& i : mv){
        cout << i.F << " : " << "[";
        for (auto& j : i.S){cout << j << ", ";}
        cout << "], ";}
    cout << "}\n";}

template<typename T> void printlist(vector<T>& v){
    for (T& i : v){cout << i << " ";}
    cout << endl;}

template<typename T> void print_vov(vector<vector<T>>& v){
    for(auto& i : v) printlist(i);}

template<typename T1, typename T2> void print_vpi(vector<pair<T1, T2>>& v){
    for(auto& i : v) printpair(i);
}

int n, m;

class Graph{
    vvi adjl;

    public:
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(int x, int y){
        adjl[x].eb(y);
    }

    pi get_start_end(vi& in_degree, vi& out_degree){
        pi ans = {-1, -1};
        int start_pos = -1; // a possible starting position
        fr(i, 1, n + 1){
            if (out_degree[i] > 0) start_pos = i;   // a possiblility, to avoide singleton
            if (abs(out_degree[i] - in_degree[i]) > 1){
                return {-1, -1};
            }
            if (out_degree[i] - in_degree[i] == 1){
                if (ans.F == -1) ans.F = i;
                else return {-1, -1};
            }
            else if (in_degree[i] - out_degree[i] == 1){
                if (ans.S == -1) ans.S = i;
                else return {-1, -1};
            }
        }
        if (ans.F == -1 && ans.S == -1){
            ans = {start_pos, start_pos};   // eulerian circuit hence any can be start end
        }
        if (ans.F == -1 || ans.S == -1){
            ans = {-1, -1}; // wrong
        }
        return ans;
    }

    void dfs_help_directed(int v, vi& out_degree, vi& path){
        while (out_degree[v] > 0){
            int u = adjl[v][--out_degree[v]];
            dfs_help_directed(u, out_degree, path);
        }
        path.eb(v);
    }

    void euler_directed(){
        vi in_degree(n + 1);
        vi out_degree(n + 1);
        fr(v, 1, n + 1){
            out_degree[v] = len(adjl[v]);
            for(auto& u : adjl[v]){
                in_degree[u]++;
            }
        }

        pi extreme = get_start_end(in_degree, out_degree);
        if (extreme.F == -1 && extreme.S == -1) {
            out(-1);
            return;
        }

        vi path;
        dfs_help_directed(extreme.F, out_degree, path);
        if (len(path) != m + 1){    // m = number of edges
            out(-1);    // multiple components
            return;
        }
        reverse(all(path));
        printlist(path);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 7;
    Graph g;
    m = 12;
    int x, y;
    loop(i, m){
        cin >> x >> y;
        g.add_edge(x + 1, y + 1);
    }
    g.euler_directed();

    return 0;
}

// A Eulerian path is a path in a graph that passes through all of its edges exactly once. A Eulerian cycle is a Eulerian path that is a cycle
// so should be a connected component, ignoring singleton vertices

// to find the Eulerian path in an undirected multigraph with loops

// A multigraph is a type of graph that allows multiple edges between the same pair of nodes
// A loop is an edge that connects a node to itself

// An Eulerian cycle exists if and only if the degrees of all vertices are even.
// An Eulerian path exists if and only if the number of vertices with odd degrees is two (or zero, in the case of the existence of a Eulerian cycle)

// For directed graph, refer https://youtu.be/8MpoO2zA2l4?si=8y_sk70SmMt7bdUh