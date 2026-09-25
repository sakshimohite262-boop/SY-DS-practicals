#include <iostream>
using namespace std;

struct Node
{
    string url;
    Node *next;
};

Node *top = NULL;

void push()
{
    Node *newNode = new Node;

    cout << "Enter webpage URL: ";
    cin >> newNode->url;

    newNode->next = top;
    top = newNode;

    cout << "Webpage visited.\n";
}

void pop()
{
    if (top == NULL)
    {
        cout << "No webpage to go back.";
    }
    else
    {
        Node *temp = top;

        cout << "Going back from: " << top->url << endl;

        top = top->next;
        delete temp;
    }
}

void peek()
{
    if (top == NULL)
        cout << "Stack is empty.";
    else
        cout << "Current webpage: " << top->url << endl;
}

void display()
{
    Node *temp = top;

    if (temp == NULL)
    {
        cout << "Stack is empty.";
        return;
    }

    cout << "\nVisited Webpages:\n";

    while (temp != NULL)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop (Back)";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}
