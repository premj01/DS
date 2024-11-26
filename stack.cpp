#include <iostream>
using namespace std;
#define MAX 5
class stack
{
private:
    int arr[MAX], top;

public:
    stack() : top(-1) {}
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top >= MAX - 1;
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack is Full";
        }
        else
        {
            arr[++top] = data;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty";
            return 0;
        }
        else
        {
            top = top - 1;
            return arr[top + 1];
        }
    }
    int peek()
    {
        return arr[top];
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack *s = new stack();
    int choice;
    while (true)
    {
        cout << "1.Push" << endl;
        cout << "2.POP" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Display" << endl;
        cout << "5.Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data :";
            cin >> data;
            s->push(data);
            break;

        case 2:
            cout << s->pop() << " has been poped !!" << endl;
            break;

        case 3:
            cout << s->peek() << " is now at top";
            break;
        case 4:
            s->display();
            break;
        case 5:
            exit(0);

        default:
            break;
        }
    }

    return 0;
}