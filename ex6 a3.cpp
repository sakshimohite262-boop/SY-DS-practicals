#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Array queue
int arr[MAX];
int af = -1, ar = -1;

// Linked list structure
struct Node {
    int id;
    struct Node *next;
};

// Linked list queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue using array
void arrayEnqueue(int id) {
    if (ar == MAX - 1) {
        printf("Array queue is full!\n");
        return;
    }

    if (af == -1)
        af = 0;

    arr[++ar] = id;
    printf("Reservation %d added to array queue.\n", id);
}

// Dequeue using array
void arrayDequeue() {
    if (af == -1) {
        printf("Array queue is empty!\n");
        return;
    }

    printf("Processed reservation: %d\n", arr[af++]);

    if (af > ar)
        af = ar = -1;
}

// Display array queue
void arrayDisplay() {
    int i;

    if (af == -1) {
        printf("Array queue is empty!\n");
        return;
    }

    printf("Array queue: ");
    for (i = af; i <= ar; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Enqueue using linked list
void listEnqueue(int id) {
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    n->id = id;
    n->next = NULL;

    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }

    printf("Reservation %d added to linked list queue.\n", id);
}

// Dequeue using linked list
void listDequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Linked list queue is empty!\n");
        return;
    }

    temp = front;
    printf("Processed reservation: %d\n", temp->id);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Display linked list queue
void listDisplay() {
    struct Node *temp;

    if (front == NULL) {
        printf("Linked list queue is empty!\n");
        return;
    }

    temp = front;
    printf("Linked list queue: ");

    while (temp != NULL) {
        printf("%d ", temp->id);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {
    int choice, id;

    do {
        printf("\n--- Ticket Reservation System ---\n");
        printf("1. Array Enqueue\n");
        printf("2. Array Dequeue\n");
        printf("3. Display Array Queue\n");
        printf("4. Linked List Enqueue\n");
        printf("5. Linked List Dequeue\n");
        printf("6. Display Linked List Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter reservation ID: ");
                if (scanf("%d", &id) != 1)
                    return 1;
                arrayEnqueue(id);
                break;

            case 2:
                arrayDequeue();
                break;

            case 3:
                arrayDisplay();
                break;

            case 4:
                printf("Enter reservation ID: ");
                if (scanf("%d", &id) != 1)
                    return 1;
                listEnqueue(id);
                break;

            case 5:
                listDequeue();
                break;

            case 6:
                listDisplay();
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    // Free remaining linked list nodes
    while (front != NULL) {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
