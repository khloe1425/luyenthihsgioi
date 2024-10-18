#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ifstream infile("B3.INP");
    ofstream outfile("B3.OUT");

    int n, m;
    infile >> n >> m;

    vector<long long> a(n); // Số viên gạch ở các chồng
    vector<long long> b(m); // Các lượt chơi

    // Đọc số viên gạch ở các chồng
    for (int i = 0; i < n; ++i) {
        infile >> a[i];
    }

    // Đọc các lượt chơi
    for (int i = 0; i < m; ++i) {
        infile >> b[i];
    }

    // Sắp xếp các lượt bốc gạch theo thứ tự giảm dần
    sort(b.rbegin(), b.rend());

    // Theo dõi số gạch đã xếp vào các chồng
    vector<bool> used(n, false);

    // Duyệt qua các lượt bốc gạch
    for (int i = 0; i < m; ++i) {
        // Duyệt qua các chồng để xếp gạch
        for (int j = 0; j < n; ++j) {
            // Chỉ xếp vào chồng j nếu nó chưa được xếp gạch
            if (!used[j]) {
                a[j] += b[i]; // Xếp b[i] vào chồng j
                used[j] = true; // Đánh dấu chồng j đã được sử dụng
                break; // Chuyển sang lượt chơi tiếp theo
            }
        }
    }

    // Tìm số gạch ít nhất sau khi xếp
    long long min_score = *min_element(a.begin(), a.end());

    // Ghi kết quả ra tệp
    outfile << min_score << endl;

    infile.close();
    outfile.close();
    return 0;
}
