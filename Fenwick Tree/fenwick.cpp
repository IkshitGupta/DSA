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
#define lisin(x, n) loop(i, n){cin >> x[i];}
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
// calculates the value of function f in the given range [l, r] in O(logn) time
// updates the value of an element in O(logn) time
// requires O(n) memory, or in other words, exactly the same memory required for array
// easy to use and code, especially, in the case of multidimensional arrays
// also called Binary Indexed Tree

// for sum
// A Fenwick tree is just an array T, where each of its elements is equal to the sum of elements of A in some range [g(i), i] where g is some function that satisfies 0 <= g(i) <= i
// use only with zero indexing
// point update range query
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {    // with default value
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {    // converting
        // int r = INT_MAX;
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);   // r = min(r, a[i])
    }   // similarly can find other things

    int s(int r) {  // sum
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int s(int l, int r) {
        return s(r) - s(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;  // here also change if min or other operation required
    }
};

// it is very easy to implement Fenwick Tree for multidimensional array.
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    // init(...) { ... }

    int s(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

// Range update and point query
// Let the Fenwick tree be initialized with zeros. Suppose that we want to increment the interval [l, r] by x. We make two point update operations on Fenwick tree which are add(l, x) and add(r+1, -x).
// If we want to get the value of A[i], we just need to take the prefix sum using the ordinary range sum method
// it is also possible to increase a single point A[i] with range_add(i, i, val).

// Range update & range query
// void range_add(int l, int r, int x){
//     add(B1, l, x);
//     add(B1, r+1, -x);
//     add(B2, l, x*(l-1));
//     add(B2, r+1, -x*r));
// }
// sum[0, i] = sum(B1, i)*i - sum(B2, i)
int main(){

    return 0;
}