#include <iostream>
#include <string>
using namespace std;

struct Team
 {
    string name;
    Team* next;

    Team(string n) {
        name = n;
        next = NULL;
    }
};

class CircularLinkedList
 {
private:
    Team* tail;

public:
    CircularLinkedList()
	 {
        tail = NULL;
    }

    void addTeam(string name) {
        Team* newTeam = new Team(name);

        if (tail == NULL) {
            tail = newTeam;
            tail->next = tail;
        } else {
            newTeam->next = tail->next;
            tail->next = newTeam;
            tail = newTeam;
        }
    }

    void roundRobin(int rounds)
	 {
        if (tail ==NULL) {
            cout << "No teams available.\n";
            return;
        }

        Team* current = tail->next;

        cout << "\nRound Robin Schedule:\n";

        for (int i = 1; i <= rounds; i++)
		 {
            cout << "Round " << i << ": "
                 << current->name << " plays.\n";

            current = current->next;
        }
    }

    void displayTeams() 
	{
        if (tail == NULL)
		 {
            cout << "No teams available.\n";
            return;
        }

        Team* current = tail->next;

        cout << "\nTeams: ";

        do {
            cout << current->name << " -> ";
            current = current->next;
        } while (current != tail->next);

        cout << "(back to " << tail->next->name << ")\n";
    }

    ~CircularLinkedList()
	 {
        if (tail == NULL)
            return;

        Team* head = tail->next;
        Team* current = head;

        while (current->next != head)
		 {
            Team* temp = current;
            current = current->next;
            delete temp;
        }

        delete current;
    }
};

int main()
 {
    CircularLinkedList tournament;

    tournament.addTeam("Team A");
    tournament.addTeam("Team B");
    tournament.addTeam("Team C");
    tournament.addTeam("Team D");

    tournament.displayTeams();

    tournament.roundRobin(8);

    return 0;
}
