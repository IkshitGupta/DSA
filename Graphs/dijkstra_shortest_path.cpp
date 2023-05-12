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
template<typename T1, typename T2> void printmap(map<T1, T2>& m){
    cout << "{";
    for(auto& i : m){cout << i.F << " : " << i.S << ", ";}
    cout << "}\n";}
    
int n;  // vertices
template<typename T>
class Graph{
    public:
    // map<T, vector<pair<T, int>>> adjl;
    vector<vpi> adjl;
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(T x, T y, int w, bool check = 1) {
        adjl[x].push_back({y, w});
        if (check) adjl[y].push_back({x, w});
    }

    // sparse graph with set
    void dijkstra2(T s){
        set<pair<ll, T>> q;
        q.insert({0, s});
        vector<ll> d(n + 1, LLONG_MAX);
        // map<T, int> d;
        // fr(i, 1, n + 1){
        //     d[i] = INT_MAX;
        // }
        d[s] = 0;
        // map<T, T> parent;
        vector<T> parent(n + 1);
        parent[s] = -1;
        while(!q.empty()){
            T v = (*q.begin()).S;
            q.erase(q.begin());
            for(auto& to : adjl[v]){
                T u = to.F;
                int w = to.S;
                if (w + d[v] < d[u]){
                    q.erase({d[u], u});
                    d[u] = w + d[v];
                    q.insert({d[u], u});
                    parent[u] = v;
                }
            }
        }
        printlist(d);
        // T dest = n; // take another input dest
        // if(d[dest] == LLONG_MAX){
        //     cout << "-1\n";
        //     return;
        // }
        // deque<T> path;
        // T x = dest;
        // while(x != parent[s]){
        //     path.emplace_front(x);
        //     x = parent[x];
        // }
        // for(auto i : path){
        //     cout << i << " ";
        // }
    }

    // dense graph
    void dijkstra1(T s){
        vector<T> d(n + 1, INT_MAX);
        // map<T, int> d;
        // fr(i, 1, n + 1){
        //     d[i] = INT_MAX;
        // }
        d[s] = 0;
        // map<T, bool> marked;
        vector<T> marked(n + 1);
        // map<T, T> parent;
        vector<T> parent(n + 1);
        parent[s] = -1;
        loop(i, n){ // n iterations
            T v = -1;
            // for(auto& j : d){
            //     if(!marked[j.F] && (v == "?" || d[j.F] < d[v])){
            //         v = j.F;
            //     }
            // }
            // fr(j, 1, n + 1){   // if numbered 1 to n
            loop(j, n){ // if numbered 0 to n - 1
                if(!marked[j] && (v == -1 || d[j] < d[v])){
                    v = j;
                }
            }
            if(d[v] == INT_MAX){
                break;
            }
            marked[v] = 1;
            for(auto& to : adjl[v]){
                T u = to.F;
                int w = to.S;
                if (w + d[v] < d[u]){
                    d[u] = w + d[v];
                    parent[u] = v;
                }
            }
        }
        printlist(d);
        // T dest = "Jaipur"; // take another input dest
        // if(d[dest] == INT_MAX){
        //     cout << "-1\n";
        //     return;
        // }
        // deque<T> path;
        // T x = dest;
        // while(x != parent[s]){
        //     path.emplace_front(x);
        //     x = parent[x];
        // }
        // for(auto i : path){
        //     cout << i << " ";
        // }
    }

    void dijkstra3(T s){    // sparse with heap
        priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> q;
        q.push({0, s});
        vector<int> d(n + 1, INT_MAX);
        // map<T, int> d;
        // fr(i, 1, n + 1){
        //     d[i] = INT_MAX;
        // }
        d[s] = 0;
        // map<T, T> parent;
        vector<T> parent(n + 1);
        parent[s] = -1;
        while(!q.empty()){
            T v = q.top().S;
            int d_v = q.top().F;
            q.pop();
            if(d_v != d[v]){
                continue;
            }
            for(auto& to : adjl[v]){
                T u = to.F;
                int w = to.S;
                if (w + d[v] < d[u]){
                    d[u] = w + d[v];
                    q.push({d[u], u});
                    parent[u] = v;
                }
            }
        }
        printlist(d);
        // T dest = n; // take another input dest
        // if(d[dest] == INT_MAX){
        //     cout << "-1\n";
        //     return;
        // }
        // deque<T> path;
        // T x = dest;
        // while(x != parent[s]){
        //     path.emplace_front(x);
        //     x = parent[x];
        // }
        // for(auto i : path){
        //     cout << i << " ";
        // }
    }
};

int main(){
    // Graph<str> g;
    // g.add_edge("Amritsar", "Jaipur", 4);
    // g.add_edge("Delhi", "Jaipur", 2);
    // g.add_edge("Mumbai", "Jaipur", 8);
    // g.add_edge("Mumbai", "Bhopal", 3);
    // g.add_edge("Delhi", "Agra", 1);
    // g.add_edge("Agra", "Bhopal", 2);
    // g.add_edge("Amritsar", "Delhi", 1);
    // // g.dijkstra1("Amritsar");
    // g.dijkstra2("Amritsar");
    // g.dijkstra3("Amritsar");
    n = 9;
    Graph<int> g;
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
    g.dijkstra1(0);
    g.dijkstra2(0);
    g.dijkstra3(0);
    return 0;
}

// positive weights
// shortest path from s to all
// d[] for each v current shortest path from s to v, initially infinity
// marked[] initially all unmarked
// runs for n iterations, each time a vertex v is chosen as which has least d[v]
// it is marked, and all edges u from v are considered and d[u] = min(d[v], d[u] + w(u, v))
// iteration for this edge ends
// CLAIM : the found d after n iterations are the shortest
// Hence, After any vertex v becomes marked, the current distance to it is the shortest, and will no longer change

// two case possible edges(m), vertices(n)
// searching for minimum d n time in O(n^2) and m times relaxtion, so total O(n^2 + m)
// searching for minimum d n time in O(nlogn) and m times relaxtion, but now updating also take logn time, so total O(nlogn + mlogn)

// for dense graph edges = vertices^2 approx
// case 1 better
// for sparse graph case 2 better

// can be further reduced using fibonaci heap as it updates in O(1), total O(nlogn + m), but very complex and high constant factors
// don't need to maintain visited in second case as queue already keeps only those whose iteration required

// if we use heap than there will be multiple elements with same elements in the heap, will consume more memory but will be a little faster than of set