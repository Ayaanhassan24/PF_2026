#include <stdio.h>
#include <string.h>
int main(){
    char sentence[50];
    printf("Enter a sentence: ");
    fgets(sentence,sizeof(sentence),stdin);
    char *p =strchr(sentence,'a');
    if (p!=NULL){
        int index=p-sentence;
        printf("First 'a' found at index %d\n",index);
    }
    else{
        printf("'a' not found\n");
    }
    if (strstr(sentence,"good")){
        printf("Word 'good' found.\n");
    }
    else{
        printf("Word good not found.\n");
    }
    return 0;
}