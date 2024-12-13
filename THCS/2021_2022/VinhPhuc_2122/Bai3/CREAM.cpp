#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

int main() {
    // Mở file input và output
    ifstream inputFile("CREAM.inp");
    ofstream outputFile("CREAM.out");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    // Dùng set để lưu các cặp "xấu"
    set<pair<int, int>> badPairs;

    for (int i = 0; i < m; i++) {
        int x, y;
        inputFile >> x >> y;
        // Đảm bảo luôn lưu (x, y) với x < y để dễ kiểm tra
        if (x > y) swap(x, y);
        badPairs.insert({x, y});
    }

    int count = 0;

    // Duyệt qua tất cả các tổ hợp 3 hương vị
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                // Kiểm tra tổ hợp (i, j, k) có chứa cặp "xấu" nào không
                if (badPairs.count({i, j}) || badPairs.count({i, k}) || badPairs.count({j, k})) {
                    continue; // Nếu có cặp xấu, bỏ qua tổ hợp này
                }
                count++;
            }
        }
    }

    // Ghi kết quả ra file
    outputFile << count << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
