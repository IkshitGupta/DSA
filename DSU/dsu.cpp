#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
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
int mod = 1e9 + 7;

// Naive
// class DSU{
//     public:
//     vi parent;
//     void start(){
//         parent.resize(n + 1);
//     }
//     void make_set(int v) {
//         parent[v] = v;
//     }

//     int find_set(int v) {
//         if (v == parent[v])
//             return v;
//         return find_set(parent[v]);
//     }

//     void union_sets(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if (a != b) parent[b] = a;
//     }
// };
// Inefficient
// find_set takes O(n)

// Path compression optimization
// int find_set(int v) {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(parent[v]);
// }
// This simple modification of the operation already achieves the time complexity O(log n)

// Union by size
// we will change which tree gets attached to the other one. In the naive implementation the second tree always got attached to the first one
int n;
class DSU{
    vi parent;
    vi size;
    public:
    DSU(){
        loop(i, n + 1){
            parent.eb(i);
        }
        size.resize(n + 1, 1);
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            // Here can update min of sets, max of sets, etc..
        }
    }
};
// Nearly constant time for all operations
// can also add on basis of other things except size depending on problem

// union by rank based on the depth of the trees
// void make_set(int v) {
//     parent[v] = v;
//     rank[v] = 0;
// }

// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (rank[a] < rank[b])
//             swap(a, b);
//         parent[b] = a;
//         if (rank[a] == rank[b])
//             rank[a]++;
//     }
// }

int main(){
    return 0;
}

// https://cp-algorithms.com/data_structures/disjoint_set_union.html

//  We are given several elements, each of which is a separate set. A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is.

// make_set(v) - creates a new set consisting of the new element v
// union_sets(a, b) - merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)
// find_set(v) - returns the representative (also called leader) of the set that contains the element v. This representative is an element of its corresponding set. It is selected in each set by the data structure itself (and can change over time, namely after union_sets calls). This representative can be used to check if two elements are part of the same set or not.

// We will store the sets in the form of trees: each tree will correspond to one set. And the root of the tree will be the representative/leader of the set.

// array parent that stores a reference to its immediate ancestor in the tree.

// One of the applications of DSU is the following task: there is an image of n*m pixels. Originally all are white, but then a few black pixels are drawn. You want to determine the size of each white connected component in the final image
// For the solution we simply iterate over all white pixels in the image, for each cell iterate over its four neighbors, and if the neighbor is white call union_sets. Thus we will have a DSU with n*m nodes corresponding to image pixels. The resulting trees in the DSU are the desired connected components.
// a connected components problem by dfs, bfs

// Compress jumps along a segment
// problem of painting subarrays
//  We have a segment of length L, each element initially has the color 0. We have to repaint the subarray [l, r] with the color c for each query (l, r, c). At the end we want to find the final color of each cell. We assume that we know all the queries in advance, i.e. the task is offline.

// For the solution we can make a DSU, which for each cell stores a link to the next unpainted cell. Thus initially each cell points to itself. After painting one requested repaint of a segment, all cells from that segment will point to the cell after the segment.
// Now to solve this problem, we consider the queries in the reverse order: from last to first. This way when we execute a query, we only have to paint exactly the unpainted cells in the subarray. All other cells already contain their final color. To quickly iterate over all unpainted cells, we use the DSU. We find the left-most unpainted cell inside of a segment, repaint it, and with the pointer we move to the next empty cell to the right.
// Here we can use the DSU with path compression, but we cannot use union by rank / size (because it is important who becomes the leader after the merge). Therefore the complexity will be O(log n) per union

// for (int i = 0; i <= L; i++) {
//     make_set(i);
// }

// for (int i = m-1; i >= 0; i--) {
//     int l = query[i].l;
//     int r = query[i].r;
//     int c = query[i].c;
//     for (int v = find_set(l); v <= r; v = find_set(v)) {
//         answer[v] = c;
//         parent[v] = v + 1;   // even if v + 1 is painted when we do find_set, it will return next unpainted
//     }
// }
// We can use union by rank, if we store the next unpainted cell in an additional array