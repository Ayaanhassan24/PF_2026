#include <stdio.h>
int main(){
    int rows,cols;

    printf("Enter no of rows and columns(upto 5x5): ");
    scanf("%d %d", &rows, &cols);

    int mat[5][5],other[5][5];
    printf("Enter elements of matrix:\n");
    for (int i=0; i<rows;i++){
        for(int j=0; j<cols;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int isZero=1;
    int isSkew=1;
    int isSym=1;
    int isUpper=1;
    int isLower=1;
    int isIdentity=1;
    int isScalar=1;
    int isDiagonal=1;
    int isSquare=(rows==cols);

    for (int i=0;i<rows;i++){
        for (int j=0; j<cols;j++){
            if (mat[i][j]!=0){
                isZero = 0;
            }
        }
    }

    if(isSquare){
        int n=rows;

        for(int i=0; i<n;i++){  
            for (int j=0; j<n;j++){
                if (mat[i][j]!=-mat[j][i]){
                    isSkew=0;
                }
                if (mat[i][j]!=mat[j][i]){
                    isSym=0;
                }
                if(i>j && mat[i][j]!=0){
                    isUpper=0;
                }
                if(i<j && mat[i][j]!=0){
                    isLower=0;
                }
                if(i!=j && mat[i][j]!=0){
                    isDiagonal=0;
                }
            }
            if(mat[i][i]!=mat[0][0]){
                isScalar=0;
            }
            if(mat[i][i]!=1){
                isIdentity=0;
            }
        }
        if(!isDiagonal){
            isScalar=0;
            isIdentity=0;
        }

        
        int a[5][5];
        int singular = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = mat[i][j];

        for (int c = 0; c < n && !singular; c++) {
            int p = -1;
            for (int r = c; r < n && p == -1; r++)
                if (a[r][c] != 0) p = r;

            if (p == -1) {
                singular = 1;
            } else {
                if (p != c) {
                    for (int k = 0; k < n; k++) {
                        int t = a[p][k];
                        a[p][k] = a[c][k];
                        a[c][k] = t;
                    }
                }
                for (int r = c + 1; r < n; r++) {
                    int x = a[r][c];
                    int y = a[c][c];
                    for (int k = c; k < n; k++)
                        a[r][k] = a[r][k] * y - a[c][k] * x;
                }
            }
        }
 
        
        int sq[5][5], idempotent = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                sq[i][j] = 0;
                for (int k = 0; k < n; k++)
                    sq[i][j] += mat[i][k] * mat[k][j];
                if (sq[i][j] != mat[i][j]) idempotent = 0;
            }
 
        
        int pw[5][5], tmp[5][5], nilpotent = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                pw[i][j] = mat[i][j];
 
        for (int k = 1; k <= n && !nilpotent; k++) {
            int allZero = 1;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (pw[i][j] != 0) allZero = 0;

            if (allZero) {
                nilpotent = 1;
            } else {
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++) {
                        tmp[i][j] = 0;
                        for (int m = 0; m < n; m++)
                            tmp[i][j] += pw[i][m] * mat[m][j];
                    }
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        pw[i][j] = tmp[i][j];
            }
        }
 
        printf("\nThe matrix is:\n");
        printf("Square Matrix\n");
        if (isZero) printf("Zero Matrix\nNull Matrix\n");
        if (isIdentity) printf("Identity Matrix\n");
        if (isDiagonal) printf("Diagonal Matrix\n");
        if (isScalar) printf("Scalar Matrix\n");
        if (isUpper) printf("Upper Triangular Matrix\n");
        if (isLower) printf("Lower Triangular Matrix\n");
        if (isSym) printf("Symmetric Matrix\n");
        if (isSkew) printf("Skew-Symmetric Matrix\n");
        if (singular) printf("Singular Matrix\n");
        else printf("Non-Singular Matrix\n");
        if (idempotent) printf("Idempotent Matrix\n");
        if (nilpotent) printf("Nilpotent Matrix\n");
    } else {
        printf("\nThe matrix is:\n");
        printf("Rectangular Matrix\n");
        if (isZero) printf("Zero Matrix\nNull Matrix\n");
    }
 
    if (rows == 1) printf("Row Matrix\n");
    if (cols == 1) printf("Column Matrix\n");
 
    
    int choice;
    printf("\nCompare with another matrix? (1 = yes, 0 = no): ");
    scanf("%d", &choice);
    if (choice == 1) {
        int equal = 1;
        printf("Enter elements of second matrix:\n");
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                scanf("%d", &other[i][j]);
                if (other[i][j] != mat[i][j]) equal = 0;
            }
        if (equal) printf("Equal Matrix\n");
        else printf("Matrices are not equal\n");
    }
 
    return 0;
}