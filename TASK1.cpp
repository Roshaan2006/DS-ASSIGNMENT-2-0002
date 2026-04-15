#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;

        cout << val << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        }
        else {
            cout << "Top element: " << top->data << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            s.display();
            break;

        case 2:
            s.pop();
            s.display();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid\n";
        }

    } while (choice != 5);

    return 0;
}