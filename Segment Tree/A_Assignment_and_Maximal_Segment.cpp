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
// 1 denotes left, 2 denotes right
// seg = max(seg1, seg2, suf1 + pref2)  (maximum sum segment entirely in left, entirely in right, part of both)
// pref = max(pref1, s1 + pref2)    (complete segment in left, in both left and right)
// suf = max(suf2, s2 + suf1)

int n;
struct node{
    ll op = 0;
    ll seg = 0; // stores segment with maximum sum
    ll s = 0;   // stores sum of all segments
    ll pref = 0;    // stores maximum prefix sum
    ll suf = 0; // stores maximum suffix sum
    void combine(const node& left, const node& right){
        s = left.s + right.s;
        pref = max(left.pref, left.s + right.pref);
        suf = max(left.suf + right.s, right.suf);
        seg = max({left.seg, right.seg, left.suf + right.pref});
    }
};
class SegTree{
    vector<node> t;
    ll NO_OPERATION = LLONG_MAX;

    ll operation(ll a, ll b, ll l){   // for non commutative
        if (b == NO_OPERATION) return a;    // no change in child a
        // if (a == NO_OPERATION) a = 0;  // assign value in this case
        return b*l;   // apply the operation to child
    }

    void propogate(int v, int tl, int tr){
        if (tl == tr) return;   // leaf node
        int tm = (tl + tr)/2;
        t[2*v].op = operation(t[2*v].op, t[v].op, 1);
        t[2*v].s = operation(t[2*v].s, t[v].op, tm + 1 - tl);
        t[2*v + 1].op = operation(t[2*v + 1].op, t[v].op, 1);
        t[2*v + 1].s = operation(t[2*v + 1].s, t[v].op, tr - tm);
        t[2*v].pref = operation(t[2*v].pref, t[v].op, tm + 1 - tl);
        t[2*v].suf = operation(t[2*v].suf, t[v].op, tm + 1 - tl);
        t[2*v].seg = operation(t[2*v].seg, t[v].op, tm + 1 - tl);
        t[2*v + 1].pref = operation(t[2*v + 1].pref, t[v].op, tr - tm);
        t[2*v + 1].suf = operation(t[2*v + 1].suf, t[v].op, tr - tm);
        t[2*v + 1].seg = operation(t[2*v + 1].seg, t[v].op, tr - tm);
        t[v].op = NO_OPERATION;
    }

    public:
    SegTree(){
        t.resize(4*n);
    }

    ll query(){
        return t[1].seg;
    }

    void update(int v, int tl, int tr, int l, int r, int val){
        propogate(v, tl, tr);
        if (tl > r || tr < l) return;
        if(tl >= l && tr <= r){
            t[v].op = operation(t[v].op, val, 1);
            t[v].s = operation(t[v].s, val, tr + 1 - tl);
            val = max(val, 0);
            t[v].seg = operation(t[v].seg, val, tr + 1 - tl);
            t[v].pref = operation(t[v].pref, val, tr + 1 - tl);
            t[v].suf = operation(t[v].suf, val, tr + 1 - tl);
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
};

void solve(){
    int m;
    cin >> n >> m;
    SegTree st;
    int l, r, val;
    loop(i, m){
        cin >> l >> r >> val;
        st.update(l, r, val);
        out(st.query());
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