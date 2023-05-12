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
// The Z-function for this string is an array of length n where the i-th element is equal to the greatest number of characters starting from the position i that coincide with the first characters of s.
// In other words, z[i] is the length of the longest string that is, at the same time, a prefix of s and a prefix of the suffix of s starting at i.
// easy to understand by example
// assume z[0] = 0
// 0 index
// aaaaa
// 04321   from a given character longest prefix of s available
// aaabaab
// 0210210
// abacaba
// 0010301
// aabxaayaab
// 0100210310

//     0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
//     a  a  b  x  a  a  b  x  c  a  a  b  x  a  a  b  x  a  y
//                 l        r
// Z   0  1  0  0  4
// already calculated for abx 100
// Z   0  1  0  0  4  1  0  0  0  8
//                                l                    r
// Z   0  1  0  0  4  1  0  0  0  8  1  0  0
// can't put 4 as length crosses r so we don't know about later string, so move l, and as already compared till r, compare after it
// Z   0  1  0  0  4  1  0  0  0  8  1  0  0  5  1  0  0
// similarly again can't put 4
// Z   0  1  0  0  4  1  0  0  0  8  1  0  0  5  1  0  0  1  0

void z_function(str& s, vi& z){
    int n = len(s);
    z.resize(n);
    int l = 0, r = 0;
    fr(i, 1, n){
        if (i > r){
            l = i;
            r = i;
            while (r < n && s[r - l] == s[r]){
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else{
            int k = i - l;
            if (z[k] < r - i + 1){
                z[i] = z[k];
            }
            else{
                l = i;
                while(r < n && s[r - l] == s[r]){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}

// search the substring
// make s + # + t

// find a string of shortest length such that can be represented as a concatenation of one or more copies of t
// compute the Z-function of s, loop through all i such that i divides n. Stop at the first i such that i + z[i] = n. Then, the string s can be compressed to the length i.

// checking usse pehle wo prefix aa chuke then maintain max, check if z[i] <= max

int main(){

    return 0;
}