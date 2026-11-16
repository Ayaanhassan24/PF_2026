#include <stdio.h>

struct Flight {
    char flightNumber[20];
    char departureCity[50];
    char destinationCity[50];
    char date[15];
    int availableSeats;
};

void displayFlight(struct Flight f) {
    printf("Flight Details\n");
    printf("Flight Number    : %s\n", f.flightNumber);
    printf("Departure City   : %s\n", f.departureCity);
    printf("Destination City : %s\n", f.destinationCity);
    printf("Date             : %s\n", f.date);
    printf("Available Seats  : %d\n", f.availableSeats);
    printf("\n");
}


struct Flight bookSeat(struct Flight f) {
    if (f.availableSeats > 0) {
        f.availableSeats--;
        printf("Seat booked successfully\n");
        printf("Remaining seats: %d\n", f.availableSeats);
    } else {
        printf("No seats are available %s.\n", f.flightNumber);
    }
    return f; 
}

int main() {
    struct Flight flight1;
    int choice;

    printf("Enter Flight Number: ");
    scanf("%s", flight1.flightNumber);

    printf("Enter Departure City: ");
    scanf("%s", flight1.departureCity);

    printf("Enter Destination City: ");
    scanf("%s", flight1.destinationCity);

    printf("Enter Date: ");
    scanf("%s", flight1.date);

    printf("Enter Available Seats: ");
    scanf("%d", &flight1.availableSeats);

    do {
        printf("\n1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlight(flight1);
                break;
            case 2:
                flight1 = bookSeat(flight1); 
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}