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
    ll op = 0;  // stores operations, initially all 0
    ll s = 0;
    void combine(const node& left, const node& right){
        s = min(left.s, right.s);
    }
};

class SegTree{
    ll NO_OPERATION = LLONG_MAX - 1;
    vector<node> t;

    ll operation(ll a, ll b){   // for non commutative
        if (b == NO_OPERATION) return a;    // no change in child a
        return b;   // apply the operation to child
    }   // for commutative same function will work, as b will always be no_operation, as propagation done already

    void propogate(int v, int tl, int tr){
        if (tl == tr) return;   // leaf node
        t[2*v].op = operation(t[2*v].op, t[v].op);
        t[2*v].s = operation(t[2*v].s, t[v].op);
        t[2*v + 1].op = operation(t[2*v + 1].op, t[v].op);
        t[2*v + 1].s = operation(t[2*v + 1].s, t[v].op);
        t[v].op = NO_OPERATION;
    }
    public:
    SegTree(){
        t.resize(4*n);
    }

    void update(int v, int tl, int tr, int l, int r, int val){
        propogate(v, tl, tr);
        if (tl > r || tr < l) return;
        if(tl >= l && tr <= r){
            t[v].op = operation(t[v].op, val);
            t[v].s = operation(t[v].s, val);
        }
        else{
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, r, val);
            update(v*2 + 1, tm + 1, tr, l, r, val);
            t[v].combine(t[2*v], t[2*v + 1]);
        }
    }

    void update(int l, int r, int val){
        update(1, 0, n - 1, l, r - 1, val);
    }

    node query(int v, int tl, int tr, int l, int r){
        propogate(v, tl, tr);
        if (tl > r || tr < l){
            node x;
            x.s = LLONG_MAX;
            return x;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        int tm = (tl + tr)/2;
        node x;
        x.combine(query(v*2, tl, tm, l, r), query(v*2 + 1, tm + 1, tr, l, r));
        return x;
    }

    ll query(int l, int r){
        return query(1, 0, n - 1, l, r - 1).s;
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
            cin >> a >> b>> c;
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