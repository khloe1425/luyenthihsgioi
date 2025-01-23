#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Hàm tính diện tích lớn nhất của hình chữ nhật sử dụng Histogram
int max_histogram_area(vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int n = heights.size();
    vector<int> left(n), right(n);

    // Tìm vị trí giới hạn bên trái của mỗi cột
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }

    // Dọn sạch stack
    while (!s.empty()) s.pop();

    // Tìm vị trí giới hạn bên phải của mỗi cột
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n - 1 : s.top() - 1;
        s.push(i);
    }

    // Tính diện tích lớn nhất
    for (int i = 0; i < n; i++) {
        max_area = max(max_area, heights[i] * (right[i] - left[i] + 1));
    }

    return max_area;
}

int main() {
    ifstream fin("MESSAGE.INP");
    ofstream fout("MESSAGE.OUT");

    int t;
    fin >> t;

    while (t--) {
        int m, n;
        fin >> m >> n;

        vector<string> A(m), B(m);
        for (int i = 0; i < m; i++) {
            fin >> A[i];
        }
        for (int i = 0; i < m; i++) {
            fin >> B[i];
        }

        // Tạo bảng match
        vector<vector<int>> match(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                match[i][j] = (A[i][j] == B[i][j]) ? 1 : 0;
            }
        }

        // Tạo mảng height và tính diện tích lớn nhất
        vector<int> height(n, 0);
        int max_area = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                height[j] = (match[i][j] == 1) ? height[j] + 1 : 0;
            }
            max_area = max(max_area, max_histogram_area(height));
        }

        fout << max_area << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
