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
// given segmnt l to r, suppose it can be broken into 3 segments (as large as possible i.e. upwards)
// add val to the node corresponding the segment
// now when getting the value rather than returning leaf node, add all values of its parents with it
// for getting final a, use get

int n;
struct node{
    ll op = 0;  // stores operations, initially all 0
    void combine(const node& left, const node& right){
        
    }
};

class SegTree{
    ll NO_OPERATION = LLONG_MAX;
    vector<node> t;
    
    // length required in many
    ll operation(ll a, ll b){   // for non commutative
        if (b == NO_OPERATION) return a;    // no change in child a
        // if (a == NO_OPERATION) a =   // assign value in this case
        return b;   // apply the operation to child
    }
    // what wiil be the child after this operation (for returning b)
    // for commutative same function will work, as b will always be no_operation, as propagation done already

    // propagate in all
    void propogate(int v, int tl, int tr){
        if (tl == tr) return;   // leaf node
        // int tm = (tl + tr)/2;
        t[2*v].op = operation(t[2*v].op, t[v].op);
        // t[2*v].s = operation(t[2*v].s, t[v].op);
        t[2*v + 1].op = operation(t[2*v + 1].op, t[v].op);
        // t[2*v + 1].s = operation(t[2*v + 1].s, t[v].op);
        t[v].op = NO_OPERATION;
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
        propogate(v, tl, tr);
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
        propogate(v, tl, tr);
        if (tl > r || tr < l) return;
        if(tl >= l && tr <= r){
            t[v].op = operation(t[v].op, val);
        }
        else{
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, r, val);
            update(v*2 + 1, tm + 1, tr, l, r, val);
            // t[v].combine(t[2*v], t[2*v + 1]);
        }
    }

    void update(int l, int r, int val){
        update(1, 0, n - 1, l, r, val);
    }

    node query(int v, int tl, int tr, int l, int r){
        propogate(v, tl, tr);
        if (tl > r || tr < l){
            node x;
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
        return query(1, 0, n - 1, l, r).op;
    }
};

int main(){

    return 0;
}