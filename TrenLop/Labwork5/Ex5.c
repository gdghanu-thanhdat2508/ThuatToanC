#include "stdio.h"

void nhap(int a[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void printMatrix(int a[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
        }
        printf('\n');
    }
}

int sumMatrix(int a[10][10], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
    }
    return sum;
}

void transitionMatrix(int a[][10], int T[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

int determinantMatrix(int a[][10], int n)
{
    if (n == 1)
    {
        return a[0][0];
    }
    int det = 0;
    int temp[10][10];
    for (int p = 0; p < n; p++)
    {
        // p là chỉ số cột

        // Doạn code dưới để tạo ra ma trận con, tạo ra ma trận bỏ hàng 0 và cột p
        int sub_i = 0;
        for (int i = 1; i < n; i++)
        {
            // lặp từng hàng
            // Lặp bắt đầu từ i = 1 do loại hàng 0
            int sub_j = 0;
            for (int j = 0; j < n; j++)
            {
                // Lặp từng cột j
                if (j == p)
                    continue; // p chinh nam trong cot can xoa
                temp[sub_i][sub_j] = a[i][j];
                sub_j++;
            }
            sub_i++;
        }
        det += (p % 2 == 0 ? 1 : -1) * a[0][p] * determinantMatrix(temp, n - 1);
    }
    return det;
}
// 1 2 3
// 4 5 6
// 7 8 9

int inverseMatrix(int A[][MAX], float inv[][MAX], int n)
{
    int det = determinant(A, n);
    if (det == 0)
    {
        printf("Matrix is singular and cannot be inverted.\n");
        return 0; // No inverse exists
    }

    int adj[MAX_INT][MAX_INT]; // To store adjugate matrix

    // Find adjugate of A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp[MAX_INT][MAX_INT];
            int sub_i = 0, sub_j = 0;

            // Form the sub-matrix by excluding current row and column
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (r != i && c != j)
                    {
                        temp[sub_i][sub_j] = A[r][c];
                        sub_j++;
                        if (sub_j == n - 1)
                        {
                            sub_j = 0;
                            sub_i++;
                        }
                    }
                }
            }

            // Calculate cofactor and assign to adj matrix
            adj[j][i] = (i + j) % 2 == 0 ? determinant(temp, n - 1) : -determinant(temp, n - 1);
        }
    }

    // Find inverse using adjugate and determinant
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inv[i][j] = adj[i][j] / (float)det;
        }
    }
    return 1; // Inverse exists
}

int main()
{

    return 0;
}