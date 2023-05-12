#include <bits/stdc++.h>
#define n 200
using namespace std;

class que {
    int* arr;
    int front;
    int back;
    public:
    que(){
        arr = new  int[n];
        front = -1;
        back = -1;
    }
    void push(int x){   // push at last
        if (back == n - 1){
            cout << "Queue overflow\n";
            return;
        }
        back ++;
        arr[back] = x;
        if (front == -1) {
            front ++;
        }
    }
    void pop(){ // remove from front
        if (front == -1 || front > back){
            cout << "Queue empty\n";
            return;
        }
        front ++;
    }
    int peek(){
        if (front == -1 || front > back){
            cout << "Queue empty\n";
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if (front == -1 || front > back){
            return true;
        }
        return false;
    }
};

int main(){
    que q;
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(3);
    // cout << q.peek();
    q.pop();
    // cout << q.peek();
    q.pop();
    // cout << q.peek();
    q.pop();

    queue <int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    cout << qu.front() << endl;
    qu.pop();
    cout << qu.front() << endl;
    // empty() – Returns whether the queue is empty.
    // size() – Returns the size of the queue.
    // queue::swap() in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
    // queue::emplace() in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.
    // queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
    // push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.

    deque<int>dq;
    dq.push_front(5);
    dq.push_back(4);
    dq.pop_front();
    dq.pop_back();
    int l = dq.size();
    return 0;
}