#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() { return top == SIZE - 1; }
    bool isEmpty() { return top == -1; }

    void push(int item) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = item;
        cout << "Item inserted successfully: " << item << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Deleted element: " << arr[top--] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements are:\n";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};


int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
}
