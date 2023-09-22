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

template<typename T>
class SparseTable{
    vector<vector<T>> store;
    int k, L;
    vi lg;
    public:
    SparseTable(vector<T>& a){
        L = len(a);

        // precomuting log2
        lg.resize(L + 1);
        lg[1] = 0;  // check L != 0
        fr(i, 2, L + 1){
            lg[i] = lg[i/2] + 1;
        }

        // precomputing
        k = lg[L];
        store.resize(k + 1, vector<T>(L));
        loop(i, L){
            store[0][i] = a[i];
        }
        fr(i, 1, k + 1){
            for(int j = 0; j + (1 << i) - 1 < L; j++){
                store[i][j] = min(store[i - 1][j], store[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T getmin(int l, int r){ // 0 based  // both included
        int x = lg[r + 1 - l];
        return min(store[x][l], store[x][r - (1 << x) + 1]);
    }
};

class Graph1{
    vvi adjl;
    vi time_in;

    public:
    Graph1(){
        time_in.resize(n + 1);
        fill(all(time_in), -1);
        adjl.resize(n + 1);
    }

    void add_edge(int x, int y){
        adjl[x].eb(y);
        adjl[y].eb(x);
    }

    void dfs_help(int v, vi& euler, vi& height, int& t){
        euler.eb(v);    // when entering
        time_in[v] = t++;
        for(auto& u : adjl[v]){
            if(time_in[u] == -1){
                height[u] = height[v] + 1;
                dfs_help(u, euler, height, t);
                euler.eb(v);    // coming back then going to another
                t++;
            }
        }
    }

    SparseTable<pi> pre_comp(){
        vi euler;
        vi height(n + 1);
        int t = 0;
        dfs_help(0, euler, height, t);
        vpi new_height;
        for(auto& i : euler){
            new_height.eb(height[i], i);
        }
        SparseTable<pi> st(new_height);
        return st;
    }

    int lca(int v1, int v2, SparseTable<pi>& st){
        int min_t = min(time_in[v1], time_in[v2]);
        int max_t = max(time_in[v1], time_in[v2]);
        return st.getmin(min_t, max_t).S;
    }
};

class Graph2{
    vector<vpi> adjl;
    vvi freq;
    vi parent;
    public :
    Graph2(){
        adjl.resize(n);
        freq = vvi(n, vi(27));
        parent.resize(n);
    }

    void add_edge(int x, int y, int w){
        adjl[x].eb(y, w);
        adjl[y].eb(x, w);
    }

    void dfs_help(int v, int p){
        parent[v] = p;
        for(auto& u : adjl[v]){
            if (u.F == p) continue;
            dfs_help(u.F, v);
            loop(i, 27){
                freq[v][i] += freq[u.F][i];
            }
            freq[v][u.S] += 1;
        }
    }

    void dfs(){
        dfs_help(0, -1);
        print_vov(freq);
    }

    int get_ans(int a, int b, int lca){
        vi new_freq(27);
        int p = max(parent[lca], 0);
        loop(i, 27){
            new_freq[i] = freq[lca][i] - freq[a][i] - freq[b][i];
        }
        int ma = 0;
        int s = 0;
        for(auto& i : new_freq){
            amax(ma, i);
            s += i;
        }
        return s - ma;
    }
};

vector<int> minOperationsQueries(int nn, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    n = nn;
    Graph1 g1;
    Graph2 g2;
    for(auto& i : edges){
        g1.add_edge(i[0], i[1]);
        g2.add_edge(i[0], i[1], i[2]);
    }
    SparseTable<pi> st = g1.pre_comp();
    g2.dfs();
    int q = len(queries);
    vi ans(q);
    loop(i, q){
        int lca = g1.lca(queries[i][0], queries[i][1], st);
        out(lca);
        ans[i] = g2.get_ans(queries[i][0], queries[i][1], lca);
    }
    return ans;
}

int main(){
    // int nn = 7;
    // vvi edges = {{0,1,1},{1,2,1},{2,3,1},{3,4,2},{4,5,2},{5,6,2}}; 
    // vvi queries = {{0,3},{3,6},{2,6},{0,6}};

    int nn = 8;
    vvi edges = {{1,2,6},{1,3,4},{2,4,6},{2,5,3},{3,6,6},{3,0,8},{7,0,2}};
    vvi queries = {{4,6},{0,4},{6,5},{7,4}};
    vi x = minOperationsQueries(nn, edges, queries);
    printlist(x);

    return 0;
}