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

// leaf nodes as elements while all parents 0
// given segment l to r, suppose it can be broken into 3 segments (as large as possible i.e. upwards)
// add val to the node corresponding the segment
// now when getting the value rather than returning leaf node, add all values of its parents with it
// op in node stores operations initially 0, then any vertex has a value its like a operation for its child vertex
// for leaf nodes, op stores values (not necessary correct, as operations above)

int n;
vi a;
struct node{
    ll op = 0;
    void combine(const node& left, const node& right, ll operations){
        
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

    // no need if initially 0
    // void build(vi& a, int v = 1, int tl = 0, int tr = n - 1){
    //     if(tl == tr) t[v].op = a[tl];
    //     else{
    //         int tm = (tl + tr)/2;
    //         build(a, v*2, tl, tm);
    //         build(a, v*2 + 1, tm + 1, tr);
    //         t[v].combine(t[v*2], t[v*2 + 1]);
    //         t[v] = node();
    //     }
    // }

    node get(int v, int tl, int tr, int pos){
        if (tr == tl) return t[v];
        int tm = (tl + tr)/2;
        node x;
        if (pos <= tm) x.op = operation(t[v].op, get(v*2, tl, tm, pos).op);
        else x.op = operation(t[v].op, get(v*2 + 1, tm + 1, tr, pos).op);
        return x;
    }

    ll get(int pos){
        return get(1, 0, n - 1, pos).op;
    }

    void update(int v, int tl, int tr, int l, int r, int val){
        if (tl > r || tr < l) return;
        if(tl >= l && tr <= r){
            t[v].op = operation(t[v].op, val);
            // t[v].s = operation(t[v].s, val);
        }
        else{
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, r, val);
            update(v*2 + 1, tm + 1, tr, l, r, val);
            // t[v].combine(t[2*v], t[2*v + 1], t[v].op);
        }
    }

    void update(int l, int r, int val){
        update(1, 0, n - 1, l, r, val);
    }

    node query(int v, int tl, int tr, int l, int r){
        if (tl > r || tr < l){
            node x;
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
        return query(1, 0, n - 1, l, r).op;
    }
};

// can apply both kind of operations when associative & distributive
// distributive = (a op1 v) op2 (b op1 v) = (a op2 b) op1 v
// eg (mul, add), bitwise
// sometimes may work in other cases like (+, +)

int main(){

    return 0;
}