#include <stdio.h>

int det(int a[][10], int n)
{
    if (n == 1)
    {
        return a[0][0];
    }
    int det = 0;
    int tmp[10][10];
    for (int i = 0; i < n; i++)
    {
        // cot i
        int subi = 0;
        for (int j = 1; j < n; j++)
        {
            int subj = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                    continue;
                tmp[subi][subj] = a[i][j];
                subj++;
            }
            subi++;
        }
        det += (p % 2 == 0 ? 1 : -1) * a[0][p] * det(tmp, n - 1);
    }
}

int main()
{

    return 0;
}