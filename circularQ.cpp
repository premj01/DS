#include <iostream>
using namespace std;

#define SIZE 5  

class CircularQueue {
private:
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;  
        } else {
            int element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
            return element;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front -> " << front << endl;
            cout << "Items -> ";
            for (int i = front; i != rear; i = (i + 1) % SIZE) {
                cout << items[i] << " ";
            }
            cout << items[rear] << endl;
            cout << "Rear -> " << rear << endl;
        }
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CircularQueue q;
    int choice, element;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to enqueue: ";
                cin >> element;
                q.enqueue(element);
                break;
            case 2:
                element = q.dequeue();
                if (element != -1) {
                    cout << "Dequeued element: " << element << endl;
                }
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
