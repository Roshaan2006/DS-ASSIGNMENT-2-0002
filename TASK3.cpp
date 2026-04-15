#include <iostream>
using namespace std;

class CQ {
    int* arr;
    int front, rear, size;

public:
    CQ(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    ~CQ() {
        delete[] arr;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
        cout << val << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }

        cout << arr[front] << " removed\n";

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue empty\n";
        }
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }

        cout << "Queue: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of circular queue: ";
    cin >> size;

    CQ q(size);

    int choice, val;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
            break;

        case 2:
            q.dequeue();
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