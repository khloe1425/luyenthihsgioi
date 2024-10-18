#include <iostream>
#include <vector>

using namespace std;

// Hàm tìm tất cả các cách chia sách hợp lệ
vector<vector<int>> findWaysToStackBooks(int N) {
    vector<vector<int>> ways;  // Danh sách các cách chia sách hợp lệ

    // Tìm tất cả các dãy liên tiếp có tổng bằng N
    int k = 2;  // Số chồng sách bắt đầu từ 2 trở lên
    while (k * (k + 1) / 2 <= N) {  // Điều kiện tổng tối thiểu của dãy liên tiếp phải <= N
        // Tính giá trị x từ công thức S = k(2x + k - 1) / 2 = N
        if ((N - k * (k - 1) / 2) % k == 0) {
            int x = (N - k * (k - 1) / 2) / k;  // Tính x
            if (x > 0) {  // x phải là số tự nhiên dương
                // Tạo dãy liên tiếp bắt đầu từ x và có k phần tử
                vector<int> way;
                for (int i = 0; i < k; ++i) {
                    way.push_back(x + i);
                }
                ways.push_back(way);
            }
        }
        k++;
    }
    return ways;
}

int main() {
    int N;
    cout << "Nhap so sach N: ";
    cin >> N;

    vector<vector<int>> ways = findWaysToStackBooks(N);

    if (!ways.empty()) {
        cout << ways.size() << endl;  
        for (const auto& way : ways) {
            for (size_t i = 0; i < way.size(); ++i) {
                if (i > 0) cout << " + ";
                cout << way[i];
            }
            cout << endl;
        }
    } else {
        cout << 0 << endl; 
    }

    return 0;
}
