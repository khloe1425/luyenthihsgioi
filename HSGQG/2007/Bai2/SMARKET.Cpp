#include <bits/stdc++.h>
using namespace std;

// Ta giới hạn: s ≤ 500, số cách có thể rất lớn nên dùng long long để đếm.
// Kế hoạch: Dùng DP kiểu "đếm số cách" + "lưu vết".
//    dp[i][v] = số cách mua (từ item 1..i) để đạt tổng giá v.
//    dp[0][0] = 1, dp[0][v>0] = 0.
//    dp[i][v] = ∑_{k=0..m_i, v-k*c_i >=0} dp[i-1][v-k*c_i].
//
// Để lưu 1 cách mua, ta cất "parent[i][v]" = k (lượng item i) dẫn đến dp[i][v] > 0 đầu tiên.
//
// Cuối cùng, kết quả = dp[n][s]. Nếu >0 thì ta lần ngược lại để truy ra x_n..x_1.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file vào/ra
    ifstream fin("SMARKET.INP");
    ofstream fout("SMARKET.OUT");

    // Đọc s, n
    int s, n;
    fin >> s >> n;

    // Đọc c[i], m[i]
    vector<int> c(n+1), m(n+1);
    for(int i=1; i<=n; i++){
        fin >> c[i] >> m[i];
    }

    // Tạo mảng dp và parent
    // dp[i][v] là số cách (long long) để đạt tổng giá v dùng những mặt hàng 1..i
    static long long dp[5010][501]; 
    // parent[i][v] = -1 nếu dp[i][v]=0, còn lại ghi "số lượng mặt hàng i" ta chọn
    static int parent[5010][501];

    // i chạy đến n, v chạy đến s
    // ta sẽ dùng dp cỡ (n+1) x (s+1) => n <= 500, s <= 500 thì vẫn ổn

    // Khởi tạo dp[0][0] = 1
    dp[0][0] = 1;
    parent[0][0] = 0; // 0 nghĩa là "không dùng"

    for(int v=1; v<=s; v++){
        dp[0][v] = 0;
        parent[0][v] = -1;
    }

    // Tính DP
    for(int i=1; i<=n; i++){
        for(int v=0; v<=s; v++){
            // dp[i][v] = sum_{k=0..m[i], v-k*c[i] >=0} dp[i-1][v-k*c[i]]
            long long ways = 0;
            int chosenK = -1;
            for(int k=0; k<=m[i]; k++){
                int prevV = v - k*c[i];
                if(prevV < 0) break; // không còn hợp lệ
                if(dp[i-1][prevV] > 0){
                    ways += dp[i-1][prevV];
                    // nếu chưa chọn k để lưu vết, ta lấy k đầu tiên
                    if(chosenK < 0){
                        chosenK = k;
                    }
                }
            }
            dp[i][v] = ways;
            if(ways>0){
                parent[i][v] = chosenK; 
            } else {
                parent[i][v] = -1; 
            }
        }
    }

    // Số cách = dp[n][s]
    long long totalWays = dp[n][s];
    fout << totalWays << "\n";

    // Nếu totalWays > 0 thì ta cần truy vết ra 1 cách
    if(totalWays > 0){
        vector<int> buy(n+1, 0);
        int v = s;
        for(int i=n; i>=1; i--){
            int used = parent[i][v];
            buy[i] = used;
            v -= used * c[i];
        }
        // In ra từ 1..n
        for(int i=1; i<=n; i++){
            fout << buy[i];
            if(i<n) fout << " ";
        }
        fout << "\n";
    }

    return 0;
}
