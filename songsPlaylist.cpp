#include <iostream>
using namespace std;

class song
{
public:
    int id;
    string name, author;
    float duration;
    song *next, *prev;
    song() {}
    song(int id, string name, string author, float duration) : id(id), name(name), author(author), duration(duration), next(nullptr), prev(nullptr) {}
};

class playlist
{
private:
    song *start, *end;

public:
    playlist() { start = end = nullptr; }
    void insert(int id, string name, string author, float duration)
    {
        song *tmp = new song(id, name, author, duration);

        if (start == nullptr)
        {
            start = end = tmp;
            tmp->next = tmp->prev = tmp;
        }
        else
        {
            tmp->prev = end;
            tmp->next = start;
            end->next = tmp;
            start->prev = tmp;
            end = tmp;
        }
    }
    void insert(int idx, int id, string name, string author, float duration)
    {
        song *tmp = new song(id, name, author, duration);
        if (start == nullptr)
        {
            start = end = start->prev = end->next = tmp;
        }
        else
        {
            song *i = start;
            while (--idx)
            {
                i = i->next;
            }
            tmp->next = i->next;
            tmp->prev = i;
            i->next->prev = tmp;
            i->next = tmp;
        }
    }
    bool remove()
    {
        song *i = end;
        if (start == nullptr)
            return false;
        if (start == end)
        {
            start = end = nullptr;
            delete (i);
            return true;
        }
        i->prev->next = i->next;
        i->next->prev = i->prev;
        delete (i);
        return true;
    }
    bool remove(int idx)
    {
        song *i = start;
        if (start == nullptr)
            return false;
        while (--idx)
        {
            i = i->next;
        }
        if (i == nullptr)
            return false;

        i->next->prev = i->prev;
        i->prev->next = i->next;
        delete (i);
        return true;
    }
    void display()
    {
        cout << endl
             << endl;
        song *i = start;
        while (i->next != start)
        {
            cout << i->id << "  " << i->name << "  " << i->author << "  " << i->duration << " , " << endl;
            i = i->next;
        }
    }
};
void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert song at the end\n";
    cout << "2. Insert song at a specific position\n";
    cout << "3. Remove the last song\n";
    cout << "4. Remove song from a specific position\n";
    cout << "5. Display playlist\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    playlist *p = new playlist();
    p->insert(1, "Alone pt.2", "Alan Walker", 4.25);
    p->insert(2, "Shape of You", "Ed Sheeran", 4.24);
    p->insert(3, "Blinding Lights", "The Weeknd", 3.22);
    p->insert(4, "Dance Monkey", "Tones and I", 3.29);
    p->insert(5, "Someone You Loved", "Lewis Capaldi", 3.02);
    p->insert(6, "Senorita", "Shawn Mendes & Camila Cabello", 3.11);
    p->insert(7, "Bad Guy", "Billie Eilish", 3.14);
    p->insert(8, "Sunflower", "Post Malone & Swae Lee", 2.38);
    p->insert(9, "Memories", "Maroon 5", 3.09);
    p->insert(10, "Old Town Road", "Lil Nas X", 2.37);

    int choice, id, idx;
    string name, author;
    float duration;

    duration;
    while (true)
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter song id: ";
            cin >> id;
            cout << "Enter song name: ";
            cin >> name;
            cout << "Enter song author: ";
            cin >> author;
            cout << "Enter song duration: ";
            cin >> duration;
            p->insert(id, name, author, duration);
            break;
        case 2:
            cout << "Enter position to insert: ";
            cin >> idx;
            cout << "Enter song id: ";
            cin >> id;
            cout << "Enter song name: ";
            cin >> name;
            cout << "Enter song author: ";
            cin >> author;
            cout << "Enter song duration: ";
            cin >> duration;
            p->insert(idx, id, name, author, duration);
            break;
        case 3:
            if (p->remove())
            {
                cout << "Removed the last song from the playlist." << endl;
            }
            else
            {
                cout << "Playlist is empty. No song to remove." << endl;
            }
            break;
        case 4:
            cout << "Enter position to remove: ";
            cin >> idx;
            if (p->remove(idx))
            {
                cout << "Removed song from position " << idx << "." << endl;
            }
            else
            {
                cout << "Invalid position. No song removed." << endl;
            }
            break;
        case 5:
            p->display();
            break;
        case 6:
            delete p;
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}