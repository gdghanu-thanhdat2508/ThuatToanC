#include <bits/stdc++.h>

using namespace std;
// https://www.youtube.com/watch?v=brcigkrUqPA
// Quay lui giai Sudoku

// Khai bao kich thuoc ban co N * N
int N = 9;

void in(int a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool Check(int board[N][N], int row, int col, int x)
{
    // Hàm check điều kiện
    // Check xem trong hàng đã có giá trị x hay chưa
    for (int j = 0; j < N; j++)
    {
        // Duyệt cột
        if (board[row][j] == x)
        {
            return false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        // Duyệt cột
        if (board[i][col] == x)
        {
            return false;
        }
    }

    //  Check xem vùng 3 x3 hiện tại đã tồn tại số x hay chưa
    //  Chỉ số hàng của ô ở gốc tạo độ của 1 ô đơn vị = i - i % 3
    //  Chỉ số cột của ô ở gốc tạo độ của 1 ô đơn vị = j - j % 3
    int start_row = row - row % 3;
    int start_col = col - col % 3;

    for (int i = start_row; i < 3; i++)
    {
        for (int j = start_col; j < 3; j++)
        {
            if (board[i][j] == x)
            {
                return false;
            }
        }
    }
    return true;
}

// row col => o can dien
bool BackTrack(int board[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
    {
        // Khi da het bang
        return true; // se co 1 phuong an dien neu xet den vi tri cuoi cung cua bang
    }
    if (col == N)
    {
        // Khi hết 1 hàng
        row++;
        col = 0; // Khi xuống dòng thì phải xét lại cột = 0
    }
    if (board[row][col] > 0)
    {
        // Đánh dấu các ô trống
        // Nếu có giá trị rồi thì mình gọi backtrack đến ô tiếp theo trong dòng đó
        return BackTrack(broad, row, col + 1);
    }
    for (int j = 1; j <= 9; j++)
    {
        if (Check(board(board, row, col, j)))
        {
            board[row][col] = j;
            // Lại xét tiếp các ô tiếp theo
            if (BackTrack(board, row, col + 1))
            {
                return true;
            }
        }
        // Nếu điền sai thì phải backtrack lại đổi chỗ cho các ô còn lại
        // Đặt lại = 0 để xét lại
        board[row][col] = 0;
    }
    return false;
}

int main()
{
    int board[N][N] = {};
    if (BackTrack(board, 0, 0))
    {
        in(board);
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}