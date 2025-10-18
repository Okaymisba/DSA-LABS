#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top1 = NULL;
Node* top2 = NULL;

void push(Node*& top, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop(Node*& top) {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

void display(Node* top) {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseStack() {
    while (top1 != NULL) {
        int val = pop(top1);
        push(top2, val);
    }
    cout << "Stack reversed successfully!\n";
}

int main() {
    push(top1, 56);
    push(top1, 34);
    push(top1, 87);

    cout << "Original stack: ";
    display(top1);

    reverseStack();

    cout << "Reversed stack: ";
    display(top2);

    return 0;
}
