#include <iostream>
#include <fstream>
using namespace std;

const int MOD = 1532023;  // Số dư

long long calculate_sum(int M, int N) {
    long long total_sum = 0;

    // Tính tổng các số trên bảng theo quy luật
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if ((i + j) % 2 == 0) {  // Kiểm tra (i + j) có chẵn không
                total_sum += (long long)(i - 1) * N + j;
                total_sum %= MOD;  // Lấy dư ngay sau mỗi lần cộng
            }
        }
    }

    return total_sum;
}

int main() {
    ifstream infile("TONGBANG.INP");
    ofstream outfile("TONGBANG.OUT");

    int M, N;
    infile >> M >> N;  // Đọc giá trị M và N từ tệp

    long long result = calculate_sum(M, N);

    outfile << result << endl;  // Ghi kết quả vào tệp

    infile.close();
    outfile.close();

    return 0;
}
