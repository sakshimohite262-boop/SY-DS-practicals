#include <iostream>
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
}

void search()
{
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    Employee *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nEmployee Found!";
            cout << "\nID: " << temp->id;
            cout << "\nName: " << temp->name;
            return;
        }

        temp = temp->next;
    }

    cout << "\nEmployee Not Found.";
}

void display()
{
    Employee *temp = head;

    cout << "\n--- Employee Records ---\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id
             << "  Name: " << temp->name << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Insert Employee";
        cout << "\n2. Search Employee";
        cout << "\n3. Display Employees";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                search();
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
