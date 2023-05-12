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

class SegTree{
    public:
    vpi t;
    SegTree(){
        t.resize(4*n);
    }

    pi combine(pi a, pi b){
        if(a.F < b.F) return a;
        else if(a.F > b.F) return b;
        return {a.F, a.S + b.S};
    }

    void build(vi& a, int v = 1, int tl = 0, int tr = n - 1){
        if(tl == tr) t[v] = {a[tl], 1};
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);
            t[v] = combine(t[v*2], t[v*2 + 1]);
        }
    }

    pi query(int v, int tl, int tr, int l, int r){
        if (l > r) return {INT_MAX, 0};
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr)/2;
        return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    pi query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }

    void update(int v, int tl, int tr, int pos, int val){
        if(tl == tr) t[v] = {val, 1};
        else{
            int tm = (tl + tr)/2;
            if (pos <= tm) update(v*2, tl, tm, pos, val);
            else update(v*2 + 1, tm + 1, tr, pos, val);
            t[v] = combine(t[v*2], t[v*2 + 1]);
        }
    }

    void update(int pos, int val){
        update(1, 0, n - 1, pos, val);
    }
};

void solve(){
    int q;
    cin >> n >> q;
    vi a(n);
    loop(i, n){
        cin >> a[i];
    }
    SegTree st;
    st.build(a);
    int p, x, y;
    loop(i, q){
        cin >> p >> x >> y;
        if(p == 2) {
            pi ans = st.query(x, y - 1);
            out2(ans.F, ans.S);
        }
        else st.update(x, y);
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