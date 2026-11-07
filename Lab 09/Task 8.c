#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isSubsequence(char* s, char* t) { 
    int t_len=strlen(t);
    int i=0;
    for (int j = 0; j < t_len;j++){
        if(s[i]=='\0'){
            return true;
        }
        if(s[i]==t[j]){
            i++;
        }
    } 
    if(s[i]=='\0'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char s[4]="abc";
    char t[7]="ahbgdc";
    if (isSubsequence(s,t)){
        printf("It is a subsequence");
    }
    else{
        printf("It is not subsequence");
    }
    return 0;
}