#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    cout << value << " enqueued into circular queue.\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!\n";
        return;
    }

    if (front == rear) {
        cout << front->data << " dequeued from circular queue.\n";
        delete front;
        front = rear = NULL;
    } else {
        Node* temp = front;
        cout << temp->data << " dequeued from circular queue.\n";
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Circular Queue elements: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
