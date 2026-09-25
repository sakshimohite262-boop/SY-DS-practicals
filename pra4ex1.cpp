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

    cout << "Team added.\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "No teams available.";
        return;
    }

    Team *temp = head;

    cout << "\n--- Round Robin Teams ---\n";

    do
    {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    while (temp != head);

    cout << "(Back to " << head->name << ")";
}

int main()
{
    int n;

    cout << "Enter number of teams: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        addTeam();
    }

    display();

    return 0;
}
