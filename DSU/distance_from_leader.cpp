// Refer Experience EDU
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
#define print(x) cout << x << endl
int mod = 1e9 + 7;

int n;
class DSU{
    vi size;
    public:
    vpi parent;
    DSU(){
        loop(i, n + 1){
            parent.push_back({i, 0});   // .S distance from parent i.e. difference in ans between parent and itself
        }
        size.resize(n + 1, 1);
    }

    pi find_set(int v) {
        if (v == parent[v].F)
            return parent[v];
        int l = parent[v].S;    // distance of it to its parent
        parent[v] = find_set(parent[v].F);  // this will contain distance of its parent to root
        parent[v].S += l;
        return parent[v];
    }

    void union_sets(int a, int b) {
        a = find_set(a).F;
        b = find_set(b).F;
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = {a, 1};
            size[a] += size[b];
            // Here only can update min of sets, max of sets, etc..
        }
    }

    void get(int a){
        // ans = val[find_set(a).F] + parent[a].S;
    }
};

int main(){
    n = 6;
    DSU ds;
    ds.union_sets(2, 3);
    ds.union_sets(5, 4);
    ds.union_sets(3, 4);
    ds.union_sets(1, 4);
    for(auto& i : ds.parent){
        cout << i.S << " ";
    }
    return 0;
}

// bipartite
// CLAIM: if the ends of the edge lie in the same connected component and have the same parity length to the leader, then adding this edge will produce a cycle of odd length, and the component will lose the bipartiteness property.

// void make_set(int v) {
//     parent[v] = make_pair(v, 0);
//     rank[v] = 0;
//     bipartite[v] = true;
// }

// pair<int, int> find_set(int v) {
//     if (v != parent[v].first) {
//         int parity = parent[v].second;
//         parent[v] = find_set(parent[v].first);
//         parent[v].second ^= parity;
//     }
//     return parent[v];
// }

// void add_edge(int a, int b) {
//     pair<int, int> pa = find_set(a);
//     a = pa.first;
//     int x = pa.second;

//     pair<int, int> pb = find_set(b);
//     b = pb.first;
//     int y = pb.second;

//     if (a == b) {
//         if (x == y)
//             bipartite[a] = false;
//     } else {
//         if (rank[a] < rank[b])
//             swap (a, b);
//         parent[b] = make_pair(a, x^y^1); // if it was distance it would be x + y + 1
//         bipartite[a] &= bipartite[b];
//         if (rank[a] == rank[b])
//             ++rank[a];
//     }
// }