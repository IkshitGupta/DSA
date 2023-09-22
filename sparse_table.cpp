#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fr(i, a, b) for(int i = a; i < b; i++)
#define frr(i, b, a) for(int i = b; i > a; i--)
#define loop(i, n) for(int i = 0; i < n; i++)
#define len(x) int(x.size())

template<typename T>
class SparseTable{
    vector<vector<T>> store;
    int k, L;
    vi lg;
    public:
    SparseTable(vector<T>& a){
        L = len(a);

        // precomuting log2
        lg.resize(L + 1);
        lg[1] = 0;  // check L != 0
        fr(i, 2, L + 1){
            lg[i] = lg[i/2] + 1;
        }

        // precomputing
        k = lg[L];
        store.resize(k + 1, vector<T>(L));
        loop(i, L){
            store[0][i] = a[i];
        }
        fr(i, 1, k + 1){
            for(int j = 0; j + (1 << i) - 1 < L; j++){
                store[i][j] = min(store[i - 1][j], store[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T getmin(int l, int r){ // 0 based  // both included
        int x = lg[r + 1 - l];
        return min(store[x][l], store[x][r - (1 << x) + 1]);
    }
    // similarly gcd
};

int main(){

    return 0;
}

// can answer most range queries in O(log n), but its true power is answering range minimum queries (or equivalent range maximum queries). For those queries it can compute the answer in O(1) time.
// can only be used on immutable arrays
// https://www.youtube.com/watch?v=0jWeUdxrGm4

// ll getsum(int l, int r){
//     ll s = 0;
//     frr(i, k, -1){
//         if ((1 << i) <= r + 1 - l){
//             s += store[i][l];
//             l += (1 << i);
//         }
//     }
//     return s;
// }