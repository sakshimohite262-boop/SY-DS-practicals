#include <iostream>
using namespace std;

struct Song
{
    string name;
    Song *prev;
    Song *next;
};

Song *head = NULL;

void addSong()
{
    Song *newSong = new Song;

    cout << "Enter song name: ";
    cin >> newSong->name;

    newSong->prev = NULL;
    newSong->next = NULL;

    if (head == NULL)
    {
        head = newSong;
    }
    else
    {
        Song *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newSong;
        newSong->prev = temp;
    }

    cout << "Song added.\n";
}

void deleteSong()
{
    string name;
    cout << "Enter song to delete: ";
    cin >> name;

    Song *temp = head;

    while (temp != NULL && temp->name != name)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Song not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Song deleted.\n";
}

void display()
{
    Song *temp = head;

    cout << "\n--- Music Playlist ---\n";

    while (temp != NULL)
    {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Display Songs";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: display(); break;
            case 4: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
