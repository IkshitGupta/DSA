#include <bits/stdc++.h>
using namespace std;
// stores address of next and prev
class node{
    public:
    int data;
    node* next;
    node* prev;
    node (int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if (head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node* &head, int val){
    if (head == NULL){
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void printll(node* head){
    while (head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
}

int main(){
    node* head = NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 4);
    insertAtTail(head, 7);
    insertAtHead(head, 2);
    printll(head);
    return 0;
}