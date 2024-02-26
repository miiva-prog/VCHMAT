#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(int n,double matrix[n][n + 1]);

void just_iteration(int size,double matrix[size][size + 1]);

int main()
{
    int size = 3;
    double matrix[3][4] = {{4.0,1.0,1.0,9.0},
                          {1.0,6.0,-1.0,10.0},
                          {1.0,2.0,5.0,20.0}};

    just_iteration(size,matrix);
    print(size,matrix);

    return 0;
}

void print(int n,double matrix[n][n + 1])
{
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n + 1;j++)
            printf("%f ",matrix[i][j]);
        printf("\n");
    }
}

void just_iteration(int size,double matrix[size][size + 1])
{
    for(int n = 0;n < size;n++){
        double diagonal = matrix[n][n];
        for(int i = 0;i < size + 1;i++)
            matrix[n][i] /= diagonal; 

        matrix[n][n] = 0.0;
    }

    double vector[size];
    double eps = 0.0001;
    int flag = 0;

    for(int n = 0;n < size;n++)
        vector[n] = matrix[n][size];

    while(flag == 0){
        for(int n = 0;n < size;n++){
            double mult = 0.0;
            for(int i = 0;i < size;i++)
                mult += matrix[n][i] * vector[i];

            vector[n] = matrix[n][size] - mult;
        }

        for(int n = 0;n < size;n++)
            if(vector[n] - matrix[n][size] < eps)
                flag++;
    }    

    for(int n = 0;n < size;n++)
        printf("%f\n",vector[n]);
}