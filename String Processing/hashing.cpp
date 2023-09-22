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
// if the input is composed of only lowercase letters of the English alphabet, p = 31 is a good choice. If the input may contain both uppercase and lowercase letters, then p = 53 is a possible choice. 
// m should be a large number since the probability of two random strings colliding is about 1/m
// hash[s] = s[0] + s[1]*p + s[2]*p^2 + ..... + s[n - 1]*p^(n - 1) mod m
// consider a as 1 and z as 26

// We can reduce the probability of collision by generating a pair of hashes for a given string. The first hash is generated using p = 31 and m = 10^9 + 7, while the second hash is generated using p = 37 and m = 10^9 + 9.

// hash[i....j]*p^i = hash[0.....j] - hash[0....i-1] mod m    // to calculate hash[i...j] inverse required
// on changing character
// hash_new = hash_old - p^i*(ch1) + p^i*(ch2)

// finding a substr in string, calculate at each i hash[i:i+len(substr)] and compare in O(1)

// Determine the number of different substrings in a string
// loop for each length (1..n) in str(1..n) O(n^2), add hash in set, total O(n^2logn)
// better to use trie, there O(n^2)

ll pw(ll a, ll b, int m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if (b&1){
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return ans;
}

vl pow1;
vl pow2;
void pre(){
    int end = 2e5 + 1;  // len of s
    pow1.resize(end);
    pow2.resize(end);
    int p1 = 31, p2 = 37;
    int mod1 = 1e9 + 7;
    int mod2 = 1e9 + 9;
    pow1[0] = 1;
    fr(i, 1, end){
        pow1[i] = pow1[i - 1]*p1;
        pow1[i] %= mod1;
    }
    pow2[0] = 1;
    fr(i, 1, end){
        pow2[i] = pow2[i - 1]*p2;
        pow2[i] %= mod2;
    }
}

class Hashing{
    int p1 = 31, p2 = 37;
    int mod1 = 1e9 + 7;
    int mod2 = 1e9 + 9;
    vl hash1, hash2;
    // 1 based indexing
    public:
    pl hash_pair;
    vl invpow1;
    vl invpow2;
    Hashing(str& s){
        int n = len(s); 
        hash1.resize(n + 1);
        hash2.resize(n + 1);
        loop(i, n){
            hash1[i + 1] = hash1[i] + (s[i] - 'a' + 1)*pow1[i];
            hash1[i + 1] %= mod1;
        }
        loop(i, n){
            hash2[i + 1] = hash2[i] + (s[i] - 'a' + 1)*pow2[i];
            hash2[i + 1] %= mod2;
        }
        hash_pair = {hash1[n], hash2[n]};
        invpow1.resize(n + 1);
        invpow2.resize(n + 1);
        invpow1[n] = pw(pow1[n], mod1 - 2, mod1);
        invpow2[n] = pw(pow2[n], mod2 - 2, mod2);
        frr(i, n - 1, -1){  // modular inverse in O(n)
            invpow1[i] = invpow1[i + 1]*p1;
            invpow1[i] %= mod1;
            invpow2[i] = invpow2[i + 1]*p2;
            invpow2[i] %= mod2;
        }
    }

    pl substr_hash(int l, int r){   // with 0 indexing, r excluded
        ll temp1 = hash1[r] - hash1[l];
        if (temp1 < 0) temp1 += mod1;
        ll temp2 = hash2[r] - hash2[l];
        if (temp2 < 0) temp2 += mod2;
        temp1 *= invpow1[l];
        temp1 %= mod1;
        temp2 *= invpow2[l];
        temp2 %= mod2;
        return {temp1, temp2};
    }
};

// Rabin-Karp for string matching
// pattern - s, text - t    O(s + t)
// get hash of s and t
// 1 index i + S < T + 1
// loop(i, T + 1 - S){
//     ll cur = (h[i + S] - h[i] + m)%m;
//     if (cur == (h_s * powp[i])%m) ans.eb(i); // powp[i] in formula
// }

int main(){
    pre();
    return 0;
}