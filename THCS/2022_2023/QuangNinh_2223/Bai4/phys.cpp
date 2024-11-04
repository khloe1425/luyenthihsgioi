#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Mở file input và output
    ifstream infile("phys.inp");
    ofstream outfile("phys.out");

    // Đọc số lượng học sinh
    int n;
    infile >> n;
    
    // Đọc chiều cao của các học sinh
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        infile >> heights[i];
    }

    long long total_distance = 0;

    // Duyệt qua tất cả các cặp (i, j) với 1 <= i < j <= n
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Lưu chiều cao của đoạn cần sắp xếp
            vector<int> segment(heights.begin(), heights.begin() + j + 1);
            sort(segment.begin(), segment.end()); // Sắp xếp đoạn

            // Tìm vị trí mới của hai học sinh
            int pos_i = find(segment.begin(), segment.end(), heights[i]) - segment.begin();
            int pos_j = find(segment.begin(), segment.end(), heights[j]) - segment.begin();

            // Khoảng cách tối đa
            int max_distance = max(pos_i, pos_j) - min(pos_i, pos_j) + (j - i);

            // Cộng d(i, j) vào tổng
            total_distance += max_distance;
        }
    }

    // Ghi kết quả ra file output
    outfile << total_distance << endl;

    return 0;
}
