#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;
int count = 0;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    count++;
    cout << value << " enqueued into queue.\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!\n";
        return;
    }

    Node* temp = front;
    cout << temp->data << " dequeued from queue.\n";
    front = front->next;
    if (front == NULL) rear = NULL;

    delete temp;
    count--;
}

void peek() {
    if (front == NULL)
        cout << "Queue is empty — nothing to peek.\n";
    else
        cout << "Front element is: " << front->data << endl;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void countElements() {
    cout << "Total number of elements in queue: " << count << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Count Elements\n6. Exit\n";
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
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                countElements();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
