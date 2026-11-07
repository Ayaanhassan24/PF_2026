#include <stdio.h>
#include <string.h>
int main(){
    char firstname[9];
    char lastname[9];
    char fullname[20];
    printf("Enter first name: ");
    scanf("%s",firstname);
    printf("Enter last name: ");
    scanf("%s",lastname);
    strcpy(fullname, firstname);
    strcat(fullname," ");
    strcat(fullname,lastname);
    printf("Full name: %s",fullname);

    return 0;
}