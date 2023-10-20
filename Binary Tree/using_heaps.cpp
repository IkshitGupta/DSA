#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> v;
    bool minHeap;
    bool compare (int a, int b){
        if (minHeap){
            return a < b;
        }
        return a > b;
    }
    void heapify (int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        // Assume current as min
        int minIndex = i;
        if (left < v.size() && compare(v[left], v[minIndex])){
            minIndex = left;
        }
        if (right < v.size() && compare(v[right], v[minIndex])){
            minIndex = right;
        }
        if (minIndex != i) {
            swap(v[i], v[minIndex]);
            heapify(minIndex);
        }
    }
    public:
    Heap(bool type = true){
        minHeap = type; // by default true
    }
    void push(int data){
        v.emplace_back(data);
        int index = v.size() - 1;
        int parent = (index - 1)/2;
        while (index > 0 && compare(v[index], v[parent])){
            swap(v[index], v[parent]);
            index = parent;
            parent = (index - 1)/2;
        }
    }
    int top(){
        return v[0];
    }
    bool empty(){
        return v.empty();
    }
    void pop() {
        swap(v[0], v[v.size() - 1]);
        v.pop_back();
        heapify(0);
    }
};

class Car {
    public:
    int ind, x, y;
    Car(int ind, int x, int y){
        this -> ind = ind;
        this -> x = x;
        this -> y = y;
    }
    int dist(){
        return x*x + y*y;
    }
};

// Functors - Functional Objects
class CarCompare{
    public :
    // Method to overload () operator
    // void operator()(int a, int b){
    //     cout << "Comparing " << a << " and " << b << endl;
    // }
    bool operator()(Car a, Car b){
        return a.dist() > b.dist();
    }
};

int main(){
    Heap h(false);
    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(3);
    // while (!h.empty()){
    //     cout << h.top() << " ";
    //     h.pop();
    // }
    // cout << endl;

    // stl
    // priority_queue<int> pq; // by default max heap
    // for min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int a[10] = {5, 6, 17, 18, 9, 11};
    for (int i = 0; i < 6; i++){
        pq.push(a[i]);
    }
    // while (!pq.empty()){
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    // CarCompare cc;
    // cc(2, 5);   // cc is object which is working as a function

    // Finding nearest k cars from the origin
    priority_queue<Car, vector<Car>, CarCompare> cq;
    int x[10] = {5, 6, 17, 18, 9, 11, 0, 3};
    int y[10] = {1, 2, 8, 9, 10, 91, 1, 2};
    for (int i = 0; i < 8; i++){
        Car c(i, x[i], y[i]);
        cq.push(c);
    }

    while (!cq.empty()){
        Car p = cq.top();
        cout << p.ind << " ";
        cq.pop();
    }

    return 0;

}