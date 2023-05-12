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

// A Segment Tree is a data structure that allows answering range queries over an array effectively, while still being flexible enough to allow modifying the array. This includes finding the sum of consecutive array elements a[l...r], or finding the minimum element in a such a range in O(logn) time. Between answering such queries, the Segment Tree allows modifying the array by replacing one element, or even changing the elements of a whole subsegment (e.g. assigning all elements a[l...r] to any value, or adding a value to all element in the subsegment).
// require only a linear amount of memory. The standard Segment Tree requires 4n vertices for working on an array of size n.

// answer sum queries efficiently. We have an array a[], the Segment Tree must be able to find the sum of elements between the indices l and r and also handle changing values of the elements in the array (i.e. perform assignments of the form a[i] = x). The Segment Tree should be able to process both queries in O(logn) time.

// We compute and store the sum of the elements of the whole array. We then split the array into two halves a[0...n/2] and a[n/2+1...n] and compute the sum of each halve and store them. Each of these two halves in turn also split in half, their sums are computed and stored. And this process repeats until all segments reach size 1. these segments form a binary tree
// whenever n is not a power of two, not all levels of the Segment Tree will be completely filled.
// The height of the Segment Tree is O(logn)

// for construction of the segment tree, we start at the bottom level (the leaf vertices) and assign them their respective values. On the basis of these values, we can compute the values of the previous level, using the merge function. And on the basis of those, we can compute the values of the previous, and repeat the procedure until we reach the root vertex.

// left child of a vertex at index i is stored at index 2i, and the right one at index 2i + 1.
// in query segment can be broken into left and right
// Each level of a Segment Tree forms a partition of the array. Therefore an element a[i] only contributes to one segment from each level.
// here sum query, but can store t[v] as min, max, gcd, lcm etc...
// can also store count, in a pair

// a[] (the input array), v (the index of the current vertex)

// if indexing from 1, size = 4n + 4 and everywhere 1 to n in place of 0 to n - 1

int n;
vi a;
struct node{
    ll s = 0;
    // node(){

    // }
    void combine(const node& left, const node& right){
        s = left.s + right.s;
    }
};

class SegTree{
    public:
    vector<node> t;
    SegTree(){
        t.resize(4*n);
    }

    void build(vi& a, int v = 1, int tl = 0, int tr = n - 1){
        if(tl == tr) t[v].s = a[tl];
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);
            t[v].combine(t[v*2], t[v*2 + 1]);
        }
    }

    node query(int v, int tl, int tr, int l, int r){
        if (tl > r || tr < l) return node();
        if(tl >= l && tr <= r){
            return t[v];
        }
        int tm = (tl + tr)/2;
        node x;
        x.combine(query(v*2, tl, tm, l, r), query(v*2 + 1, tm + 1, tr, l, r));
        return x;
    }

    ll query(int l, int r){
        return query(1, 0, n - 1, l, r).s;
    }

    void update(int v, int tl, int tr, int pos, int val){
        if(tl == tr){
            t[v].s = val;
            a[pos] = val;
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

int main(){

    return 0;
}

// another version
// at each vertex of the Segment Tree we don't store information about the corresponding segment in compressed form, but store all elements of the segment.
// can store in list, sorted list, sets, maps, multiset
// IMP! memory consumed will only be O(nlogn) because each element of the array falls into logn segments
// for three given numbers (l, r, x) we have to find the minimal number in the segment a[l...r] which is greater than or equal to x.
// now t will be vvi
// if (tl == tr) t[v] = {a[tl]}
// in else part use merge(all(t[2*v]), all(t[2*v + 1]), back_inserter(t[v]))

// Segment Tree allows applying modification queries to an entire segment of contiguous elements, and perform the query in the same time O(logn)