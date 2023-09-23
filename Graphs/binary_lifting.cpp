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
#define lisin(x, n) loop(i, n){cin >> x[i];}
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

int n;
class BinaryLifting{    // get kth ancestor
    vvi up;
    vvi adjl;
    vi depth;
    int LOG;
    public:

    void add_edge(int x, int y){
        adjl[x].eb(y);
        adjl[y].eb(x);
    }

    void dfs_tree(int v, int p){
        for(auto& u : adjl[v]){
            if (u == p) continue;
            depth[u] = depth[v] + 1;
            up[u][0] = v;
            fr(j, 1, LOG){
                up[u][j] = up[ up[u][j - 1] ][j - 1];
            }
            dfs_tree(u, v);
        }
    }

    BinaryLifting(vi& parent){
        LOG = 0;
        while ((1 << LOG) <= n){
            LOG++;
        }

        up = vvi(n, vi(LOG));
        adjl.resize(n);
        depth.resize(n);

        // adding all edges
        int root;
        fr(i, 0, n){
            if (parent[i] == -1){
                root = i;
                continue;
            }
            add_edge(i, parent[i]);
        }

        dfs_tree(root, root);   // let parent[root] be root
    }

    int getKanc(int u, int k){
        if (depth[u] < k){
            return -1;
        }
        loop(j, LOG){
            if ((k & (1 << j))){
                u = up[u][j];
            }
        }
        return u;
    }

    int get_lca(int a, int b){
        if (depth[a] < depth[b]){
            swap(a, b);
        }
        int k = depth[a] - depth[b];
        a = getKanc(a, k);  // both now at same depth
        if (a == b) return a;

        frr(j, LOG - 1, -1){    // getting as close to lca as possible
            if (up[a][j] != up[b][j]){
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }

    int distance(int a, int b){
        int lca = get_lca(a, b);
        return depth[a] + depth[b] - 2*depth[lca];
    }

};

int main(){

    return 0;
}

// think by diameter, distance between nodes, distance from lca etc...
// Eg.. do the given nodes fill fall on a valid path
// can check by taking two points as diameter and then checking whether the next ones fall inside or fill make new diameter
// so this also calculates maximum possible diameter from given nodes
// max radius/centroid will be ceil(diameter, 2)


// depth[a] + depth[b] - 2*depth[lca];
// can calculate other things in similar way
// example calculating sum between nodes then calculate sum till each node in dfs then apply same operation for sum between nodes