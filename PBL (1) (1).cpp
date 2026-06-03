
#include <stdio.h>
#include <string.h>

#define MAX 6

char bookingNames[MAX][50];
char bookingTrains[MAX][30];
int count = 0;

int login();
void bookTicket();
void displayTickets();
void deleteTicket();
void modifyTicket();

int main()
{
    int choice;

    printf("Train Ticket Booking System\n");

    if(login() == 0)
        return 0;

    while(1)
    {
        printf("\nMENU\n");
        printf("1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Delete Ticket\n");
        printf("4. Modify Ticket\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookTicket();
                break;

            case 2:
                displayTickets();
                break;

            case 3:
                deleteTicket();
                break;

            case 4:
                modifyTicket();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

int login()
{
    char password[30];

    printf("Enter system password: ");
    scanf("%s", password);

    if(strcmp(password, "password") == 0)
    {
        printf("Access granted!\n");
        return 1;
    }
    else
    {
        printf("Incorrect password\n");
        return 0;
    }
}

void bookTicket()
{
    char name[50];
    char train[30];
    int choice;

    if(count >= MAX)
    {
        printf("No more bookings allowed!\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf("%s", name);

    printf("Choose Train:\n");
    printf("1. Rajdhani Express\n");
    printf("2. Shatabdi Express\n");
    printf("3. Duronto Express\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        strcpy(train, "Rajdhani");
    else if(choice == 2)
        strcpy(train, "Shatabdi");
    else if(choice == 3)
        strcpy(train, "Duronto");
    else
    {
        printf("Invalid train!\n");
        return;
    }

    strcpy(bookingNames[count], name);
    strcpy(bookingTrains[count], train);
    count++;

    printf("Ticket booked successfully!\n");
}

void displayTickets()
{
    int i;

    if(count == 0)
    {
        printf("No bookings found!\n");
        return;
    }

    printf("\n--- Bookings ---\n");
    for(i = 0; i < count; i++)
    {
        printf("%d. %s -> %s\n", i+1, bookingNames[i], bookingTrains[i]);
    }
}

void deleteTicket()
{
    int i, delIndex;

    if(count == 0)
    {
        printf("Nothing to delete!\n");
        return;
    }

    printf("Enter booking number to delete: ");
    scanf("%d", &delIndex);

    if(delIndex < 1 || delIndex > count)
    {
        printf("Invalid number!\n");
        return;
    }

    for(i = delIndex - 1; i < count - 1; i++)
    {
        strcpy(bookingNames[i], bookingNames[i+1]);
        strcpy(bookingTrains[i], bookingTrains[i+1]);
    }

    count--;
    printf("Ticket deleted!\n");
}

void modifyTicket()
{
    int index, choice;
    char name[50];
    char train[30];

    if(count == 0)
    {
        printf("No bookings to modify!\n");
        return;
    }

    displayTickets();

    printf("Enter booking number to modify: ");
    scanf("%d", &index);

    if(index < 1 || index > count)
    {
        printf("Invalid number!\n");
        return;
    }

    printf("Enter new passenger name: ");
    scanf("%s", name);

    printf("Choose New Train:\n");
    printf("1. Rajdhani Express\n");
    printf("2. Shatabdi Express\n");
    printf("3. Duronto Express\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        strcpy(train, "Rajdhani");
    else if(choice == 2)
        strcpy(train, "Shatabdi");
    else if(choice == 3)
        strcpy(train, "Duronto");
    else
    {
        printf("Invalid train!\n");
        return;
    }

    strcpy(bookingNames[index - 1], name);
    strcpy(bookingTrains[index - 1], train);

    printf("Ticket modified successfully!\n");
}
