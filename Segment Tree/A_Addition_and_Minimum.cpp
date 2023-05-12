#ifndef LOCAL
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,lzcnt,popcnt")
#endif
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
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
#define out2(x, y) cout << x << " " << y << " " << endl
#define out3(x, y, z) cout << x << " " << y << " " << z << " " << endl
#define out4(x, y, z, w) cout << x << " " << y << " " << z << " " << w << " " << endl
int mod = 1e9 + 7;

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
    for (T i : v){cout << i << " ";}
    cout << endl;
}
int n;
struct node{
    ll op = 0;
    ll mi = 0;
    void combine(const node& left, const node& right, ll operations){
        mi = min(left.mi, right.mi) + operations;   // also need to add remaining operations
    }
};

class SegTree{
    vector<node> t;
    ll operation(ll a, ll b){   // for associative & commutitive operations like max, min, gcd, lcm, sum; not work for assignment
        return a + b;
    }
    public:
    SegTree(){
        t.resize(4*n);
    }

    void update(int v, int tl, int tr, int l, int r, int val){
        if (tl > r || tr < l) return;
        if(tl >= l && tr <= r){
            t[v].op = operation(t[v].op, val);
            t[v].mi += val; // as for its leaf node say 3, 4, in both val added so in mi also val added
        }
        else{
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, r, val);
            update(v*2 + 1, tm + 1, tr, l, r, val);
            t[v].combine(t[2*v], t[2*v + 1], t[v].op);
        }
    }

    void update(int l, int r, int val){
        update(1, 0, n - 1, l, r - 1, val);
    }

    node query(int v, int tl, int tr, int l, int r){
        if (tl > r || tr < l) {
            node x;
            x.mi = LLONG_MAX;
            return x;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        int tm = (tl + tr)/2;
        node x;
        x.combine(query(v*2, tl, tm, l, r), query(v*2 + 1, tm + 1, tr, l, r), t[v].op);
        return x;
    }

    ll query(int l, int r){
        return query(1, 0, n - 1, l, r - 1).mi;
    }
};

void solve(){
    int m;
    cin >> n >> m;
    SegTree st;
    int q, a, b, c;
    loop(i, m){
        cin >> q;
        if (q == 1){
            cin >> a >> b >> c;
            st.update(a, b, c);
        }
        else{
            cin >> a >> b;
            out(st.query(a, b));
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t > 0){
        solve();
        t--;
    }

    return 0;
}