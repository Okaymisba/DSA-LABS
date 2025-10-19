#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << val << " enqueued.\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << front->data << " dequeued.\n";
    Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void peek() {
    if (front == NULL)
        cout << "Queue is empty.\n";
    else
        cout << "Front element: " << front->data << endl;
}

int main() {
    int choice, val;
    while (true) {
        cout << "\n--- Linked List Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
