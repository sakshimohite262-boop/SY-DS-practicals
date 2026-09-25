#include <iostream>
using namespace std;

struct Team
{
    string name;
    Team *next;
};

Team *head = NULL;

void addTeam()
{
    Team *newTeam = new Team;

    cout << "Enter team name: ";
    cin >> newTeam->name;

    if (head == NULL)
    {
        head = newTeam;
        newTeam->next = head;
    }
    else
    {
        Team *temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newTeam;
        newTeam->next = head;
    }
}

void playRounds(int rounds)
{
    if (head == NULL)
        return;

    Team *temp = head;

    for (int r = 1; r <= rounds; r++)
    {
        cout << "\nRound " << r << ":\n";

        do
        {
            cout << temp->name << " gets a turn\n";
            temp = temp->next;
        }
        while (temp != head);
    }
}

int main()
{
    int n, rounds;

    cout << "Enter number of teams: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        addTeam();

    cout << "\nEnter number of rounds: ";
    cin >> rounds;

    playRounds(rounds);

    return 0;
}
