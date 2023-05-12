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
// Finding original from inversion array
// a = [0 1 1 0 3]
// create a visited array
// build a segment tree of visited array
// now iterate in a from right to left
// if inversions at position is 3, find 3rd(index wise) one from last, i.e. 4th one, which indicates 3 are greater than it which will come earlier and the next possible one is answer

int n;
class SegTree{
    public:
    vl t;
    SegTree(){
        t.resize(4*n);
    }

    void build(vi& a, int v = 1, int tl = 0, int tr = n - 1){
        if((tl == tr) && (a[tl] == 1)) t[v] = 1;    // maintaining count of a certain number
        else if(tl == tr) t[v] = 0;
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);
            t[v] = t[v*2] + t[v*2 + 1];
        }
    }

    ll query(int v, int tl, int tr, int k){
        if (tl == tr && k == 0) return tl;
        int tm = (tl + tr)/2;
        if(t[2*v] > k) return query(v*2, tl, tm, k);
        else return query(v*2 + 1, tm + 1, tr, k - t[2*v]); // agar right subtree me ja rahe toh left subtree ke ones hata do
    }

    ll query(int k){    // k is index
        if(k > t[1]) return -1;
        return query(1, 0, n - 1, k);
    }

    void update(int v, int tl, int tr, int pos){
        if(tl == tr){
            t[v]^=1;
        }
        else{
            int tm = (tl + tr)/2;
            if (pos <= tm) update(v*2, tl, tm, pos);
            else update(v*2 + 1, tm + 1, tr, pos);
            t[v] = t[v*2] + t[v*2 + 1];
        }
    }

    void update(int pos){
        update(1, 0, n - 1, pos);
    }
};

void solve(){
    cin >> n;
    vi a(n);
    loop(i, n){
        cin >> a[i];
    }
    vi vis(n, 1);
    // reverse(all(vis));   // not required here
    SegTree st;
    st.build(vis);  // all leaf nodes 1
    vi ans(n);
    int q;
    frr(i, n - 1, -1){
        q = st.query(a[i]); // end se kth one
        ans[i] = n - q; // original array me index n - q - 1
        st.update(q);   // updating reversed array only, so given index of it
    }
    printlist(ans);
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