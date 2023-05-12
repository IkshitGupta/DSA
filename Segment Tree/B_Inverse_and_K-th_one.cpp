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
    bool op = 0;  // stores operations, initially all NO_OP
    int s = 0;
    void combine(const node& left, const node& right){
        s = left.s + right.s;
    }
};

class SegTree{
    ll NO_OPERATION = 0;
    vector<node> t;

    // propagate in all
    void propogate(int v, int tl, int tr){
        // inversion repeates over a cycle of 2, hence when even operation count it means that lower inverted twice
        if (tl == tr || t[v].op == 0) return;   // leaf node
        int tm = (tl + tr)/2;
        t[2*v].op ^= 1;
        t[2*v + 1].op ^=  1;
        t[2*v].s = tm + 1 - tl - t[2*v].s;
        t[2*v + 1].s = tr - tm - t[2*v + 1].s;
        t[v].op = 0;
    }
    public:
    SegTree(){
        t.resize(4*n);
    }

    void update(int v, int tl, int tr, int l, int r){
        if (tl > r || tr < l) return;
        propogate(v, tl, tr);
        if((tl >= l) && (tr <= r)){
            t[v].op = 1;
            t[v].s = tr + 1 - tl - t[v].s;
        }
        else{
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, r);
            update(v*2 + 1, tm + 1, tr, l, r);
            t[v].combine(t[2*v], t[2*v + 1]);
        }
    }

    void update(int l, int r){
        update(1, 0, n - 1, l, r - 1);
    }

    int query(int v, int tl, int tr, int k){
        propogate(v, tl, tr);
        if (tl == tr && k == 0) return tl;
        int tm = (tl + tr)/2;
        if(t[2*v].s > k) return query(v*2, tl, tm, k);
        else return query(v*2 + 1, tm + 1, tr, k - t[2*v].s); // agar right subtree me ja rahe toh left subtree ke ones hata do
    }

    int query(int k){
        propogate(1, 0, n - 1);
        if (k >= t[1].s) return n;
        return query(1, 0, n - 1, k);
    }
};


void solve(){
    int m;
    cin >>  n>> m;
    SegTree st;
    int q, a, b;
    loop(i, m){
        cin >> q;
        if (q == 1){
            cin >> a >> b;
            st.update(a, b);
        }
        else{
            cin >> a;
            out(st.query(a));
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