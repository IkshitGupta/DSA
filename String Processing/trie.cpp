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
int mod = 1e9 + 7;

struct node{
    char data;
    map<char, node*> h; // if a in h then it has its address
    int isLast;
    node(char d){
        data = d;
        isLast = 0;
    }
};

class Trie{
    node* root;
    public:
    Trie(){
        root = new node('\0');  // initial root which will contain map of first charachter
    }

    void insert(str& word){
        node* temp = root;
        loop(i, len(word)){
            char ch = word[i];
            if(temp->h.count(ch) == 0){ // if this character not present in previous charachter map
                node* child = new node(ch);
                temp->h[ch] = child;
            }
            temp = temp->h[ch];
        }
        temp->isLast = 1;
    }

    bool isPresent(str& word){
        node* temp = root;
        loop(i, len(word)){
            char ch = word[i];
            if(temp->h.count(ch)) temp = temp->h[ch];
            else return 0;
        }
        return temp->isLast;
    }
};

// bitwise
struct node2{
    int data;
    int cnt = 0;
    vector<node2*> h; // if a in h then it has its address
    node2(int d){
        data = d;
        h.resize(2, nullptr);
    }
};

template<typename T>
class Trie2{
    const int hb = 32;
    public:
    node2* root = new node2(0);  // initial root which will contain map of first charachter

    void insert(T x){
        node2* temp = root;
        frr(i, hb, -1){
            int ch = (((1LL<<i)&x) != 0);
            if(temp->h[ch] == nullptr){ // if this character not present in previous charachter map
                node2* child = new node2(ch);
                temp->h[ch] = child;
            }
            temp = temp->h[ch];
            temp->cnt++;
        }
    }

    void remove(T x, node2* temp, int i){
        if (i == -1) return;
        int ch = (((1LL<<i)&x) != 0);
        remove(x, temp->h[ch], i - 1);
        if (temp->h[ch]->cnt == 1) {
            delete temp -> h[ch];
            temp->h[ch] = nullptr;
        }
        else temp->h[ch]->cnt--;
    }

    void remove(T x){
        remove(x, root, hb);
    }
    
    T Xor(T x){   // gives maximum possible xor with n and elements in trie
        node2* temp = root;
        T ans = 0;
        frr(i, hb, -1){ // starting as bigger bit more priority
            int ch = (((1LL<<i)&x) != 0);
            ch ^= 1;
            if(temp->h[ch] != nullptr) {
                temp = temp->h[ch];
                ans |= (1LL<<i);
            }
            else{
                temp = temp->h[ch^1];
            }
        }
        return ans;
    }
};

int main(){
    vs words = {"wohi", "toh", "abcdefu", "abc", "word"};
    Trie t;
    for(auto& i : words){
        t.insert(i);
    }
    str s = "wohi";
    cout << t.isPresent(s);
    return 0;
}

// dictionary type data structure (real wali, not python)
// apple, ask
// a node, containing p and s, they respectively contain there subsequent
// Tries is a tree that stores strings. The maximum number of children of a node is equal to the size of the alphabet. Trie supports search, insert and delete operations in O(L) time where L is the length of the key
// used in prefix search, auto complete
// O(total characters)

// total distinct substrings
// int count = 0;
// node* t = new node('\0');
// loop(i, len(s)){
//     node* temp = head;
//     fr(j, i, len(s)){
//         if (temp->h.count(s[j] - 'a') == 0){
//             node* child = new node(ch);
//             temp->h[s[j] - 'a'] = child;
//             temp->isLast = 1;
//             count++;
//         }
//         temp = temp->h[s[j] - 'a'];
//     }
// }