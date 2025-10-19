#include <iostream>
#define SIZE 5
using namespace std;

int queueArr[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (front == -1) front = 0;
    queueArr[++rear] = value;
    cout << value << " enqueued into queue.\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << queueArr[front++] << " dequeued from queue.\n";
}

void peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element: " << queueArr[front] << endl;
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queueArr[i] << " ";
    cout << endl;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return rear == SIZE - 1;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (isFull())
                    cout << "Queue is full!\n";
                else {
                    cout << "Enter value: ";
                    cin >> value;
                    enqueue(value);
                }
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
                if (isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 6:
                if (isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
