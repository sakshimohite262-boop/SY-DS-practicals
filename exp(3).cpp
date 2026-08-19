#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    Song* prev;
    Song* next;

    Song(string t) {
        title = t;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addSong(string title) {
        Song* newSong = new Song(title);

        if (head == NULL) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song added: " << title << endl;
    }

    void nextSong() {
        if (current == NULL) {
            cout << "Playlist is empty.\n";
        }
        else if (current->next == NULL) {
            cout << "Already at the last song.\n";
        }
        else {
            current = current->next;
            cout << "Playing: " << current->title << endl;
        }
    }

    void previousSong() {
        if (current == NULL) {
            cout << "Playlist is empty.\n";
        }
        else if (current->prev == NULL) {
            cout << "Already at the first song.\n";
        }
        else {
            current = current->prev;
            cout << "Playing: " << current->title << endl;
        }
    }

    void displayForward() {
        Song* temp = head;

        cout << "\nPlaylist Forward:\n";

        while (temp != NULL) {
            if (temp == current)
                cout << "-> ";

            cout << temp->title << endl;
            temp = temp->next;
        }
    }

  
    void displayBackward() {
        Song* temp = tail;

        cout << "\nPlaylist Backward:\n";

        while (temp != NULL) {
            if (temp == current)
                cout << "-> ";

            cout << temp->title << endl;
            temp = temp->prev;
        }
    }

    void showCurrent() {
        if (current == NULL)
            cout << "No song is currently playing.\n";
        else
            cout << "Currently playing: " << current->title << endl;
    }

  
    ~Playlist() {
        Song* temp = head;

        while (temp != NULL) {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Shape of You");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Believer");
    playlist.addSong("Perfect");

    playlist.displayForward();

    playlist.showCurrent();

    playlist.nextSong();
    playlist.nextSong();

    playlist.previousSong();

    playlist.displayForward();
    playlist.displayBackward();

    return 0;
}


	
	


