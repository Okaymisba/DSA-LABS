#include <iostream>
#define SIZE 5
using namespace std;

int queueArr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queueArr[rear] = value;
    cout << value << " enqueued.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << queueArr[front] << " dequeued.\n";
    if (front == rear)
        front = rear = -1; // Queue becomes empty
    else
        front = (front + 1) % SIZE;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
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
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
