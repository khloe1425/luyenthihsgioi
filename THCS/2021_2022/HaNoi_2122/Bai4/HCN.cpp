#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Hàm tìm diện tích lớn nhất trong Histogram
int largestRectangle(vector<int>& heights) {
    stack<int> s;
    heights.push_back(0); // Thêm một cột 0 vào cuối để xử lý hết các cột
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        s.push(i);
    }

    return maxArea;
}

int main() {
    ifstream input("HCN.INP");
    ofstream output("HCN.OUT");

    int N, M, K;
    input >> N >> M >> K;

    // Khởi tạo ma trận grid ban đầu
    vector<vector<int>> grid(N + 1, vector<int>(M + 1, 1)); // Mặc định tất cả là '1'
    for (int i = 0; i < K; i++) {
        int d, c;
        input >> d >> c;
        grid[d][c] = 0; // Đánh dấu vị trí chứa 'X'
    }

    // Tính toán chiều cao
    vector<int> height(M + 1, 0); // Chiều cao của mỗi cột
    int maxArea = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (grid[i][j] == 0) {
                height[j] = 0; // Nếu là 'X', chiều cao bằng 0
            } else {
                height[j] += 1; // Nếu không, tăng chiều cao
            }
        }

        // Tính diện tích lớn nhất tại dòng hiện tại
        maxArea = max(maxArea, largestRectangle(height));
    }

    output << maxArea << endl;

    input.close();
    output.close();

    return 0;
}
