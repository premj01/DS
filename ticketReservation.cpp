#include <iostream>
using namespace std;
#define MAX 100

class Ticket
{
public:
    int ticketID;
    string name, destination;
    static int ticketCounter;
    Ticket() {}

    void putData(string name, string destination)
    {
        this->name = name;
        this->destination = destination;
        ticketCounter++;
        this->ticketID = ticketCounter;
    }
    void printTicket()
    {
        cout << this->ticketID << "\t" << this->name << "\t" << this->destination<<endl;
    }
};
int Ticket::ticketCounter = 0;

class Queue
{
public:
    Ticket arr[MAX];
    int front, rear;
    Queue()
    {
        front = rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (front == 0 && rear == MAX - 1 || front == rear + 1);
    }
    bool enqueue(Ticket t)
    {
        if (isFull())
        {
            cout << "All tickets are sold" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            arr[rear] = t;
            return true;
        }
    }
    Ticket dequeue()
    {
        if (isEmpty())
        {
            cout << "All seats are empty";
        }
        else
        {
            Ticket t = arr[front];

            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
            return t;
        }
    }
    Ticket peek()
    {
        if (isEmpty())
        {
            cout << "All seats are empty";
        }
        else
        {
            return arr[front];
        }
    }
};
class reservationSystem
{
public:
    Queue q;
    void makereservation(string name, string destination)
    {
        Ticket *t = new Ticket();
        t->putData(name, destination);
        if (q.enqueue(*t))
        {
            cout << "ticket with id " << t->ticketID << " name :" << t->name << " booked successfully !!!" << endl;
        }
    }
    void cancleTicket(int id)
    {
        Queue temp;
        bool flagFound = false;
        while (!q.isEmpty())
        {
            Ticket t = q.dequeue();
            if (id == t.ticketID)
            {
                cout << "Ticket with ID " << t.ticketID << " canceled successfully!" << endl;
                flagFound = true;
            }
            else
            {
                temp.enqueue(t);
            }
        }
        q = temp;
    }
    void displayTicket()
    {
        Queue temp;
        while (!q.isEmpty())
        {
            Ticket t = q.dequeue();
            t.printTicket();
            temp.enqueue(t);
        }
        q = temp;
    }
};
void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Make Reservation\n";
    cout << "2. Cancel Ticket\n";
    cout << "3. Display Tickets\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    reservationSystem rs;
    int choice;
    while (true)
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string name, destination;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter destination: ";
            cin >> destination;
            rs.makereservation(name, destination);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter ticket ID to cancel: ";
            cin >> id;
            rs.cancleTicket(id);
            break;
        }
        case 3:
            rs.displayTicket();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}