#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};


void BackwardTraversal(Node* tail){
    Node* temp = tail;
    cout << "Backward Traversal: ";
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    Node* tail = head->next->next->next;
    BackwardTraversal(tail);
    return 0;
}