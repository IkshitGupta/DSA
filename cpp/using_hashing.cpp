// two types map & unordered_map
// unordered_map is dictionary in python (implemented by hash table)
// map is also a dictionary but its always sorted (implemented by red black tree) // here insertion and access in O(log n)  // if you want to do this in python maintain a normal dictionary and a list of keys with bisect insort
// in a Map, every key is mapped with default value zero when the map is declared.

#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> m;
    m[8] = 2;
    cout << m[8] << endl;
    unordered_map<string, int> ump;
    ump["a"] = 5;   // single quotes don't work as string given
    cout << ump["a"] << endl;
    cout << ump.count("b") << endl; // return 0 or 1 if key is present or not
    ump.insert(make_pair("b", 7));  // another way of inserting
    // Traversing an unordered map
    for (auto x : ump)
        cout << x.first << " " << x.second << endl;
    ump.erase("a"); // to delete
    cout << ump.size();
    if (ump.find("b") != ump.end()){    // equivalent to if "b" in ump
        cout << "Found";
    }

    struct Node {
        int value = -1;
    };
    // For Map with every key mapped to default value -1
    map<int, Node > M;
    cout << M[2].value;
    return 0;
}