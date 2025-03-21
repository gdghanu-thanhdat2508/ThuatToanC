#include <stdio.h>

void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void show(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d", a[i]);
    }
}

void BubbleSort(int a[], int n)
{
    // Xap xep noi bot
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void BubbleSort2(int a[], int n)
{
    // Vong lap dau tien so lon nhat da ve cuoi => giam di 1 buoc lap
    // Buoc n - 1 da lap xong => ko can lap den n lan
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // - i do sau i vong lap da co phan tu i duoc xap xex => Ko can so sanh voi phan tu do nuas
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void insertionSort(int a[], int n)
{
    // Coi thằng đầu tiên đã đc sắp xếp
    for (int i = 1; i < n; i++)
    {
        int k = a[i];
        int j = i - 1;

        // Dich chuyen cac phan tu lon hon k len 1 vi tri
        while (j >= 0 && arr[j] > k)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // Gia su phan tu nho nhat la a[i]

        for (int j = i + 1; i < n; i++)
        {
            if (a[j] < minIndex)
            {
                minIndex = j;
            }
        }

        // Hoan doi voi pnan tu nho nhat tim dc
        if (minIndex != i)
        {
            int tmp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = tmp;
        }
    }
}

int main()
{
    return 0;
}