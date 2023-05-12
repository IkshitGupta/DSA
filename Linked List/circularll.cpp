#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if (head == NULL){
        n -> next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp -> next != head){
        temp = temp->next;
    }
    temp ->next = n;
    n -> next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    if (head == NULL){
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp -> next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void printll(node* head){
    node* temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    printll(head);
    return 0;
}