#include <stdio.h>
#include <string.h>
int main(){
    char name[20];
    char namecopy[20];
    int len,size;
    printf("Enter name: ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';
    len=strlen(name);
    size=sizeof(name);
    printf("Length of string is: %d\n",len);
    printf("Length of string using size of is: %d\n",size);
    strcpy(namecopy,name);
    printf("Copied String: %s\n",namecopy);
    return 0;
}
