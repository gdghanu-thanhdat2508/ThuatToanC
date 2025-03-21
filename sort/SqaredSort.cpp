#include <bits/stdc++.h>
using namespace std;

vector<int> SquaredSort(vector<int> a)
{
    int n = a.size();
    vector<int> v(n, 0);

    // Tim i
    int i = -1;
    while ((i + 1) >= 0 && a[i + 1] < 0)
    {
        i++;
    }

    // Tim j
    int j = n;
    while ((j - 1) >= 0 && a[j - 1] >= 0)
    {
        j--;
    }

    int k = 0;
    while (i >= 0 || j < n)
    {
        if (i >= 0 && j < n)
        {
            int ii = a[i] * a[i];
            int jj = a[j] * a[j];

            if (ii < jj)
            {
                v[k] = ii;
                i--;
                k++;
            }
            else
            {
                v[k] = jj;
                j++;
                k++;
            }
        }
        else if (i >= 0)
        {
            v[k] = a[i] * a[i];
            k++;
            i--;
        }
        else
        {
            v[k] = a[j] * a[j];
            k++;
            j++;
        }
    }

    return v;
}

int main()
{
    int arr[] = {-4, -1, 0, 3, 10};
    vector<int> a(arr, arr + sizeof(arr) / sizeof(int));

    vector<int> v = SquaredSort(a);
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}