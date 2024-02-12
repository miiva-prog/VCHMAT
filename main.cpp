#include <iostream>

using namespace std;

void print(double **matrix,int n)
{
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n + 1;j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void modification(double **matrix,int n)
{
    for(int i = 0;i < n;i++){
        double max = matrix[i][i];
        for(int j = i;j < n;j++){
            if(matrix[j][i] > max)
                max = matrix[j][i];

            if(max > matrix[i][i]){
                double *matr = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = matr;
            }
        }
    }
}

void Gauss(double **matrix,int n)
{
    for(int i = 0;i < n;i++){
        double divisor = matrix[i][i];
        for(int j = i;j < n + 1;j++){
            matrix[i][j] /= divisor;
        }

        for(int k = i + 1;k < n;k++){
            double multiplier = matrix[k][i];
            for(int j = i;j < n + 1;j++){
                matrix[k][j] -= multiplier * matrix[i][j];
            }
        }
    }

    double solution[n];

    for(int i = n - 1;i >= 0;i--){
        solution[i] = matrix[i][n];
        for(int j = i + 1;j < n;j++){
            solution[i] -= matrix[i][j] * solution[j];
        }
    }

    for(int i = 0;i < n;i++)
        cout << "x" << i + 1 << " = " << solution[i] << endl;
}

int main()
{
    int n;

    cout << "SIZE ->";
    cin >> n;
    cout << n << "x" << n + 1 << ":" << endl;

    double** matrix = new double*[n];

    for(int i = 0;i < n;i++)
        matrix[i] = new double[n + 1];
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n + 1;j++) 
            cin >> matrix[i][j];

    modification(matrix,n);

    cout << "Modification" << endl;

    print(matrix,n);

    cout << endl;

    Gauss(matrix,n);
    print(matrix,n);

    for(int i = 0;i < n;i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}