
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Passenger {
    char name[50];
    char dob[20];
    int coins;
    char departure[50];
    char arrival[50];
    struct Passenger* next;
} Passenger;

Passenger* head = NULL;

Passenger* newNode(char name[], char dob[]) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    strcpy(newPassenger->dob, dob);
    newPassenger->coins = 0;
    newPassenger->departure[0] = '\0';
    newPassenger->arrival[0] = '\0';
    newPassenger->next = NULL;
    return newPassenger;
}

void insertFront(char name[], char dob[]) {
    Passenger* newPassenger = newNode(name, dob);
    newPassenger->next = head;
    head = newPassenger;
    printf("New account created.\n");
}

void insertNext(char name[], char departure[]) {
    Passenger* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            strcpy(curr->departure, departure);
            printf("Departure place inserted.\n");
            return;
        }
        curr = curr->next;
    }
    printf("Passenger not found.\n");
}

void insertRear(char name[], char arrival[], int distance) {
    Passenger* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            strcpy(curr->arrival, arrival);
            int fare = distance;
            if (curr->coins >= fare) {
                curr->coins -= fare;
                printf("Thank you for using the service. Come again!\n");
            } else {
                printf("Insufficient coins. Please recharge your card.\n");
            }
            return;
        }
        curr = curr->next;
    }
    printf("Passenger not found.\n");
}

void search(char name[]) {
    Passenger* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            printf("Remaining coins: %d\n", curr->coins);
            return;
        }
        curr = curr->next;
    }
    printf("Passenger not found.\n");
}

void delete(char name[]) {
    Passenger* prev = NULL;
    Passenger* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Account deletion successful.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Passenger not found.\n");
}

int main() {
    int choice;
    char name[50], dob[20], departure[50], arrival[50];
    int distance;

    while (1) {
        printf("\nWhat service do you need?\n");
        printf("1. Insert new user\n");
        printf("2. Travel\n");
        printf("3. Delete account\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter passenger name: ");
                scanf("%s", name);
                printf("Enter date of birth: ");
                scanf("%s", dob);
                insertFront(name, dob);
                break;
            case 2:
                printf("Enter passenger name: ");
                scanf("%s", name);
                printf("Enter departure place: ");
                scanf("%s", departure);
                insertNext(name, departure);
                printf("Enter arrival place: ");
                scanf("%s", arrival);
                printf("Enter distance: ");
                scanf("%d", &distance);
                insertRear(name, arrival, distance);
                break;
            case 3:
                printf("Enter passenger name: ");
                scanf("%s", name);
                delete(name);
                break;
            case 4:
                printf("Enter passenger name: ");
                scanf("%s", name);
                search(name);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
