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
typedef vector<bool> vb;
typedef vector<str> vs;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<char, int> mci;
typedef map<int, int> mii;
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
#define mset0(x) memset(x, 0, sizeof(x))
#define mset1(x) memset(x, -1, sizeof(x))
#define len(x) x.size()
#define ump unordered_map
#define sum(x) accumulate(x.begin(), x.end(), 0)
#define out(x) cout << x << endl
#define outl(x) cout << x << " "
int mod = 1e9 + 7;

int n;
class DSU{
    vi parent;
    vi size;
    public:
    DSU(){
        loop(i, n + 1){
            parent.eb(i);
        }
        size.resize(n + 1, 1);
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Graph{
    vector<pair<int, pi>> edges;    // {weight : edge}

    public:
    void add_edge(int a, int b, int w){
        edges.push_back({w, {a, b}});
    }

    void kruskal(){
        ll total = 0;
        vector<pair<int, pi>> mst;
        sort(all(edges));
        DSU ds;
        for (auto& i : edges){
            int w = i.F;
            int u = i.S.F;
            int v = i.S.S;
            if (ds.find_set(u) != ds.find_set(v)){
                total += w;
                mst.eb(i);
                ds.union_sets(u, v);
            }
        }
        // if (cnt != n - 1){
        //     out(-1);
        //     return;
        // }
        for(auto& i : mst){
            cout << i.S.F << " " << i.S.S << endl;
        }
        out(total);
    }
};

int main(){
    n = 9;
    Graph g;
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    g.kruskal();
    n = 7;
    Graph h;
    h.add_edge(1, 6, 10);
    h.add_edge(5, 6, 25);
    h.add_edge(5, 7, 24);
    h.add_edge(2, 7, 14);
    h.add_edge(2, 1, 28);
    h.add_edge(2, 3, 16);
    h.add_edge(4, 3, 12);
    h.add_edge(5, 4, 22);
    h.add_edge(7, 4, 18);
    // h.kruskal();
    return 0;
}

// O(mlogn)
// Kruskal's algorithm initially places all the nodes of the original graph isolated from each other, to form a forest of single node trees, and then gradually merges these trees, combining at each iteration any two of all the trees with some edge of the original graph. Before the execution of the algorithm, all edges are sorted by weight (in non-decreasing order). Then begins the process of unification: pick all edges from the first to the last (in sorted order), and if the ends of the currently picked edge belong to different subtrees, these subtrees are combined, and the edge is added to the answer. After iterating through all the edges, all the vertices will belong to the same sub-tree, and we will get the answer.