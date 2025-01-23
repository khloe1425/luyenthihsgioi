#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int A[MAXN][MAXN];       // Ma trận giá trị
int prefix[MAXN][MAXN];  // Ma trận tổng tiền tố

int main() {
    ifstream input("CAU3.INP");
    ofstream output("CAU3.OUT");

    int N, K;
    input >> N >> K;

    // Đọc ma trận A
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            input >> A[i][j];
        }
    }

    // Tính tổng tiền tố
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            prefix[i][j] = A[i][j] 
                         + prefix[i-1][j] 
                         + prefix[i][j-1] 
                         - prefix[i-1][j-1];
        }
    }

    // Tìm tổng lớn nhất của hình vuông KxK
    int max_sum = 0;
    for (int i = K; i <= N; ++i) {
        for (int j = K; j <= N; ++j) {
            // Tổng hình vuông (i-K+1, j-K+1) -> (i, j)
            int total = prefix[i][j] 
                      - prefix[i-K][j] 
                      - prefix[i][j-K] 
                      + prefix[i-K][j-K];
            max_sum = max(max_sum, total);
        }
    }

    // Ghi kết quả
    output << max_sum << endl;

    input.close();
    output.close();
    return 0;
}
