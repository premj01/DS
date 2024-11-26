#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Passenger
{
public:
    string name;
    int age;
    string gender;
    int ticketNumber;

    Passenger(string n, int a, string g, int t) : name(n), age(a), gender(g), ticketNumber(t) {}
};

class RailwayReservation
{
private:
    queue<Passenger> reservationQueue;
    int ticketCounter;

public:
    RailwayReservation() : ticketCounter(1) {}

    void bookTicket(string name, int age, string gender)
    {
        Passenger *p = new Passenger(name, age, gender, ticketCounter++);
        reservationQueue.push(*p);
        cout << "Ticket booked successfully! Ticket Number: " << p->ticketNumber << endl;
    }

    void cancelTicket()
    {
        if (reservationQueue.empty())
        {
            cout << "No reservations to cancel." << endl;
        }
        else
        {
            Passenger p = reservationQueue.front();
            reservationQueue.pop();
            cout << "Ticket Number " << p.ticketNumber << " for " << p.name << " has been cancelled." << endl;
        }
    }

    void displayReservations()
    {
        if (reservationQueue.empty())
        {
            cout << "No reservations in the queue." << endl;
        }
        else
        {
            queue<Passenger> tempQueue = reservationQueue;
            cout << "Current reservations:" << endl;
            while (!tempQueue.empty())
            {
                Passenger p = tempQueue.front();
                tempQueue.pop();
                cout << "Ticket Number: " << p.ticketNumber << ", Name: " << p.name << ", Age: " << p.age << ", Gender: " << p.gender << endl;
            }
        }
    }
};

int main()
{
    RailwayReservation rr;
    int choice;
    string name;
    int age;
    string gender;

    while (true)
    {
        cout << "\n1. Book Ticket\n2. Cancel Ticket\n3. Display Reservations\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;
            rr.bookTicket(name, age, gender);
            break;
        case 2:
            rr.cancelTicket();
            break;
        case 3:
            rr.displayReservations();
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
