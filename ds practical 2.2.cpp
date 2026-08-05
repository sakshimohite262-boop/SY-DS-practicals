#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = 10;
    newNode->prev = NULL;
    newNode->next = NULL;

    cout << "Data = " << newNode->data << endl;

    free(newNode);

    return 0;
}
