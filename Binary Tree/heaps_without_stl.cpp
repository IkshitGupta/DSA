#include <iostream>
using namespace std;

bool compare(int a, int b, bool minHeap){
    if (minHeap){
        return a < b;
    }
    return a > b;
}

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int* v, int i, int size, bool minHeap){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int minIndex = i;
    if (left < size && compare(v[left], v[i], minHeap)){
        minIndex = left;
    }
    if (right < size && compare(v[right], v[minIndex], minHeap)){
        minIndex = right;
    }
    if (minIndex != i){
        swap(&v[i], &v[minIndex]);
        heapify(v, minIndex, size, minHeap);
    }
}

void push(int data, int* v, int* size, bool minHeap){
    v[*size] = data;
    *size = *size + 1;
    int index = *size - 1;
    int parent = (index - 1)/2;
    while (index > 0 && compare(v[index], v[parent], minHeap)){
        swap(&v[index], &v[parent]);
        index = parent;
        parent = (index - 1)/2;
    }
}

int top(int v[]){
    return v[0];
}

void pop(int* v, int* size, bool minHeap){
    swap(&v[0], &v[*size - 1]);
    *size = *size - 1;
    heapify(v, 0, *size, minHeap);
}

int main(){
    // int v[1000];
    // int size = 0;
    bool minHeap = 1;
    // push(5, v, &size, minHeap);
    // push(15, v, &size, minHeap);
    // push(2, v, &size, minHeap);
    // push(20, v, &size, minHeap);
    // push(3, v, &size, minHeap);

    int a[] = {1, 7, 2, 3, 9, 5};
    int size = 0;
    int v[1000];
    for (int i = 0; i < 6; i++){
        push(a[i], v, &size, minHeap);
    }
    while (size != 0){
        cout << top(v) << " ";
        pop(v, &size, minHeap);
    }
    cout << endl;
    return 0;
}