#include <iostream>
using namespace std;

struct Node
{
    int id;
    string name;
    Node *next;
};

Node *head = NULL;

void insert()
{
    Node *newNode = new Node;

    cout << "Enter ID: ";
    cin >> newNode->id;

    cout << "Enter Name: ";
    cin >> newNode->name;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "ID: " << temp->id
             << " Name: " << temp->name << endl;

        temp = temp->next;
    }
}

void search()
{
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Employee Found: " << temp->name << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Employee not found" << endl;
}


void removeEmployee()
{
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Employee not found" << endl;
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    cout << "Employee deleted" << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            insert();
        else if (choice == 2)
            display();
        else if (choice == 3)
            search();
        else if (choice == 4)
            removeEmployee();
        else if (choice == 5)
            cout << "Exit";
        else
            cout << "Invalid choice";

    } while (choice != 5);

    return 0;
}
