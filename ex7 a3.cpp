#include <stdio.h>
#define MAX 5

struct Request {
    int id;
    int priority; 
};

struct Request queue[MAX];
int front = -1, rear = -1;


void enqueue(int id, int priority) {
    int i, j;
    struct Request temp;

    if ((rear + 1) % MAX == front) {
        printf("Call queue is full!\n");
        return;
    }

    struct Request newRequest;
    newRequest.id = id;
    newRequest.priority = priority;

    if (front == -1) {
        front = rear = 0;
        queue[rear] = newRequest;
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = newRequest;
    }


    i = front;
    while (i != rear) {
        j = (i + 1) % MAX;

        if (queue[i].priority > queue[j].priority) {
            temp = queue[i];
            queue[i] = queue[j];
            queue[j] = temp;
        }

        i = j;
    }

    printf("Request %d added successfully.\n", id);
}


void dequeue() {
    if (front == -1) {
        printf("No customer requests waiting.\n");
        return;
    }

    printf("Processing customer %d (",
           queue[front].id);

    if (queue[front].priority == 1)
        printf("High Priority)\n");
    else
        printf("Normal Priority)\n");

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void display() {
    int i;

    if (front == -1) {
        printf("No requests in queue.\n");
        return;
    }

    printf("\nWaiting Customer Requests:\n");
    i = front;

    while (1) {
        printf("Customer ID: %d | Priority: %s\n",
               queue[i].id,
               queue[i].priority == 1 ? "High" : "Normal");

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main() {
    int choice, id, priority;

    do {
        printf("\n--- Call Center Support System ---\n");
        printf("1. Add Customer Request\n");
        printf("2. Process Customer Request\n");
        printf("3. Display Waiting Requests\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer ID: ");
                scanf("%d", &id);

                printf("Enter priority (1=High, 2=Normal): ");
                scanf("%d", &priority);

                if (priority != 1 && priority != 2) {
                    printf("Invalid priority!\n");
                    break;
                }

                enqueue(id, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting system.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
