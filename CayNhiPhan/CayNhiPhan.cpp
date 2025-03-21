#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    int value;  // Gia tri ma node dang luu
    node *left; // con tro node
    node *right;
};

int main()
{
    // La mot cau truc du lieu ma moi node cua no co toi da la 2 node con
    // node con ben trai va ben phai
    // La 1 cau truc du lieu cap phat dong

    // KHAI NIEM CO BAN :
    // Node goc (root) : Node dau tien tao nen cay nhi phan
    // Node cha (parent) : La node cha cua 2 node con A va B
    // Node la (Leaf) : Node khong co node con
    // Node trung gian : La node co toi thieu 1 con (Ben tai hoac ben phai)
    // Node truoc (Ancestor) :Node A dc goi la node truoc cua B neu B thuoc cay con ben trai/phai voi goc A
    // Node sau trai (Left descendent) : Node B duoc goi la node sau trai cua node A neu B thuoc cay con ben trai
    //  voi goc A

    // Luu tru theo 2 cach : Dung mang -> Node cha o p -> Node con ben trai 2p+1 ben phai 2p+2
    //                       Dung node -> Tu cai dat cau truc du lieu -> Xay dung cau truc node
    // 3 phan : Data, Address Left, Address Right

    // Tao node root
    node *root = new node;
    root->value = 1;
    root->left = *NULL;
    root->right = *NULL;

    node *x = new node;
    x->value = 2;
    x->left = *NULL;
    x->right = *NULL;

    // x muon lam con cua root thi root phai luu dia chi cua thang 2
    root->left = x; // Lay dia chi node x luu vao phan left cua root

    // TAT CA CAC NODE DEU LA CON TRO

    // CHO CAY NHI PHAN DUOI DANG DANH SACH CANH
    // 1 2 L
    // 1 3 R
    // 2 4 L
    // 3 6 L
    // 3 7 R

    // u v w
    // w -> L hoac R

    return 0;
}