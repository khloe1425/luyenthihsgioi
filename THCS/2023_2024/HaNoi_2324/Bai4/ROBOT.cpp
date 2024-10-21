#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Hàm giải bài toán robot
vector<int> solve_robot_problem(int N, int M, int Q, int K, const vector<vector<int>>& A, const vector<int>& queries) {
    // Tạo một mảng dp để lưu số lượng ô thỏa mãn điều kiện Ai,j % K = X cho mỗi X
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(K, 0)));
    
    // Khởi tạo cho ô (1, 1)
    dp[0][0][A[0][0] % K] = 1;
    
    // Tính toán cho toàn bộ bảng A
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 && j == 0) continue; // Bỏ qua ô khởi đầu
            
            int current_mod = A[i][j] % K;
            
            // Lấy giá trị lớn nhất từ các ô (i-1, j), (i, j-1), (i-1, j-1)
            for (int mod = 0; mod < K; ++mod) {
                int max_prev = 0;
                if (i > 0) {
                    max_prev = max(max_prev, dp[i-1][j][mod]);
                }
                if (j > 0) {
                    max_prev = max(max_prev, dp[i][j-1][mod]);
                }
                if (i > 0 && j > 0) {
                    max_prev = max(max_prev, dp[i-1][j-1][mod]);
                }
                
                dp[i][j][mod] = max_prev;
            }
            
            // Cộng thêm 1 cho giá trị mod hiện tại tại ô (i,j)
            dp[i][j][current_mod] += 1;
        }
    }
    
    // Trả lời các truy vấn
    vector<int> result;
    for (int X : queries) {
        result.push_back(dp[N-1][M-1][X]);
    }
    
    return result;
}

// Hàm đọc dữ liệu từ tệp
void read_input(const string& filename, int& N, int& M, int& Q, int& K, vector<vector<int>>& A, vector<int>& queries) {
    ifstream infile(filename);
    infile >> N >> M >> Q >> K;
    
    A.resize(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            infile >> A[i][j];
        }
    }
    
    queries.resize(Q);
    for (int i = 0; i < Q; ++i) {
        infile >> queries[i];
    }
    
    infile.close();
}

// Hàm ghi kết quả ra tệp
void write_output(const string& filename, const vector<int>& result) {
    ofstream outfile(filename);
    for (int r : result) {
        outfile << r << endl;
    }
    outfile.close();
}

int main() {
    int N, M, Q, K;
    vector<vector<int>> A;
    vector<int> queries;
    
    // Đọc dữ liệu từ tệp ROBOT.INP
    read_input("ROBOT.INP", N, M, Q, K, A, queries);
    
    // Giải bài toán
    vector<int> result = solve_robot_problem(N, M, Q, K, A, queries);
    
    // Ghi kết quả ra tệp ROBOT.OUT
    write_output("ROBOT.OUT", result);
    
    return 0;
}
