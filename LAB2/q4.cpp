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

void SearchElement(Node* head, int key){
    Node* temp = head;
    int index = 0; // Index start from 0
    while(temp != NULL){
        if(temp->data == key){
            cout << key << " found in the list at index " << index << endl;
            break;
        }
        index++;
        temp = temp->next;
    }
    if(temp == NULL) cout << key << " not found in the list." << endl;
}
int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout << "Linked List: ";
    printList(head);
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    SearchElement(head, key);
    
    return 0;
}