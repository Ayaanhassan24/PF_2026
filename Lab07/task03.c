#include <stdio.h>
int main(){
    int r1,c1,r2,c2;
    int a[3][3], b[3][3], result[3][3];

    printf("Enter rows and column for first matrix(upto 3x3): ");
    scanf("%d %d",&r1,&c1);

    printf("Enter rows and column for second matrix(upto 3x3): ");
    scanf("%d %d",&r2,&c2);

    if(r1>3||c1>3||r2>3||c2>3||r1<=0||c1<=0||r2<=0||c2<=0){
        printf("Matrix dimension must be between 1x1 and 3x3.\n");
    }
    else{
        if(c1!=r2){
            printf("Columns of Matrix 1 must equal rows of Matrix 2.\n");
        }
        else{
            printf("Enter elements of first matrix:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    printf("Element a[%d][%d]: ",i,j);
                    scanf("%d",&a[i][j]);
                } 
            }
            printf("Enter elements of seconnd matrix:\n");
            for(int i=0;i<r2;i++){
                for(int j=0;j<c2;j++){
                    printf("Element b[%d][%d]: ",i,j);
                    scanf("%d",&b[i][j]);
                } 
            }

            for(int i=0;i<r1;i++){
                for (int j=0;j<c2;j++){
                    result[i][j]=0;
                }
            }

            for (int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    for(int k=0;k<c1;k++){
                        result[i][j]+= a[i][k]*b[k][j];
                    }
                }
            }

            printf("First Matrix\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    printf("%d\t",a[i][j]);
                }
                printf("\n");
            }

            printf("Second Matrix\n");
            for(int i=0;i<r2;i++){
                for(int j=0;j<c2;j++){
                    printf("%d\t",b[i][j]);
                }
                printf("\n");
            }

            printf("Resultant Matrix\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    printf("%d\t",result[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}