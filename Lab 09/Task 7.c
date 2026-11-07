#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[20];
    FILE *fptr;

    fptr = fopen("students.txt","w");
    if (fptr==NULL){
        printf("Error opening file for writing\n");
        return 1;
    }
    printf("Enter 3 student names:\n");
    for(int i=0;i<3;i++){
        fgets(name,sizeof(name),stdin);

        fprintf(fptr,"%s",name);
    }
    fclose(fptr);

    fptr=fopen("students.txt","r");
    if(fptr==NULL){
        printf("Error oepning file for reading\n");
        return 1;
    }
    printf("\nNames read from students.txt:\n");
    int count=0;
    while(fgets(name,sizeof(name),fptr)!=NULL){
        count=count +1;
        name[strcspn(name,"\n")]='\0';
        printf("%d. %s\n",count,name);
    }
    printf("Total students in file: %d\n",count);
    fclose(fptr);
    return 0;

}