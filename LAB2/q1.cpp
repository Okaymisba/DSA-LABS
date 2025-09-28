#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* insertAtBeginning(Node*head, int value){
    Node* newnode = new Node(value);
    newnode->next = head;
    head = newnode;
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    cout << "Before Inserting: ";
    printList(head);
    head = insertAtBeginning(head, 30);
    cout << "After Inserting: ";
    printList(head);
    return 0;
}