#include <stdio.h>
#include <stdlib.h>

void Print_Matrix(int** matr, int Row, int Column);
void Set_Matrix_Content(int** matr, int Row, int Column);
int Matrix_Product(int** matr, int Row, int Column);


int main()
{

// =============================================== // завдання 1
    int N;
    int Sum = 0;

    printf("\n enter N >= 1: ");
    while(scanf("%d", &N) && N <= 0) {}

    for (int n = 1; n <= N; n++)
    {
        Sum += pow(-1, n - 1) * (1/n);
    }

    printf("\n\n result = %d", Sum);

// =============================================== // завдання 2

    int Na;

    printf("\n\n\n");
    printf("\n Size matrix A: ");
    scanf("%d", &Na);


    int ** Matr = (int**) malloc (sizeof (int*) *Na);
    for (int i = 0; i < Na; i++)
    {
        Matr [i] = (int*) malloc (sizeof (int)*Na);
    }



    Set_Matrix_Content(Matr, Na, Na);

    Print_Matrix(Matr, Na, Na);

    printf("\n  sum = %d ", Matrix_Product(Matr, Na, Na));




    return 0;
}
void Print_Matrix(int** matr, int Row, int Column)
{
    printf("\n");

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            if(matr[i][j] > 0)
            {
                printf(" %d  ", matr[i][j]);
            }
            else
            {
                printf("%d  ", matr[i][j]);
            }
        }
        printf("\n");
    }
}
void Set_Matrix_Content(int** matr, int Row, int Column)
{

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            if(rand() % 2 == 1)
            {
                matr[i][j] = (rand() % 5) + 4;
            }
            else
            {
                matr[i][j] = -((rand() % 5) + 4);
            }
        }
    }
    printf("\n");

}
int Matrix_Product(int** matr, int Row, int Column)
{
    double SumArr = 1;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            if (j >= i)
            {
                SumArr =  SumArr * matr[i][j]; //j >= i - вище головної діагоналі
            }
        }
    }
    return SumArr;
}









