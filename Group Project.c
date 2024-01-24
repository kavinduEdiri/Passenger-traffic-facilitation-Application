#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of Passenger traffic facilities Application
typedef struct {
    char topupCardNumber[5];
    char PassengerDetails[100];
    char AmountOfCard[50];
} Task;

// Structure representing a node in the linked list
typedef struct Node {
    Task task;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* topupCardNumber, const char* PassengerDetails, const char* AmountOfCard) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->task.topupCardNumber, topupCardNumber);
    strcpy(newNode->task.PassengerDetails, PassengerDetails);
    strcpy(newNode->task.AmountOfCard, AmountOfCard);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the list
void insertFront(Node** head, const char* topupCardNumber, const char* PassengerDetails, const char* AmountOfCard) {
    Node* newNode = createNode(topupCardNumber, PassengerDetails, AmountOfCard);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the rear of the list
void insertRear(Node** head, const char* topupCardNumber, const char* PassengerDetails, const char* AmountOfCard) {
    Node* newNode = createNode(topupCardNumber, PassengerDetails, AmountOfCard);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert a node after a given node
void insertNext(Node* prevNode, const char* topupCardNumber, const char* PassengerDetails, const char* AmountOfCard) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    Node* newNode = createNode(topupCardNumber, PassengerDetails, AmountOfCard);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to search for a task by topupCardNumber
Node* search(Node* head, const char* topupCardNumber) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->task.topupCardNumber, topupCardNumber) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a task by topupCardNumber
void deleteTask(Node** head, const char* topupCardNumber) {
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->task.topupCardNumber, topupCardNumber) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Task '%s' deleted.\n", topupCardNumber);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Task '%s' not found.\n", topupCardNumber);
}

// Function to print all tasks
void printTasks(Node* head) {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf("Task %d:\n", count);
        printf("TopUp Card Number: %s\n", current->task.topupCardNumber);
        printf("Passenger Details: %s\n", current->task.PassengerDetails);
        printf("Current Amount of Topup Card: %s\n", current->task.AmountOfCard);
        printf("\n");
        current = current->next;
        count++;
    }
}

// Function to free the memory allocated by tasks
void freeTasks(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* tasks = NULL;

    // Inserting tasks
    insertFront(&tasks, "Finish report", "Complete the project report and proofread it.", "2023-06-01");
    insertFront(&tasks, "Prepare presentation", "Create slides and rehearse for the upcoming presentation.", "2023-06-03");
    insertRear(&tasks, "Send follow-up email", "Send a follow-up email to the client regarding the project status.", "2023-06-05");

    // Printing tasks
    printf("Tasks:\n");
    printTasks(tasks);

    // Freeing memory
    freeTasks(tasks);

    return 0;
}

