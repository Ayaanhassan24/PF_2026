#include <stdio.h>
int main(){
    int matrix[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},{{9,8,7},{6,5,4},{3,2,1}},{{1,2,3},{4,5,6},{7,8,9}}};

    for (int l=0;l<3;l++){
        printf("Layer %d\n",l+1);
        for(int r=0;r<3;r++){
            for (int c=0;c<3;c++){
                printf("%d\t",matrix[l][r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for(int l1=0;l1<2;l1++){
        for (int l2=l1+1; l2<3;l2++){
            int matching_element=0;
            int isIdentical=1;

            for(int r=0;r<3;r++){
                for(int c=0;c<3;c++){
                    if(matrix[l1][r][c]==matrix[l2][r][c]){
                        matching_element++;
                    }
                    else{
                        isIdentical=0;
                    }
                }
            }
            printf("Comparing layer %d and Layer %d:\n",l1+1,l2+1);
            printf("Matching Elements: %d / 9\n",matching_element);
            if(isIdentical){
                printf("Its Identical\n");
            }
            else{
                printf("Its Distinct\n");
            }
        }
    }
    return 0;
}