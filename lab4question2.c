#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Stack using Array */
int stack[MAX];
int top = -1;

void arrayStack() {
    int choice, value, i;

    while (1) {
        printf("\n--- STACK USING ARRAY ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top == MAX - 1) {
                    printf("Stack Overflow\n");
                }
                else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    stack[++top] = value;
                    printf("%d pushed into stack\n", value);
                }
                break;

            case 2:
                if (top == -1) {
                    printf("Stack Underflow\n");
                }
                else {
                    printf("Deleted: %d\n", stack[top--]);
                }
                break;

            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                }
                else {
                    printf("Stack: ");
                    for (i = top; i >= 0; i--)
                        printf("%d ", stack[i]);
                    printf("\n");
                }
                break;

            case 4:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

/* Queue using Array */
int queue[MAX];
int front = -1, rear = -1;

void arrayQueue() {
    int choice, value, i;

    while (1) {
        printf("\n--- QUEUE USING ARRAY ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == MAX - 1) {
                    printf("Queue Overflow\n");
                }
                else {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);

                    if (front == -1)
                        front = 0;

                    queue[++rear] = value;
                    printf("%d inserted into queue\n", value);
                }
                break;

            case 2:
                if (front == -1 || front > rear) {
                    printf("Queue Underflow\n");
                }
                else {
                    printf("Deleted: %d\n", queue[front++]);

                    if (front > rear)
                        front = rear = -1;
                }
                break;

            case 3:
                if (front == -1) {
                    printf("Queue is empty\n");
                }
                else {
                    printf("Queue: ");
                    for (i = front; i <= rear; i++)
                        printf("%d ", queue[i]);
                    printf("\n");
                }
                break;

            case 4:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

/* Node structure */
struct Node {
    int data;
    struct Node *next;
};

/* Stack using Linked List */
struct Node *stackTop = NULL;

void linkedStack() {
    int choice, value;
    struct Node *newNode, *temp;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newNode = (struct Node *)malloc(sizeof(struct Node));

                printf("Enter value to push: ");
                scanf("%d", &value);

                newNode->data = value;
                newNode->next = stackTop;
                stackTop = newNode;

                printf("%d pushed into stack\n", value);
                break;

            case 2:
                if (stackTop == NULL) {
                    printf("Stack Underflow\n");
                }
                else {
                    temp = stackTop;
                    printf("Deleted: %d\n", temp->data);
                    stackTop = stackTop->next;
                    free(temp);
                }
                break;

            case 3:
                if (stackTop == NULL) {
                    printf("Stack is empty\n");
                }
                else {
                    temp = stackTop;
                    printf("Stack: ");

                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }

                    printf("\n");
                }
                break;

            case 4:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

/* Queue using Linked List */
struct Node *queueFront = NULL;
struct Node *queueRear = NULL;

void linkedQueue() {
    int choice, value;
    struct Node *newNode, *temp;

    while (1) {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newNode = (struct Node *)malloc(sizeof(struct Node));

                printf("Enter value to insert: ");
                scanf("%d", &value);

                newNode->data = value;
                newNode->next = NULL;

                if (queueRear == NULL) {
                    queueFront = queueRear = newNode;
                }
                else {
                    queueRear->next = newNode;
                    queueRear = newNode;
                }

                printf("%d inserted into queue\n", value);
                break;

            case 2:
                if (queueFront == NULL) {
                    printf("Queue Underflow\n");
                }
                else {
                    temp = queueFront;

                    printf("Deleted: %d\n", temp->data);

                    queueFront = queueFront->next;

                    if (queueFront == NULL)
                        queueRear = NULL;

                    free(temp);
                }
                break;

            case 3:
                if (queueFront == NULL) {
                    printf("Queue is empty\n");
                }
                else {
                    temp = queueFront;

                    printf("Queue: ");

                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }

                    printf("\n");
                }
                break;

            case 4:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n========== DATA STRUCTURES ==========\n");
        printf("1. Stack using Array\n");
        printf("2. Queue using Array\n");
        printf("3. Stack using Linked List\n");
        printf("4. Queue using Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arrayStack();
                break;

            case 2:
                arrayQueue();
                break;

            case 3:
                linkedStack();
                break;

            case 4:
                linkedQueue();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
