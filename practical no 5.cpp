#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][100];
int top = -1;

void push(char page[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    strcpy(stack[++top], page);
}


void pop() {
    if (top == -1) {
        printf("No previous page available.\n");
        return;
    }

    printf("Going back from: %s\n", stack[top]);
    top--;
}
s
void display() {
    if (top == -1) {
        printf("History is empty.\n");
        return;
    }

    printf("\nBrowsing History:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);
    }
}

int main() {
    push("google.com");
    push("youtube.com");
    push("github.com");
    push("stackoverflow.com");

    display();

    printf("\n--- Back Operation ---\n");
    pop();

    printf("\n--- Back Operation ---\n");
    pop();

    display();

    return 0;
}

