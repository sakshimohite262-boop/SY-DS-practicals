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

    newSong->next = NULL;
    newSong->prev = NULL;

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
}

void forward()
{
    Song *temp = head;

    cout << "\nForward Playlist:\n";

    while (temp != NULL)
    {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

void backward()
{
    if (head == NULL)
        return;

    Song *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    cout << "\nBackward Playlist:\n";

    while (temp != NULL)
    {
        cout << temp->name << endl;
        temp = temp->prev;
    }
}

int main()
{
    int n;

    cout << "Enter number of songs: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        addSong();

    forward();
    backward();

    return 0;
}
