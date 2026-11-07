#include <stdio.h>
#include <string.h>
int main(){
    char user[20];
    char pass[]="lab10pass";
    printf("Enter password: ");
    scanf("%s",user);
    if (strcmp(pass,user)==0){
        printf("Access granted\n");
    }
    else{
        printf("Access denied\n");
    }
    if (strncmp(pass,user,3)==0){
        printf("First 3 characters match.\n");
    }
    else{
        printf("First 3 charcters dont match.\n");
    }
    return 0;

}