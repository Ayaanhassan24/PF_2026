#include <stdio.h>
int main(){
    int arr[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},{{10,11,12},{13,14,15},{16,17,18}},{{19,20,21},{22,23,24},{25,26,27}}};
    int total=0;
    int max=arr[0][0][0];
    int min=arr[0][0][0];

    for (int i=0; i<3;i++){
        int layer_total=0;
        printf("Processing 2D layer %d\n",i+1);

        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                int current =arr[i][j][k];

                printf("%d\t",current);
                layer_total+=current;

                if (current>max){
                    max = current;
                }
                if(current<min){
                    min =current;
                }
            }
            printf("\n");
        }
        printf("Layer %d Total: %d\n",i+1,layer_total);
        float layer_avg=layer_total/9.0;
        printf("Layer %d Average: %.2f\n\n",i+1,layer_avg);

        total+=layer_total;
    }

    float avg= total/27.0;

    printf("Total of all elements: %d\n",total);
    printf("Overall Average value: %.2f\n",avg);
    printf("Maximum Value: %d\n",max);
    printf("Minimum Value: %d\n",min);

    return 0;
}   