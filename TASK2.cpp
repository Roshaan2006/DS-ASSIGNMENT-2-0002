#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << val << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " removed\n";
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue empty\n";
        }
        else {
            cout << "Front: " << front->data << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
            q.display();
            break;

        case 2:
            q.dequeue();
            q.display();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}