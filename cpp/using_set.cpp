// Ordered set -:
// Contains unique elements
// Implemented using BST
// O(1) not possible

#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    cout << *s.find(7) << endl;
    cout << *(prev(s.end())) << endl;
    cout << *s.upper_bound(9) << endl;
    s.erase(4);
    s.erase(s.begin());
    s.erase(s.find(3));
    for (auto i : s){
        cout << i << " ";
    }
    cout << endl;
    // set<int, greater<int>> s;    // elements stored in descending order
    // begin, end, size, empty, rbegin, rend -: all are available
    // we can make anything; set of pair, of vector, etc.

    // Multiset
    // multiset<int> ms;
    // can contain duplicates
    // No O(n)
    // In sorted order
    // here erasing using value deletes all occurences, so if want to delete once only get iterator by find and then delete using iterator
    // Deletion through an iterator takes amortized constant time

    // but if don't want to delete other elements then top element then heap is faster
    // priority queue takes O(logn) time to delete top element. Multiset is a balanced binary search tree, which takes up to O(logn) time to delete anything and then assuring balance. 
    // also in multiset addition is slower

    // Unordered Set is like set of python
    // Implemented using Hash Table
    // Elements not in sorted order
    // O(1) operations
    // unordered_set<int> us;
    return 0;
}