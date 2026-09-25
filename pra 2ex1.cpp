#include<iostream>
using namespace std;

struct Employee
{
    int id;
    string name;
    Employee *next;
};

Employee *head = NULL;

void insert()
{
    Employee *newNode = new Employee;

    cout << "Enter Employee ID: ";
    cin >> newNode->id;

    cout << "Enter Name: ";
    cin >> newNode->name;

    newNode->next = head;
    head = newNode;

    cout << "Employee inserted successfully.\n";
}

void del()
{
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    Employee *temp = head;
    Employee *prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Employee not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Employee deleted successfully.\n";
}

void display()
{
    Employee *temp = head;

    cout << "\n--- Employee Records ---\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id;
        cout << "  Name: " << temp->name << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                del();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
