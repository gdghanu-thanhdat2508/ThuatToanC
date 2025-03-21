#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n, m;
int main() {
    // La 1 cau truc du lieu
    //
    // Don do thi vo huong 
    //  + G = <V, E>
    //      V : Tap cac dinh
    //      E : Tap cac canh
    //  Giua cac canh se co hoac la khong co cac canh noi
    //  Tap hop tat ca dinh va canh, se co cau truc du lieu co ten la do thi
    //  Neu nhu giua 2 dinh voi nhau chi co 1 canh duy nhat => Don do thi 
    //
    //  Da do thi vo huong
    //      Neu giua cac dinh co nhieu canh khac nhau
    //   + G = <V, E>
    //  
    //  Don do thi co huong 
    //      La di thi co huong 
    //          VD : Tu A sang B, B sang C, ...
    //
    //  Ket luan : 4 Loai chinh : 
    //      + Don do thi vo huong ( Duoc su dung nhieu nhat )
    //      + Da do thi vo huong 
    //      + Don do thi co huong 
    //      + Da do thi co huong
    //  
    //  Neu 2 dinh co chung 1 canh noi voi nhau => Goi la 2 dinh ke voi nhau
    //                                          => Canh do duoc goi la canh lien thuoc giua 2 dinh
    //
    //  Bac cua dinh (Doi voi do thi vo huong)
    //      Chinh la so canh ma noi lien voi dinh do
    //          VD : Dinh A co 1 canh noi voi no => Bac cua dinh A la 1
    //
    //      Neu khong co canh nao duoc noi voi no => Bac cua no la 0 va duoc goi la dinh co lap
    //
    //  Bac cua dinh (Doi voi do thi co huong)
    //      + Ban bac ra 
    //          TU dinh do di ra bao nhieu bac khac
    //              VD : Bac A co 3 duong di ra => Ban bac ra cua A la 3
    //      + Ban bac vao
    //          Co bao nhieu canh di vao bac do 
    //              VD : Bac A co 3 canh di vao => Ban bac vao cua A la 3
    //                   Bac B co 0 canh di vao => Bac bac ra cua B la 0
    //
    //  Duong di :
    //      La viec di tu dinh nay sang dinh khac thong qua cac Canh
    //      Neu nhu diem dau va diem cuoi trung nhau => Chu trinh khep kin
    //          VD : Di tu diem A -> B -> C -> A : Day la chu chinh khep kin
    //
    //  Lien Thong :
    //      Do thi VO HUONG duoc goi la lien thong khi tim duoc giua 2 dinh bat ky luon co diem di 
    //      Khong LIEN THONG thi se tao ra cac thanh phan lien thong khac nhau : Chia nho ra thanh cac phan
    //      Tren do thi vo huong, chi can quan tam den khai niem LIEN THONG 
    //      
    //      Tren do thi co huong :
    //          + Lien Thong manh
    //              Giua 2 dinh bat ky luon co duong di giua 2 dinh do
    //          + Lien Thong yeu 
    //              Neu do thi vo huong cua no lien thong nhung khong manh
    //  
    //  Bieu dien do thi : 
    //      Cach 1 : Ma tran ke 
    //          Neu co n dinh thi se can 1 ma tran co co la n x n 
    //              VD : 6 dinh => Ma tran 6 x 6
    //              a[i][j] = 1 khi tu dinh i den dinh j phai co 1 canh noi 
    //              a[i][j] = 0 khi giua dinh i va j khong co canh noi 
    //                  Day se la 1 ma tran doi xung do Do Thi Vo huong
    //                      Neu A noi voi B = 1 thi B noi voi A cx = 1
    //          Neu co trong so, thay vi la 1 hoac 0, se thay bang trong so
    //
    //      Cach 2 : Danh sach canh 
    //          VD : 1 3
    //               1 4
    //               ...
    //          struct edge {
    //              int dau, cuoi, w;
    //          };
    //          w - trong so 
    //
    //          Luu y: Neu la do thi vo huong 
    //              Neu nhu canh 1 2 duoc noi voi nhau
    //              No se chi liet ke 1 2 chu khong liet ke them 2 1 
    //              Khac voi ma tran ke
    //
    //      Cach 3 : Danh sach ke (PP toi uu cua ma tran ke)
    //          Thay vi dung mang 2 chieu, thi su dung mang voi cac vector
    //              VD : vector<int> adj[1001]
    //              Dinh    Danh sach ke
    //              1       {2,3,4}
    //              2       {1, 4}
    //              
    //              Danh sach ke : Luu cac Dinh ma duoc noi voi no 
    //          => HAY SU DUNG NHAT 

    // Thuc hanh 
    //
    //  Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh.
    //  Hãy chuyển đổi đồ thị dưới dạng danh sách cạnh này sang ma trận kề tương ứng.
    
    // 5 4
    // 4 3
    // 3 1
    // 4 2
    // 5 4
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << a[i][j] << "";
        }
        cout << endl;
    }
    
    return 0;
}
