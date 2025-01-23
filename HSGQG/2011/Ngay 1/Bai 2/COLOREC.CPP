#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

const string INPUT_FILE = "COLOREC.INP";
const string OUTPUT_FILE = "COLOREC.OUT";

int main() {
    ifstream input(INPUT_FILE);
    ofstream output(OUTPUT_FILE);

    int n;
    input >> n;

    // Bảng băm lưu các điểm theo hoành độ x
    unordered_map<int, vector<pair<int, int>>> points_by_x;

    // Đọc các điểm
    for (int i = 0; i < n; ++i) {
        int x, y, c;
        input >> x >> y >> c;
        points_by_x[x].emplace_back(y, c);
    }

    input.close();

    long long rectangle_count = 0;

    // Lấy tất cả các giá trị x có điểm
    vector<int> all_x;
    for (const auto& entry : points_by_x) {
        all_x.push_back(entry.first);
    }

    // Duyệt qua tất cả các cặp cột x1, x2
    for (int i = 0; i < all_x.size(); ++i) {
        for (int j = i + 1; j < all_x.size(); ++j) {
            int x1 = all_x[i];
            int x2 = all_x[j];

            // Các điểm thuộc cột x1 và x2
            auto& points_x1 = points_by_x[x1];
            auto& points_x2 = points_by_x[x2];

            // Lưu các cặp màu theo y
            unordered_map<int, set<int>> color_by_y;

            // Duyệt qua các điểm trong x1 và lưu màu theo y
            for (auto& [y, color] : points_x1) {
                color_by_y[y].insert(color);
            }

            // Duyệt qua các điểm trong x2 và đếm hình chữ nhật
            for (auto& [y, color] : points_x2) {
                if (color_by_y.count(y)) {
                    // Nếu tồn tại y trong cả hai cột, kiểm tra màu
                    color_by_y[y].insert(color);
                    if (color_by_y[y].size() == 4) {
                        rectangle_count++;
                    }
                }
            }
        }
    }

    // Ghi kết quả ra file
    output << rectangle_count << endl;
    output.close();

    return 0;
}
