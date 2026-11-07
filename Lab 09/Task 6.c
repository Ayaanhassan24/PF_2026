#include <stdio.h>
#include <string.h>
int main(){
    char names[5][20];
    char temp[20];
    for(int i=0;i<5;i++){
        printf("Enter student name: ");
        scanf("%s",names[i]);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(strcmp(names[j],names[j+1])>0){
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("Student %d: %s\n",i+1,names[i]);
    }
    return 0;
}