#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int val;
    node *left;
    node *right;

    // constructor
    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

// Tao cay nhi phan voi danh sach canh
void makeRoot(node *root, int u, int v, char c)
{
    if (c == 'L')
        root->left = new node(v);
    else
        root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c)
{
    if (root == NULL)
    {
        return; // Chung nao de quy goi den 1 node null -> Stop do khi do da het node de duyet
    }
    if (root->val == u) // Tim den thang u de them 1 canh vao trong cay
    {
        makeRoot(root, u, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c); // Goi de quy den node con ben trai va phai de duyet tim thang u
        insertNode(root->right, u, v, c);
    }
}

// Duyet giua -> Root se nam o giua (left - root - right)
// Duyet cay ben trai truoc -> Sau do Root -> Sau do cay ben phai
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);      // Left
        cout << root->val << " "; // Root
        inorder(root->right);     // Right
    }
}

// Duyet truoc (root - left - right)
void duyettruoc(node *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        duyettruoc(root->left);
        duyettruoc(root->right);
    }
}

void duyetsau(node *root)
{
    if (root != NULL)
    {
        duyetsau(root->left);
        duyetsau(root->right);
        cout << root->val << " ";
    }
}

//  Level Order - duyet theo muc
//  Từng tầng từng tầng một
// Ap dung thuat toan BFS
// Tren cay nhi phan KHONG BAO GIO QUAY LAI NODE CHA
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *tmp = q.front();
        q.pop();
        cout << tmp->val << " ";
        // Day luyen 2 node con ben trai va phai vao trong queue
        if (tmp->left != NULL)
        {
            q.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            q.push(tmp->right);
        }
        // Khong can phai check tmp left hay right chua duyet
        // => No ko bao gio vong lai node cha
    }
}

// Duyet xoan oc :
// Trai qua phai xong phai qua trai ....
// Dung 2 ngan xep : s1 - Duyet muc trai sang phai
//                  s2 - Duyet muc phai sang trai
// Check ca 2 ngan xep xem != NULL
// Day goc vao ngan xep s1
// neu s1 rong -> Lay ra
// Day 2 thang con vao s2
// Sau do s2 lai rong thi lai lay ra tu thang s1 sau do day thang con ben trai phai vao ngan xep

void XoanOc(node *root)
{
    stack<node *> st1, st2;
    st1.push(root);
    while (st1.size() > 0 || st2.size() > 0)
    {
        while (!st1.empty())
        {
            node *u = st1.top();
            st1.pop();
            cout << u->val << " ";
            if (u->right != NULL)
            {
                st2.push(u->right);
            }
            if (u->left != NULL)
            {
                st2.push(u->left);
            }
        }
        while (!st2.empty())
        {
            node *u = st2.top();
            st2.pop();
            cout << u->val << " ";
            if (u->right != NULL)
            {
                st1.push(u->right);
            }
            if (u->left != NULL)
            {
                st1.push(u->left);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root == NULL)
        {
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else
        {
            insertNode(root, u, v, c);
        }
    }
    inorder(root);
    return 0;
}