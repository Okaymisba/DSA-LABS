#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* top = NULL;

void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    cout << val << " pushed into stack.\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return;
    }
    cout << top->data << " popped from stack.\n";
    Node* temp = top;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Top element: " << top->data << endl;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack elements: ";
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isEmpty() {
    return top == NULL;
}

int main() {
    int choice, val;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
