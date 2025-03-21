#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef pair<int, int> ii;
// Gia tri + thao tac

int solve(int s, int t)
{
    queue<ii> q;
    q.push({s, 0}); // Day vao hang doi de lam dinh bat dau
    // pair : <dinh, so thao tac bien doi>

    set<int> used;
    used.insert(s); // Tai vi ban dau co moi thang s
    while (!q.empty())
    {
        ii x = q.front();
        q.pop();
        if (x.first == t)
        {
            // Bien doi den trang tai cua so t, return ve so thao tac thuc hien
            return x.second;
        }
        // Tu trang thai x.first se bien doi thanh 1 trong 2 trang thai
        // x.first - 1 hoac * 2
        if (used.count(x.first - 1) == 0 && x.first - 1 > 0) // Lon hon khong can nhan 2 ma chi can tru di thoi
        {
            q.push({x.first - 1, x.second + 1});
            used.insert(x.first - 1); // Bien doi trang thai hien tai voi thao tac - 1
        }
        if (used.cound(x.first * 2) == 0 && x.first < t) // Nho hon moi can nhan 2
        {
            q.push({x.first * 2, x.second + 1});
            used.insert(x.first * 2);
        }
    }
    return -1;
}

int main()
{
    // queue<int> q;
    // FIFO
    // push front pop size empty back
    // Push va pop se thuc hien o 2 dau
    // Push -> Day o cuoi
    // Pop -> lay o dau hang doi

    // Bài toán 1: Tìm số thao tác ít nhất để biến đổi từ số thứ 1 sang số thứ 2.
    // Dạng bài tập này ta coi mỗi trạng thái của số như 1 định của đô thị và thao tác biến đối
    // giữa 2 số như là cạnh của đồ thị, khi đó bài toán tương tự như tìm đường đi ngẫn nhất giữa 2
    // đinh của đồ thị

    // BFS ma ta da hoc

    // Cho 2 so S va T
    // Cho 2 Thang tac A : tru S di 1 don vi
    // Thao tac B : Nhan S voi 2
    // Bien thang S thanh thang T sao cho so lan thuc hien thao tac A B la it nhat
    // => Day chinh la Thuat toan BFS

    // Trang thai da xet ma lap lai thi se khong xet nua
    // Den luc nao do se tu thang thai S sang trang thai T

    int T;
    cin >> T;
    while (T--)
    {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
    return 0;
}