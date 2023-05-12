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
// Dense Graph
// O(n^2)
// for every not yet selected vertex we will store the minimum edge to an already selected vertex.
class Graph1{
    public:
    vvi adjm;   // if given as input then just pass as reference

    Graph1(){
        adjm.resize(n + 1, vi(n + 1, INT_MAX));
    }

    void add_edge(int a, int b, int w){
        adjm[a][b] = w;
        adjm[b][a] = w;
    }

    void prim(){
        ll total = 0;
        vb selected(n + 1);
        vpi min_e(n + 1, {INT_MAX, -1});    // stores the edge with minimal weight to an selected vertex for each not-yet-selected vertex {weight, to}
        min_e[1].F = 0; // starting with arbitary
        fr(i, 1, n + 1){
            // choosinf minimum edge
            int v = -1;
            fr(j, 1, n + 1){
                if (!selected[j] && (v == -1 || min_e[j].F < min_e[v].F)){  // if v = -1 then first selected, if even minimum then it found then that selected
                    v = j;
                }
            }

            if (min_e[v].F == INT_MAX){
                out(-1);
                return;
            }

            selected[v] = 1;
            total += min_e[v].F;
            if (min_e[v].S != -1){
                cout << v << " " << min_e[v].S << endl; // edge taken
            }

            // as this new edge added to selected updating for the rest of edges the minimum weight
            fr(j, 1, n + 1){
                if (adjm[v][j] < min_e[j].F){
                    min_e[j] = {adjm[v][j], v};
                }
            }
        }
        out(total);
    }
};

// sparse graph
// O(mlogn)
class Graph{
    vector<vpi> adjl;
    public:
    
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(int x, int y, int w) {
        adjl[x].push_back({y, w});
        adjl[y].push_back({x, w});
    }

    void prim(){
        ll total = 0;
        vb selected(n + 1);
        vpi min_e(n + 1, {INT_MAX, -1});    // stores the edge with minimal weight to an selected vertex for each not-yet-selected vertex {weight, to}
        min_e[1].F = 0; // starting with arbitary
        set<pi> s;  // filled with all not yet selected vertices in the order of increasing weights
        s.insert({0, 1});
        fr(i, 1, n + 1){
            if(s.empty()){
                out(-1);
                return;
            }

            auto x = s.begin();
            int v = (*x).S;
            selected[v] = 1;
            total += (*x).F;
            s.erase(x);

            if (min_e[v].S != -1){
                cout << v << " " << min_e[v].S << endl; // edge taken
            }

            for(auto& to : adjl[v]){
                int u = to.F;
                int w = to.S;
                if (!selected[u] && w < min_e[u].F){
                    s.erase({min_e[u].F, u});
                    min_e[u] = {w, v};
                    s.insert({w, u});
                }
            }
        }
        out(total);
    }
};

int main(){
    n = 9;
    Graph1 g;
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
    // g.prim();
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
    h.prim();
    return 0;
}

// The minimum spanning tree is built gradually by adding edges one at a time. At first the spanning tree consists only of a single vertex (chosen arbitrarily). Then the minimum weight edge outgoing from this vertex is selected and added to the spanning tree. After that the spanning tree already consists of two vertices. Now select and add the edge with the minimum weight that has one end in an already selected vertex (i.e. a vertex that is already part of the spanning tree), and the other end in an unselected vertex. 
// If the graph was originally not connected, then there doesn't exist a spanning tree, so the number of selected edges will be less than n - 1
// O(mlogn)
// in each iteration we do few logn operation & total logn operation = m, hence time complexity is O(mlogn)