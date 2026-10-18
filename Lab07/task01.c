#include <stdio.h>
int main(){
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,10}};
    int transpose[3][3];
    int cofactor[3][3];
    int adjoint[3][3];
    double inverse[3][3];
    int det = 0;

    for (int i =0; i<3;i++){
        for(int j = 0; j<3;j++){
            transpose[j][i] = mat[i][j];
        }
    }

    for(int j=0;j<3;j++){
        int submat[2][2];
        int subrow = 0;

        for(int r=1;r<3;r++){
            int subcol=0;
            for(int c=0;c<3;c++){
                if (c!=j){
                    submat[subrow][subcol]=mat[r][c];
                    subcol++;
                }
            }
            subrow++;
        }
    
        int sub_det=(submat[0][0]*submat[1][1])-(submat[0][1]*submat[1][0]);
        if (j%2==1){
            det -= mat[0][j]*sub_det;
        }
        else{
            det += mat[0][j]*sub_det;
        }
    }

    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            int submat[2][2];
            int subrow=0;

            for (int r=0;r<3;r++){
                if (r!=i){
                    int subcol=0;
                    for(int c=0;c<3;c++){
                        if (c!=j){
                            submat[subrow][subcol]=mat[r][c];
                            subcol++;
                        }
                    }
                    subrow++;
                }
            }

            int minor_det = (submat[0][0]*submat[1][1])-(submat[0][1]*submat[1][0]);
            if ((i+j)%2==1){
                cofactor[i][j]=-minor_det;
            }
            else{
                cofactor[i][j]=minor_det;
            }
        }
    }

    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            adjoint[j][i]=cofactor[i][j];
        }
    }

    int isInvertible = (det!=0);
    if (isInvertible){
        for(int i =0;i<3;i++){
            for(int j  =0;j<3;j++){
                inverse[i][j]=(double)adjoint[i][j]/det;
            }
        }
    }
    printf("ORIGINAL MATRIX\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%6d ", mat[i][j]);
        printf("\n");
    }

    printf("\nTRANSPOSE MATRIX\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%6d ", transpose[i][j]);
        printf("\n");
    }

    printf("\nCOFACTOR MATRIX\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%6d ", cofactor[i][j]);
        printf("\n");
    }
    printf("\nADJOINT MATRIX\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%6d ", adjoint[i][j]);
        printf("\n");
    }

    printf("\nDeterminant of the matrix = %d\n", det);

    printf("\nINVERSE MATRIX\n");
    if (isInvertible) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) printf("%8.2f ", inverse[i][j]);
            printf("\n");
        }
    } else {
        printf("The matrix is singular (det = 0). Inverse does not exist.\n");
    }

    return 0;

}