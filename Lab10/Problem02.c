#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

void display(struct Movie m[], int count) {

    printf("All Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title        : %s\n", m[i].title);
        printf("Genre        : %s\n", m[i].genre);
        printf("Director     : %s\n", m[i].director);
        printf("Release Year : %d\n", m[i].releaseYear);
        printf("Rating       : %.1f\n", m[i].rating);
        printf("\n");
    }
}

void search(struct Movie m[], int count, char searchGenre[]) {
    int found = 0;

    printf("Search Results for Genre: %s\n", searchGenre);
    for (int i = 0; i < count; i++) {
        if (strcmp(m[i].genre, searchGenre) == 0) {
            printf("Title        : %s\n", m[i].title);
            printf("Director     : %s\n", m[i].director);
            printf("Release Year : %d\n", m[i].releaseYear);
            printf("Rating       : %.1f\n", m[i].rating);
            printf("\n");
            found = 1;
        }
    }

    if (found == 0) {
        printf("No movies found in the '%s' genre.\n", searchGenre);
    }
}

int main() {
    struct Movie movies[50]; 
    int count = 0;
    int choice;
    char searchGenre[30];

    do {
        printf("\n1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < 50) {
                    printf("Enter Title: ");
                    scanf("%s", movies[count].title);

                    printf("Enter Genre: ");
                    scanf("%s", movies[count].genre);

                    printf("Enter Director: ");
                    scanf("%s", movies[count].director);

                    printf("Enter Release Year: ");
                    scanf("%d", &movies[count].releaseYear);

                    printf("Enter Rating: ");
                    scanf("%f", &movies[count].rating);

                    count++;
                    printf("Movie added successfully\n");
                } else {
                    printf("Movie list is full\n");
                }
                break;

            case 2:
                printf("Enter Genre to search: ");
                scanf("%s", searchGenre);
                search(movies, count, searchGenre);
                break;

            case 3:
                display(movies, count);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}