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
class SegTree{
    vl seg; // stores segment with maximum sum
    vl s;   // stores sum of all segments
    vl pref;    // stores maximum prefix sum
    vl suf; // stores maximum suffix sum
    public:
    SegTree(){
        seg.resize(4*n);
        s.resize(4*n);
        pref.resize(4*n);
        suf.resize(4*n);
    }

    void build(vi& a, int v = 1, int tl = 0, int tr = n - 1){
        if(tl == tr) {
            seg[v] = a[tl];
            s[v] = a[tl];
            pref[v] = a[tl];
            suf[v] = a[tl];
        }
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);
            s[v] = s[2*v] + s[2*v + 1];
            pref[v] = max(pref[2*v], s[2*v] + pref[2*v + 1]);
            suf[v] = max(suf[2*v] + s[2*v + 1], suf[2*v + 1]);
            seg[v] = max({seg[2*v], seg[2*v + 1], suf[2*v] + pref[2*v + 1]});
        }
    }

    ll query(){
        return seg[1];
    }

    void update(int v, int tl, int tr, int pos, int val){
        if(tl == tr) {
            seg[v] = val;
            s[v] = val;
            pref[v] = val;
            suf[v] = val;
        }
        else{
            int tm = (tl + tr)/2;
            if (pos <= tm) update(v*2, tl, tm, pos, val);
            else update(v*2 + 1, tm + 1, tr, pos, val);
            s[v] = s[2*v] + s[2*v + 1];
            pref[v] = max(pref[2*v], s[2*v] + pref[2*v + 1]);
            suf[v] = max(suf[2*v] + s[2*v + 1], suf[2*v + 1]);
            seg[v] = max({seg[2*v], seg[2*v + 1], suf[2*v] + pref[2*v + 1]});
        }
    }

    void update(int pos, int val){
        update(1, 0, n - 1, pos, val);
    }
};

void solve(){
    int m;
    cin >> n >> m;
    vi a(n);
    loop(i, n){
        cin >> a[i];
    }
    SegTree st;
    st.build(a);
    int pos, val;
    loop(i, m){
        cin >> pos >> val;
        out(max(st.query(), 0LL));
        st.update(pos, val);
    }
    out(max(st.query(), 0LL));
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