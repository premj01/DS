#include <iostream>
using namespace std;
#define MAX 10
class book
{
public:
    int bookId;
    string bookname, author;
    static int bookCounter;
    void setData(string bookname, string author)
    {
        this->bookId = ++bookCounter;
        this->bookname = bookname;
        this->author = author;
    }
    void display()
    {
        cout << "Book " << bookId << "\t" << bookname << "\t" << author << endl;
    }
};
int book::bookCounter = 0;

class bookStore
{
public:
    book arr[MAX];
    int size;
    bookStore()
    {
        size = -1;
    }
    void addBook(string name, string author)
    {
        if (size < MAX - 1)
        {
            book *p = new book();
            p->setData(name, author);
            arr[++size] = *p;
            delete p;
        }
        else
        {
            cout << "BookStore is full, cannot add more books." << endl;
        }
    }
    void SortBook()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                if (arr[j].bookname > arr[j + 1].bookname)
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
    void display()
    {
        for (int i = 0; i <= size; i++)
        {
            arr[i].display();
        }
    }
};
int main()
{
    bookStore b;
    int choice;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Sort Books\n";
        cout << "3. Display Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, author;
            cout << "Enter book name: ";
            cin >> name;
            cout << "Enter author name: ";
            cin >> author;
            b.addBook(name, author);
            break;
        }
        case 2:
            b.SortBook();
            cout << "Books sorted successfully!" << endl;
            break;
        case 3:
            b.display();
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