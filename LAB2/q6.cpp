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
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* sortList(Node* head) {
    if(!head || !head->next) return head;
    Node*curr = head;
    Node*sorted = NULL;
    while(curr != NULL){
        Node*nextnode = curr->next;
        if(sorted == NULL || sorted->data >= curr->data){
            curr->next = sorted;
            sorted = curr;
        } else {
            Node*temp = sorted;
            while(temp->next != NULL && temp->next->data < curr->data){
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = nextnode;

    }
    return sorted;
}

int main(){

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Unsorted Linked List: ";
    printList(head);
    cout << "Sorted Linked List: ";
    head = sortList(head);
    printList(head);
    return 0;
}