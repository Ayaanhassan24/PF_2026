#include <stdio.h>
#include <string.h>
int main(){
    char cities[5][20];
    for(int i=0;i<5;i++){
        printf("Enter city name: ");
        fgets(cities[i],sizeof(cities[i]),stdin);
        cities[i][strcspn(cities[i],"\n")]='\0';
    }
    int longest=0;
    for(int i=0;i<5;i++){
        if(strlen(cities[i])>strlen(cities[longest])){
            longest=i;
        }
    }
    for(int i=0;i<5;i++){
        printf("%s\n",cities[i]);
    }
    int length=strlen(cities[longest]);
    printf("Longest name of city is: %s (Length: %d)\n",cities[longest],length);
    return 0;
}