// continuous memory is not required data can be stored at different places.
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data; //  data at each node
    node* next; // pointer storing address address of next node
    node (int val){
        data = val;
        next = NULL; // by default next pointer is null
    }
};

int lenll(node *head){
    int l = 0;
    while (head != NULL){
        head = head->next;
        l++;
    }
    return l;
}

void insertAtHead(node* &head, int data){  // passing pointer variable head by reference
    node* n = new node(data);
    n -> next = head;
    head = n;
}

void insertAtTail(node* &head, int data){
    if (head == NULL){
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail ->next != NULL){
        tail = tail -> next;
    }
    tail ->next = new node(data);
    return;
}

void inserAtP(node* &head, int data, int p){
    if (head == NULL || p == 0){
        insertAtHead(head, data);
    }
    else if (p > lenll(head)){
        insertAtTail(head, data);
    }
    else {
        int jump = 1;
        node* temp = head;
        while (jump <= p - 1){
            temp = temp -> next;
            jump++;
        }
        node* n = new node(data);
        n ->next = temp->next;
        temp ->next = n;
    }
}

void printll(node* head){
    node *temp = head;
    while (temp != NULL){
        cout << temp -> data << "-> ";
        temp = temp->next;
    }
}

void delAtHead (node* &head){
    if (head == NULL){
        return;
    }
    node* temp = head;
    head = head ->next;
    delete temp; // will free memory
}

void delAtTail (node* &head){
    node* prev = NULL;
    node* temp = head;
    while(temp -> next != NULL) {
        prev = temp;
        temp = temp -> next;
    }
    prev->next = NULL;
    delete temp;
}

void delAtP (node* &head, int p){
    if (p == 0){
        delAtHead(head);
    }
    else {
        int jump = 1;
        node* temp = head;
        node* prev = NULL;
        while (jump <= p){
            prev = temp;
            temp = temp ->next;
            jump ++;
        }
        prev -> next = temp ->next;
        delete temp;
    }
}

int searchll(node* head, int val){
    int ind = 0;
    while (head != NULL){
        if (head ->data == val){
            return ind;
        }
        ind ++;
        head = head->next;
    }
    return -1;
}

ostream& operator<<(ostream& os, node* head){
    printll(head);
    return os;
}

// Parts
// ans                  start
// 			            a -> b -> c -> d
// a -> 			    b -> c -> d
// b -> a -> 		    c -> d
// c -> b -> a -> 		d
// d -> c -> b -> a	    NULL
void reversell (node* &head){
    node* start = head;
    node* ans = NULL;
    node* temp;
    while (start != NULL){
        temp = start->next;
        start->next = ans;
        ans = start;
        start = temp;
    }
    head = ans;
}

// 1 2 3 4      return 2
// 1 2 3 4 5    return 3
node* midP(node* head){
    // Runner technique, when fast at last slow will be at middle (as l is not known)
    if (head == NULL || head ->next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while (fast!=NULL && fast -> next != NULL){
        fast = fast ->next->next;
        slow = slow->next;
    }
    return slow;
}

// node* klast(node* head){
    // fast start from kth
    // then move both slow and fast one step, when fast at null slow at kth from last
// }

node* merge(node* a, node* b){
    // way 1 for O(n) insertion
    node c(0);
    node* p = &c;
    // way2
    // ListNode* z = new ListNode(0);   // in this operations on z and later p -> next is answer
    // ListNode* p = z;
    while(a != NULL && b != NULL){
        if (a -> data < b -> data){
            p -> next = a;
            a = a -> next;
        }
        else{
            p -> next = b;
            b = b -> next;
        }
        p = p -> next;
    }
    if (a != NULL){
        p -> next = a;
    }
    else if (b != NULL){
        p -> next = b;
    }
    return c.next;  // not a pointer
}

node* mergeSortll(node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    node* mid = midP(head);
    node* a = head;
    node* b = mid -> next;
    mid -> next = NULL;
    a = mergeSortll(a);
    b = mergeSortll(b);
    node* c = merge(a, b);
    return c;
}

bool detectCycle(node* head){
    // Floyd's cycle detection
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast ->next->next;
        slow = slow ->next;
        if (fast == slow){
            return 1;
        }
    }
    return 0;
}

void rotate(node* &head, int k){
    node* temp = head;
    int jump = lenll(head) - k - 1;
    for (int i = 0; i < jump; i++){
        temp = temp ->next;
    }
    node* n = temp->next;
    node* n2 = temp->next;
    temp->next = NULL;
    while (n ->next != NULL){
        n = n ->next;
    }
    n ->next = head;
    head = n2;
}

int main(){
    
    return 0;
}