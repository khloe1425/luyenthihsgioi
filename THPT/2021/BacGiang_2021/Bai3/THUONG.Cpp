#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("THUONG.INP");
    ofstream output("THUONG.OUT");

    int n, m;
    input >> n >> m;

    vector<int> a(n), b(m);

    // Đọc các số trên bảng điện tử
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    // Đọc các số quay thưởng
    for (int i = 0; i < m; ++i) {
        input >> b[i];
    }

    long long total_reward = 0; // Tổng tiền thưởng
    vector<int> remaining;     // Danh sách các số còn lại

    // Xử lý từng số trong danh sách quay thưởng
    for (int j = 0; j < m; ++j) {
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (*it == b[j]) {
                total_reward += b[j]; // Cộng tiền thưởng
                a.erase(it);          // Xóa số khỏi bảng điện tử
                break;                // Thoát ngay sau khi tìm thấy
            }
        }
    }

    // Ghi các số còn lại trên bảng điện tử (giữ nguyên thứ tự)
    for (int num : a) {
        remaining.push_back(num);
    }

    if (remaining.empty()) {
        output << "0\n";
    } else {
        for (size_t i = 0; i < remaining.size(); ++i) {
            output << remaining[i];
            if (i < remaining.size() - 1) {
                output << " ";
            }
        }
        output << "\n";
    }

    // Ghi tổng tiền thưởng
    output << total_reward << "\n";

    // Đóng file
    input.close();
    output.close();

    return 0;
}
