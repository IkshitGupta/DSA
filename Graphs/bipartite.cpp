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
    public:
    // map<T, vector<T>> adjl;
    vector<vi> adjl;
    Graph(){
        adjl.resize(n + 1);
    }
    void add_edge(T x, T y, bool check = 1) {
        adjl[x].eb(y);
        if (check) adjl[y].eb(x);
    }

    bool bfs(){
        // map<T, int> color;
        vi color(n + 1, -1);
        deque<T> que;
        fr(s, 1, n + 1){    // iterate in vertices
            if(color[s] != -1) continue;
            que.eb(s);
            color[s] = 1;
            while(!que.empty()){
                T v = que[0];
                que.pop_front();
                for(auto u : adjl[v]){
                    if(color[u] == -1){
                        color[u] = color[v]^1;
                        que.eb(u);
                    }
                    else if (color[u] == color[v]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){

    return 0;
}

// A bipartite graph is a graph whose vertices can be divided into two disjoint sets so that every edge connects two vertices from different sets (i.e. there are no edges which connect vertices from the same set)
// a graph is bipartite if and only if all its cycles have even length
// a graph is bipartite if and only if it is two-colorable.
// graph with no edges is also Bipartite.