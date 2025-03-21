#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// QUAN TRONG
// Bai toan lien quan den truy van day so, lien quan den day so

// Tinh tong tu left den right
// Co Q truy van => Q * O(logn)

// Segment tree
// 2 loai truy van :
//      + Truy van ket qua trong doan L to R : Tinh tong, min, max
//      + Update 1 phan tu / 1 doan thanh 1 gia tri khac
// Truoc day dung mang cong don => Co the su dung segment tree (Nhung cham hon)

// Gia su co mang A =[1, 3, 5, 7 ,9 ,11]
// Nhung node leaf dai dien cho chinh cac phan tu trong mang
// La 1 cay nhi phan day du

// Voi mang A[] co N phan tu :
// -> Segment tree se khong co qua 4 * N node (O nho)

// Xay to root -> Node con ben trai -> Node con ban phai -> ....
// Node cha U => co 2 node con : 2U va 2U + 1

// Bat dau tu node 1 (1, 36) -> Luu tong tat ca phan tu trong mang la 36
// Node cha u luu tong tat ca phan tu tu chi so L den R
// => Node con ben trai la 2u va ben phai la 2u+1
// => Chia doi ra node trai luu L -> m, node ben phai luu m -> R

// Bat dau tu node 1 (1, 0, 5) : Node t index = 1, luu chi so tu 0 den 5 (VD cua mang A)
// Sau do goi de quy den node con ben trai va ben phai
// Ben trai : 2 * u = 2 * 1 = 2 => (2, 0, 2) : Luu chi so tu 0 den 2(mid - la so 5 trong mang A)
// Ben phai : 2 * u + 1 = 2 * 1 = 3 => (3, 3, 5) : Luu chi so tu 3 den 5(mid + 1 - la so 7 trong mang A)
// Sau do node ben trai lai lap tiep tuc chia ra lam 2 node ...
// Lap lai cho den khi L va M deu bang nhau
// VD : (8, 0, 0)
// Sau do gan t index = phan tu chi so Index cua mang A ban dau
// VD (5, 2, 2) -> t = 5 va gan chi so 2 cua mang A ban dau => Node do co gia tri la A[2] la gia tri 5 vao cay segment tree

int maxn = 2e5;
int a[maxn], n;
int t[4 * maxn];

// t[v] = tong cac phan tu tu chi so L den R
void build(int v, int l, int r)
{
    if (l == r) // VD (8, 0, 0)
    {
        t[v] = a[l]; // Node leaf
        // t[v] = 8
        // a[l] = a[0]
        // => node do co gia tri la a[0]
    }
    else
    {
        // Chia l den r thanh 2 nua
        int mid = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r); // Xong nhanh tren thi moi chay den nhanh nay
        // Chay nhanh ben trai truoc, khi trai da tim duoc l == r thi moi den nhanh ben phai

        // Sau khi chay xong de quy, cap nhap cho node root
        t[v] = t[2 * v] + t[2 * v + 1];
        // gan gia tri chua node cha bang tong cua 2 node con neu da hoan thanh viec build
    }
}

// Ham truy van
// O(logn) -> Tinh tong cac phan tu L -> R cua mang A
int sum(int v, int tl, int tr, int l, int r)
{
    // Tu tuong : Su dung cay segment Tree
    // Chia doi no ra => tinh tong trong doan L -> m va m -> R
    // Node bat dau v, Cận tl và tr -> Chinh la biên ban đầu muốn tính
    // VD : n = 8, Muon tinh tu chi so 2 -> 5, l = 2 r = 5, v = 1,
    // Ban dau tl = 0 tr = 7 (Tren toan mang) Sau do lau tl + tr / 2 de lay thang mid
    // Chia thanh doi nua Tiep tuc truy van de tinh tong tu doan l -> r
    // Cu chia doi chia doi den khi den duoc node leaf -> Stop

    if (l > r)
    {
        return 0;
    }

    if (l == tl && r == tr)
    {
        return t[v]; // Doan chung ta tim kiem chi con dung 1 phan tu
        // Khi do tong tu l -> r chinh la t[v]
    }
    else
    {
        int tmid = (tl + tr) / 2;
        // Goi de quy vao nua ben trai va nua ben phai
        return sum(2 * v, tl, tmid, l, min(tl, r)) + sum(2 * v + 1, tm + 1, tr, max(tmid + 1, l), r);
        // sau khi chia doi thi se tim mid ben can phai la mid cua l va tmid (voi dieu kien phai nam trong khoang l cho den r)
        // min(tl, r) dam bao rang se truy van trong khoang l cho den r.
        // Neu r < tmid => Truy can l -> r
        // neu r -> tmid => truy van l cho den tmid =>Van nam trong khoang
        // PHAI XET TRUONG HOP TE NHAT
    }
}

// update
// O(logn)
// a[pos] = val -> update phan tu o gia tri nao do thanh 1 gia tri khac
// Minh se lan den cai node la co gia tri la pos, sau do cap nhap t[v] cho gia tri tren cay(Ko can thay doi mang A)
void update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[v] = val; // node leaf, luu phan tu chi so pos o mang A
        // Node leaf dai dien cho 1 phan tu trong mang A co chi so la POS
    }
    else
    {
        // Tinh chi so dung giua
        int mid = (l + r) / 2;
        // xem xem vi tri can cap nhap nam ben trai hay ben phai
        if (pos <= mid)
        {
            update(2 * v, l, mid, pos, val);
        }
        else
        {
            update(2 * v + 1, mid + 1, r, pos, val);
        }
        // Cu chia doi cho den khi gap chi so l == r thi cap nhap t[v] tren segment tree = gia tri moi
        // Sau khi update, lam thay foi thang t[v]
        t[v] = t[2 * v] + t[2 * v + 1]; // Thay doi cac node cha -> Do thay doi value cua node
    }
}

int main()
{
    // 2 3 1 4 2 7 6 8
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for (int i = 1; i <= 20; i++)
    {
        // Duyet tu 1 do luu thu tu node tu 1
        cout << t[i] << ' ';
    }
    int l, r;
    cin >> l >> r;
    cout << sum(1, 0, n - 1, l, r) << endl;

    build(1, 0, n - 1);
    for (int i = 1; i <= 8; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}