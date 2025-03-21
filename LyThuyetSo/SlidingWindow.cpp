#include <bits/stdc++.h>
using namespace std;

void hoanvi()
{
    // Cho A[] gom n so nguyen duong va so k.
    // Hay sap dat cac phan tu cua mang sao cho so nho hon hoac bang k dung canh nhau
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        int d = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= k)
            {
                d++;
            }
        }
        int count = 0;
        for (int i = 0; i < d; i++)
        {
            if (a[i] <= k)
            {
                count++;
            }
        }
        int ans = count; // cap nhat ky luc
        for (int i = d; i < n; i++)
        {
            if (a[i - d] <= k)
            {
                count--;
            }
            if (a[i] <= k)
            {
                count++;
            }
            ans = max(ans, count);
        }
        cout << d - ans << endl;
    }
}

int main()
{
    // Cho mang so nguyen n phan tu va so nguyen duong k
    // Tim day con lien tiep cua mang co do dai k sao cho tong cac phan tu
    // trong day la lon nhat va liet ke day con do
    // Neu co nhieu day con co cung tong lon nhat thi in ra day con dau tien

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (itn i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long sum = 0;
        for (int i = 0 i < k; i++)
        {
            sum += a[i]; // Bien sum luu cua so dau tien
        }
        long long res = sum, index = 0; // index de luu chi so dau tien cua cua so
        for (int i = k; i < n; i++)
        {
            sum = sum - a[i - k] + a[i]; // a[i - k] -> phan tu dau tien cua cua so truoc do - bi loai khoi cua so hien tai
            //+a[i] phan tu cua so hien tai
            if (sum > res)
            {
                res = sum;
                index = i - k + 1; // chi so bat dau
            }
        }
        cout << res << endl;
        for (int j = 0; j < k; j++)
        {
            cout << a[index + j] << " ";
        }
        cout << endl;
    }

    return 0;
}