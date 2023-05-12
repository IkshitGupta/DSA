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

template<typename T> void printlist(vector<T>& v){
    for (T& i : v){cout << i << " ";}
    cout << endl;
}

map<int, str> dic;
int n;
template<typename T>
class Graph{
    // map<T, vector<T>> adjl;
    vector<vi> adjl;
    public:
    Graph(){
        adjl.resize(n + 1);
    }

    void add_edge(T x, T y) {
        adjl[x].eb(y);
    }

    void kahn(){
        vi inDegree(n + 1);
        // map<T, int> inDegree;
        for(auto& i : adjl){
            for(auto& j : i){
                inDegree[j]++;
            }
        }
        deque<T> que;
        fr(i, 1, n + 1){    // if 1 to n + 1
            if (inDegree[i] == 0) que.eb(i);
        }

        vector<T> ans;

        while(!que.empty()){
            T v = que[0];
            ans.eb(v);
            que.pop_front();
            for(auto& u : adjl[v]){
                inDegree[u]--;
                if (inDegree[u] == 0) que.eb(u);
            }
        }

        if(len(ans) != n){
            cout << -1 << endl;
            return;
        }
        printlist(ans);
        for(auto& i : ans){
            cout << dic[i] << " ";
        }
    }

};

int main(){
    n = 9;
    Graph<int> g;
    // g.start();
    dic = {{1, "English"}, {2, "Programming"}, {3, "HTML"}, {4, "Maths"}, {5, "CSS"}, {6, "JS"}, {7, "Python"}, {8, "Web"}, {9, "Java"}};
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(4, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 5);
    g.add_edge(5, 6);
    g.add_edge(2, 7);
    g.add_edge(7, 8);
    g.add_edge(9, 8);
    g.add_edge(6, 8);
    g.add_edge(2, 9);
    g.add_edge(2, 6);
    g.kahn();
    return 0;
}