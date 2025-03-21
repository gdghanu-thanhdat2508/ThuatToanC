# Thuat toan tarzan 

 1. disc vs low 

 - disc[u] : Đại diện cho thời gian mà đỉnh u được duyệt lần đầu tiên trong DFS.
          Đây là thứ tự duyệt của DFS, và nó luôn tăng dần khi ta đi qua các đỉnh mới.

 - low[u] : Lowest Discovery time Reachable 
    + Giá trị nhỏ nhất của disc[v] mà u có thể quay lui về bằng cách đi qua cạnh ngược hoặc qua cây DFS
    + Giúp xác định xem có cách nào quay lui về tổ tiên mà không cần qua cha trực tiếp.

2. Canh cau va dinh tru 

 - Dinh tru : Là đỉnh mà nếu ta loại bỏ nó, số thành phần liên thông của đồ thị tăng lên.
 - Canh cau : Là cạnh mà nếu ta loại bỏ nó, số thành phần liên thông của đồ thị tăng lên

