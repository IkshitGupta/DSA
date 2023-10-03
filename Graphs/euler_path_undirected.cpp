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
    vector<msi> adjl;

    public:
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(int x, int y){
        adjl[x].insert(y);
        adjl[y].insert(x);
    }

    void dfs_help(int v, vi& path){
        while(!adjl[v].empty()){
            int u = *adjl[v].begin();
            adjl[u].erase(adjl[u].find(v));
            adjl[v].erase(adjl[v].find(u));
            dfs_help(u, path);
        }
        path.eb(v);
    }

    int get_start(vi& deg){
        int start = -1;
        vi odd;
        fr(i, 1, n + 1){
            if (deg[i] > 0) start = i;
            if (deg[i]&1){
                odd.eb(i);
            }
        }
        if (odd.empty()) return start;
        if (len(odd) != 2) {
            return -1;
        }
        return odd[0];
    }

    void euler(){
        vi deg(n + 1);
        fr(v, 1, n + 1){
            for(auto& u : adjl[v]){
                deg[u]++;
            }
        }

        int start = get_start(deg);
        if (start == -1){
            out(-1);
            return;
        }

        vi path;
        dfs_help(start, path);
        if (len(path) != m + 1){
            out(-1);
            return;
        }
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
    g.euler();

    return 0;
}


