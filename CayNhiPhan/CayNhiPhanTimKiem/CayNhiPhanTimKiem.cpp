#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    int val;
    node *left;
    node *right;
};

// Tim kiem tren cay nhi phan tim kiem
bool Search(node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == x)
        return true; // Da tim thay ket qua
    if (root->val < x)
        // Goi de quy den cay con ben trai
        return search(root->right, x); // Vi nho hon nen phai xet ben phai
    else
        // Cay con ben phai
        return search(root->left, x);
}

// Co 1 cay nhi phan tim kiem => Chen vao 1 so
// Van phai dam bao rang day la cay nhi phan tim kiem
// Phai tim sau do so sanh sau do goi de quy de them vao dung vi tri

node *makeNode(int x)
{
    node *newNode = new node;
    newNode->val = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int x)
{
    if (root == NULL)
    {
        // Da den node can phai insert
        return makeNode(x);
    }
    if (root->val < x)
    {
        root->right = insert(root->right, x);
    }
    else if (root->val > x)
    {
        root->left = insert(root->left, x);
        // Sau khi goi de quy thi chung ta se phai gan nguoc lai
        // Sau khi chay xong se return thang leaf de gan
    }
    return root;
}

// Xoa 1 node tren cay nhi phan tim kiem
// TH1 : Node can xoa la node leaf, ta chi can xoa node nay
// TH2 : Node can xoa la 1 node con, khi do gan tri cho node can xoa bang gia tri cua node con sau do
// giai phong node con => Dam bao no van la cay nhi phan tim kiem,
// tim thang nho nhat va lon hon node can xoa
// Nam ben cay con ben phai -> Nam ben trai cung -> Di den node la -> Do chinh la gia tri can tim

// B1 Tim node x nho nhat lon hon cai node can xoa
node *minNode(node *root)
{
    node *tmp = root;
    while (tmp != NULL && tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}
node *deleteNode(node *root, int x)
{
    if (root == NULL)
        return root;

    // Do chua tim duoc => Phai duyet 2 ben cay
    if (x < root->val)
    {
        // Xoa node con ben phai
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->val)
    {
        // Xoa node con ben trai
        root->right = deleteNode(root->right, x);
    }
    else
    {
        // TH1 : Con ben trai cua root = NULL
        // Dua node con do len vi tri dang truoc
        if (root->left == NULL)
        {
            node *tmp = root->right;
            delete root; // Delete node goc
            return tmp;  // Return node con ben phai de no gan vao root->left hoac root->right cua loi goi de quy
        }
        else if (root->right == NULL)
        {
            node *tmp = root->left;
            delete root;
            return tmp;
        }
        else
        {
            node *tmp = minNode(root->right);
            root->data = tmp->data;                           // Gan data node tmp do cho cai node muon xoa (root)
            root->right = deleteNode(root->right, tmp->data); // Goi de quy den cay con ben phai
            // xoa di node
        }
    }
    return root;
}

int main()
{
    // Cay tim kiem - Binary Search Tree (BST)
    // + Tat ca cac node con thuoc cay con ben trai nho hon node goc
    // + Tat ca node con thuoc cay ben phai lon hon node goc
    // + Cay con ben trai va ben phai cung la cay BST (Cung phai tuan theo quy tac tren)

    // Moi lan chi can cua doi cay ra de tim

    return 0;
}