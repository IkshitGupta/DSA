#include <bits/stdc++.h>
#define n 1000
using namespace std;

class stac{
	int* arr;
	int top;
	public:
	stac(){
		top = -1;
		arr = new int[n];
	}
	void push(int x){
		if (top == n - 1){
			cout << "Overflow" << endl;
			return;
		}
		top ++;
		arr[top] = x;
	}
	void pop (){
		if (top == -1){
			cout << "Nothing to pop\n";
			return;
		}
		top --;
	}
	int Top(){
		if (top == -1){
			cout << "Nothing present\n";
			return -1;
		}
		return arr[top];
	}
	bool empty(){
		return top == -1;
	}
};

int main(){
	stac st;
	st.push(25);
	st.push(24);
	st.push(21);
	cout << st.Top() << endl;
	st.pop();
	cout << st.Top() << endl;
	st.pop();
	cout << st.Top() << endl;
	st.pop();
	cout << st.Top() << endl;
	st.pop();

	// using stl
	stack <int> st;
	// includes functions like emplace, empty, push, pop, size, swap and top
	return 0;
}