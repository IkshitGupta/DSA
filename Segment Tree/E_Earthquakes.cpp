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
    ll mi = 0;
    ll op = 0;
    ll z = -1;
    void combine(const node& left, const node& right){
        mi = min(left.mi, right.mi);
        z = left.z + right.z;
    }
};

class SegTree{
    ll NO_OPERATION = LLONG_MAX;
    int cnt;
    ll operation(int a, int b, int p, int l, int z){
        if (b == NO_OPERATION) return a;
        if (b > p) return b;
        else {
            cnt += l - z;
            return 0LL;
        }
    }
    public:
    vector<node> t;
    SegTree(){
        t.resize(4*n);
    }

    void propogate(int v, int tl, int tr, int p = 0){
        if (tl == tr) return;   // leaf node
        int tm = (tl + tr)/2;
        t[2*v].op = operation(t[2*v].op, t[v].op, p, 0, 0);
        t[2*v].mi = operation(t[2*v].mi, t[v].op, p, tm + 1 - tr, t[2*v].z);
        t[2*v + 1].op = operation(t[2*v + 1].op, t[v].op, p, 0);
        t[2*v + 1].mi = operation(t[2*v + 1].mi, t[v].op, p, tr - tm, t[2*v + 1].z);
        t[v].op = NO_OPERATION;
    }

    node query(int v, int tl, int tr, int l, int r, int p){
        propogate(v, tl, tr, p);
        if (tl > r || tr < l) return node();
        if(tl >= l && tr <= r){
            return t[v];
        }
        int tm = (tl + tr)/2;
        node x;
        x.combine(query(v*2, tl, tm, l, r, p), query(v*2 + 1, tm + 1, tr, l, r, p));
        return x;
    }

    int query(int l, int r, int p){
        cnt = 0;
        query(1, 0, n - 1, l, r - 1, p);
        return cnt;
    }

    void update(int v, int tl, int tr, int pos, int val){
        if (t[v].z == -1) t[v].z = tr + 1 - tl;
        propogate(v, tl, tr);
        if(tl == tr){
            t[v].op = val;
            t[v].mi = val;
            t[v].z -= 1;
        } 
        else{
            int tm = (tl + tr)/2;
            if (pos <= tm) update(v*2, tl, tm, pos, val);
            else update(v*2 + 1, tm + 1, tr, pos, val);
            t[v].combine(t[v*2], t[v*2 + 1]);
        }
    }

    void update(int pos, int val){
        update(1, 0, n - 1, pos, val);
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
            cin >> a >> b;
            st.update(a, b);
        }
        else{
            cin >> a >> b >> c;
            out(st.query(a, b, c));
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