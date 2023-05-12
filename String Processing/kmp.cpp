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
// lPS Longest Prefix Suffix
// The prefix function for this string is defined as an array of length n, where pi[i] is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring. A proper prefix of a string is a prefix that is not equal to the string itself.
// Examples:
// abcdabeabf
// 0000120120  prefix se kitna match hai
// abcdeabfabc
// 00000120123
// aabcadaabe
// 0100101230
// aaaabaacd
// 012301200

// always from index 1, so that we can have zero as reference
// going to pi[j - 1]
// say abababd
//     0012
//     last one has 2, means we require s[2] as indexing from 1
//     so now last as 2 we know we require 3 no need to check from start
// if we reach 0 and still no match we assign 0

void prefix_function(str& s, vi& pii){   // pi given to store
    int n = len(s);
    pii.resize(n);
    fr(i, 1, n){
        int j = pii[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pii[j - 1];
        }
        if (s[i] == s[j]) j++;
        pii[i] = j;
    }
}

// for searching a pattern/substring
// get prefix function of pattern
void isSubstring(str& t, str& s){   // text s, pattern s
    // create x = s + # + t
    // now if we reach pi[i] = n, then substring exists
    // original index = i - 2n

    // another method
    // if we know that max prefix can only be of some length than only create that much prefix sum
    vi pii;
    prefix_function(s, pii);
    int n = len(t);
    int j = 0;  // corresponding to pattern
    int i = 0;  // corresponding to text
    vi ans;
    while (i < n){
        if (s[j] == t[i]){
            j++;
            i++;
            if (j == len(s)){
                ans.eb(i - j + 1);  // by 1 index
                j = pii[j - 1];
            }
        }
        else{
            if (j == 0) i++;
            else j = pii[j - 1];
        }
    }
}
// if do not understand can refer ending of video Abdul Bari

// Counting the number of occurrences of each prefix
void cnt(str& s){
    vi pii;
    prefix_function(s, pii);
    int n = len(s);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pii[i]]++;
    for (int i = n-1; i > 0; i--)
        ans[pii[i-1]] += ans[i];
    for (int i = 0; i <= n; i++)    // counting original
        ans[i]++;
    // abab // shorter prefixes like a, b are also in ab
}

// to check if a string can be written by repeating a small string
// ex abcabcabca
// len(small string) = len(pii) - pii.back()

// to check after how many rotations we will get the same string
// apply prefix sum to 2*n and get len(pii) - pii.back()

int main(){

    return 0;
}