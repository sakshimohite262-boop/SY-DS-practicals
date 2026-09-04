#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title, artist;
    Song *prev, *next;

    Song(string t, string a)
	 {
        title = t;
        artist = a;
        prev = next = NULL;
    }
};

class Playlist {
    Song *head = NULL, *tail = NULL, *current = NULL;

public:
    void addSong(string title, string artist)
	 {
        Song *newSong = new Song(title, artist);

        if (head == NULL)
            head = tail = current = newSong;
        else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    void displayCurrent()
	 {
        if (current)
            cout << "Now Playing: " << current->title
                 << " - " << current->artist << endl;
        else
            cout << "No song selected.\n";
    }

    void nextSong()
	 {
        if (current && current->next) {
            current = current->next;
            displayCurrent();
        } else
            cout << "Already at the last song.\n";
    }

    void previousSong()
	 {
        if (current && current->prev)
		 {
            current = current->prev;
            displayCurrent();
        } else
            cout << "Already at the first song.\n";
    }

    void displayPlaylist() {
        Song *temp = head;
        cout << "\nPlaylist:\n";

        while (temp)
		 {
            cout << temp->title << " - " << temp->artist << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Dil Nu", "AP Dhillon");
    playlist.addSong("Laavan", "Jasmine Sandlas");
    playlist.addSong("Khat", "Navjot Ahuja");
    playlist.addSong("Romeo", "Taylor Swift");

    playlist.displayPlaylist();

    cout << "\nStarting Playlist:\n";
    playlist.displayCurrent();

    cout << "\nMoving Forward:\n";
    playlist.nextSong();
    playlist.nextSong();

    cout << "\nMoving Backward:\n";
    playlist.previousSong();
    playlist.previousSong();

    return 0;
}
