#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Set:
    // Loai bo trung lap
    // Tu dong sap xep theo thu tu tang dan
    // Tim kiem voi OLog(n)
    //      -> Neu tim thay, tra ve iterator toi phan tu do, con neu khong se tra ve set.end()

    // Set khong the su dung +2 hay -2 vi khong nam voi nhau trong bo nho
    // Chi co the su dung ++ va --
    set<int> se = {1, 2, 3, 4, 5, 6, 7};

    auto it = se.find(2);
    if (it == se.end())
    {
        cout << "Cant found numbers in set" << endl;
    }
    else
    {
        cout << "Found it " << endl;
    }

    it++;
    cout << *it << endl;

    // Ham count trong set

    // Co the su dung count de that cho ham find
    cout << se.count(2) << endl;

    // Ham erase
    // Can dam bao la phan tu do xuat hien trong set
    if (se.count(2) == 1)
    {
        se.erase(2);
    }

    // Co the xoa bang iterator
    auto it2 = se.begin();
    it2++;
    se.erase(it);

    return 0;
}