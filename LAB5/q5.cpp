#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};
Node* top = NULL;

void push(char c) {
    Node* newNode = new Node();
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) return '\0';
    char c = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return c;
}

bool isEmpty() {
    return top == NULL;
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(string expr) {
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{')
            push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty()) return false;
            char topChar = pop();
            if (!isMatchingPair(topChar, c)) return false;
        }
    }
    return isEmpty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Parentheses are balanced.\n";
    else
        cout << "Parentheses are NOT balanced.\n";

    return 0;
}
