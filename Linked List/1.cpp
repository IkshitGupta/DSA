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
#define len(x) int(x.size())
#define sum(x) accumulate(x.begin(), x.end(), 0)
#define out(x) cout << x << endl
#define outl(x) cout << x << " "
#define out2(x, y) cout << x << " " << y << endl
#define printpair(x) cout << x.F << " " << x.S << endl
#define out3(x, y, z) cout << x << " " << y << " " << z << endl
#define out4(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl
#define lisin(x, n) loop(i, n){cin >> x[i];}
int mod = 1e9 + 7;
void yes(bool a = 1){
	if (a == 1) out("YES");
	else out("NO");}

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
int n;

void solve(){
	
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