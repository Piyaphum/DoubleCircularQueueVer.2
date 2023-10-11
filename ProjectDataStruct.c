#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    struct node* next;
    char data;  // Changed from int to char
};

struct node* head = NULL;
struct node* rear = NULL;
int size = 0;

void enQueue_front();
void enQueue_rear();
void deQueue_front();
void deQueue_rear();
void display();

int main() {
    int choice;
    while(1) {
        printf("\n\n*****MENU*****\n");
        printf("Don't input more than 5\n");
        printf("1. Enqueue_front\n2. Enqueue_rear\n3. Dequeue_front\n4. Dequeue_rear\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (size < 5) {
                    enQueue_front();
                    display();
                    size++;
                } else {
                    printf("Queue is full. Cannot enqueue more items.\n");
                }
                break;
            case 2:
                if (size < 5) {
                    enQueue_rear();
                    display();
                    size++;
                } else {
                    printf("Queue is full. Cannot enqueue more items.\n");
                }
                break;
            case 3:
                if (size > 0) {
                    deQueue_front();
                    display();
                    size--;
                } else {
                    printf("Queue is empty. Cannot dequeue items.\n");
                }
                break;
            case 4:
                if (size > 0) {
                    deQueue_rear();
                    display();
                    size--;
                } else {
                    printf("Queue is empty. Cannot dequeue items.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong selection!!! Try again!!!");
        }
    }
}

void enQueue_front() {
    struct node* newnode;
    char item;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("\nOVERFLOW");
    }
    else {
        printf("\nEnter item value (char or int): ");
        if (scanf(" %c", &item) == 1) {  // Changed to read a character
            newnode->data = item;
        }
        if (head == NULL) {
            head = rear = newnode;
            newnode->next = newnode;
            newnode->prev = newnode;
        }
        else {
            newnode->next = head;
            newnode->prev = rear;
            rear->next = newnode;
            head->prev = newnode;
            head = newnode;
        }
    }
}

void enQueue_rear() {
    struct node* newnode;
    char item;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("\nOVERFLOW");
    }
    else {
        printf("\nEnter item value (char or int): ");
        if (scanf(" %c", &item) == 1) {  // Changed to read a character
            newnode->data = item;
        }
        if (head == NULL) {
            head = rear = newnode;
            newnode->next = newnode;
            newnode->prev = newnode;
        }
        else {
            newnode->next = head;
            newnode->prev = rear;
            rear->next = newnode;
            head->prev = newnode;
            rear = newnode;
        }
    }
}

void deQueue_front() {
    struct node* temp = head;
    if (head == NULL) {
        printf("\nUNDERFLOW");
    }
    else {
        if (head == rear) {
            head = rear = NULL;
        }
        else {
            head = head->next;
            head->prev = rear;
            rear->next = head;
        }
    }
    printf("%c has been dequeued\n", temp->data);
    free(temp);
}

void deQueue_rear() {
    struct node* temp = rear;
    if (head == NULL) {
        printf("\nUNDERFLOW");
    }
    else {
        if (head == rear) {
            head = rear = NULL;
        }
        else {
            rear = rear->prev;
            rear->next = head;
            head->prev = rear;
        }
    }
    printf("%c has been dequeued\n", temp->data);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node* current = head;
    printf("Queue elements: ");
    do {
        printf("%c ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}
