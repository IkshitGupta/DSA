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
// int mod = 1e9 + 7;

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

int n, mod;
vi mm(vi& a, vi& b){
    vi c(4);
    c[0] = (a[0]*b[0] + a[1]*b[2])%mod;
    c[1] = (a[0]*b[1] + a[1]*b[3])%mod;
    c[2] = (a[2]*b[0] + a[3]*b[2])%mod;
    c[3] = (a[2]*b[1] + a[3]*b[3])%mod;
    return c;
}

class SegTree{
    vvi t;
    void combine(int v){
        t[v][0] = (t[2*v][0]*t[2*v + 1][0] + t[2*v][1]*t[2*v + 1][2])%mod;
        t[v][1] = (t[2*v][0]*t[2*v + 1][1] + t[2*v][1]*t[2*v + 1][3])%mod;
        t[v][2] = (t[2*v][2]*t[2*v + 1][0] + t[2*v][3]*t[2*v + 1][2])%mod;
        t[v][3] = (t[2*v][2]*t[2*v + 1][1] + t[2*v][3]*t[2*v + 1][3])%mod;
    }
    public:
    SegTree(){
        t.resize(4*n, vi(4));
    }

    void build(vvi& a, int v, int tl, int tr){
        if(tl == tr) t[v] = a[tl];
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);
            combine(v);
        }
    }

    void build(vvi& a){
        build(a, 1, 0, n - 1);
    }

    vi query(int v, int tl, int tr, int l, int r){
        if (l > r) return {1, 0, 0, 1};
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr)/2;
        vi x = query(v*2, tl, tm, l, min(r, tm));
        vi y = query(v*2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return mm(x, y);
    }

    void query(int l, int r){
        vi v = query(1, 0, n - 1, l - 1, r - 1);
        out2(v[0], v[1]);
        out2(v[2], v[3]);
    }
};

void solve(){
    int m;
    cin >> mod >> n >> m;
    vvi matrix;
    str s;
    int a, b, c, d;
    loop(i, n){
        cin >> a >> b >> c >> d;
        matrix.push_back({a, b, c, d});
        getline(cin, s);
    }
    SegTree st;
    st.build(matrix);
    loop(i, m){
        cin >> a >> b;
        st.query(a, b);
        cout << endl;
    }
    // out(1);
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