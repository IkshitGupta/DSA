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
int mod = 1e9 + 7;

template<typename T> void printlist(vector<T>& v){
    for (T& i : v){cout << i << " ";}
    cout << endl;
}

int n;
class Graph{
    public:
    vvl adjm;

    void add_edge(int a, int b, ll c, bool check = 1){
        adjm[a][b] = min(adjm[a][b], c);
        if (check) adjm[b][a] = adjm[a][b];
    }

    void floyd(){
        fr(i, 1, n + 1){
            adjm[i][i] = 0;
        }
        vector<vector<int>> parent (n + 1, vector<int>(n + 1, -1));
        fr(i, 1, n + 1){
            fr(j, 1, n + 1){
                if (adjm[i][j] == LLONG_MAX) parent[i][j] = -1;
                else parent[i][j] = j;
            }
        }
        fr(i, 1, n + 1){    // intermediate
            fr(j, 1, n + 1){
                fr(k, 1, n + 1){    // j to k
                    if(adjm[j][i] < LLONG_MAX && adjm[i][k] < LLONG_MAX){
                        if (adjm[i][i] < 0){    // If Negative Cycle may be present
                            adjm[j][k] = LLONG_MIN;
                            parent[j][k] = -1;
                        }
                        else{
                            ll x = adjm[j][i] + adjm[i][k];
                            if (x < adjm[j][k]){
                                adjm[j][k] = x;
                                parent[j][k] = parent[j][i];
                            }
                        }
                    }
                }
            }
        }
        for(auto& i : adjm){
            printlist(i);
        }

        int u = 2, v = 0;
        if (adjm[u][v] == LLONG_MAX || adjm[u][v] == LLONG_MIN) {
            cout << -1 << endl;
            return;
        }
        vi path = {u};
        while(u != v){
            u = parent[u][v];
            path.eb(u);
        }
        printlist(path);
    }
};

int main(){
    int m, a, b;
    ll c;   // should be
    cin >> n >> m;
    vector<vector<ll>> adjm (n + 1, vector<ll>(n + 1, LLONG_MAX));
    Graph g;
    g.adjm = adjm;
    loop(i, m){
        cin >> a >> b >> c;
        g.add_edge(a, b, c, 0);
    }
    g.floyd();
    return 0;
}

// # O(n^3)
// # ALL PAIR SHORTEST PATH PROBLEM
// # The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph
// # can do by dijkstra for all but not optimum
// # as all pairs required better to use adjacency matrix
// # in the matrix, we upate by taking each vertex as a intermediate i.e. f(3, 2) taking intermediate 4 means going fron 3 to 2 via 4 = f(3, 4) + f(4, 2)
// # row and column containing the intermediate vertex is not needed to be changed
// # directed graph
// # dp
// # Floyd Warshall works for negative edge but not for negative cycle
// # This algorithm works for both the directed and undirected weighted graphs

// # we just have to check the nodes distance from itself and if it comes out to be negative, we will detect the required negative cycle.
// # A negative cycle is one in which the overall sum of the cycle comes negative. Hence, for shortest path algorithms an undirected graph cannot have any negative weight edges

// # when vertices 0 to v - 1
// # can change range (1, v + 1) if vertices 1 to v