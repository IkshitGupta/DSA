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
    ll s = 0;
    ll op1 = LLONG_MAX;
    ll op2 = 0;
    void combine(const node& left, const node& right){
        s = left.s + right.s;
    }
};

// say 10 assign then 5 add, we can't say 15 add as, say child is 7, it should become 15, but due to this it will become 22
class SegTree{
    vector<node> t;

    // propagate in all
    void propogate(int v, int tl, int tr){
        if (tl == tr) return;   // leaf node
        int tm = (tl + tr)/2;
        if (t[v].op1 != LLONG_MAX){
            t[2*v].op1 = t[v].op1;
            t[2*v].op2 = 0;
            t[2*v + 1].op1 = t[v].op1;
            t[2*v + 1].op2 = 0;
            t[2*v].s = t[v].op1*(tm + 1 - tl);
            t[2*v + 1].s = t[v].op1*(tr - tm);
        }
        t[2*v].op2 += t[v].op2;
        t[2*v + 1].op2 += t[v].op2;
        t[2*v].s += t[v].op2*(tm + 1 - tl);
        t[2*v + 1].s += t[v].op2*(tr - tm);
        t[v].op1 = LLONG_MAX;
        t[v].op2 = 0;
    }
    public:
    SegTree(){
        t.resize(4*n);
    }

    void update1(int v, int tl, int tr, int l, int r, ll val){
        if (tl > r || tr < l) return;
        propogate(v, tl, tr);
        if(tl >= l && tr <= r){
            t[v].op1 = val;
            t[v].op2 = 0;
            t[v].s = val*(tr + 1 - tl);
        }
        else{
            int tm = (tl + tr)/2;
            update1(v*2, tl, tm, l, r, val);
            update1(v*2 + 1, tm + 1, tr, l, r, val);
            t[v].combine(t[2*v], t[2*v + 1]);
        }
    }

    void update1(int l, int r, ll val){
        update1(1, 0, n - 1, l, r - 1, val);
    }

    void update2(int v, int tl, int tr, int l, int r, ll val){
        if (tl > r || tr < l) return;
        propogate(v, tl, tr);
        if(tl >= l && tr <= r){
            t[v].op2 += val;
            t[v].op1 = LLONG_MAX;
            t[v].s += val*(tr + 1 - tl);
        }
        else{
            int tm = (tl + tr)/2;
            update2(v*2, tl, tm, l, r, val);
            update2(v*2 + 1, tm + 1, tr, l, r, val);
            t[v].combine(t[2*v], t[2*v + 1]);
        }
    }

    void update2(int l, int r, ll val){
        update2(1, 0, n - 1, l, r - 1, val);
    }

    node query(int v, int tl, int tr, int l, int r){
        if (tl > r || tr < l){
            node x;
            return x;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        propogate(v, tl, tr);
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
    cin >>  n >> m;
    SegTree st;
    int q, a, b, c;
    loop(i, m){
        cin >> q;
        if (q == 1){
            cin >> a >> b >> c;
            st.update1(a, b, c);
        }
        else if (q == 2){
            cin >> a >> b >> c;
            st.update2(a, b, c);
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