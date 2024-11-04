#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int countDancingPairs(vector<int>& heights, int k) {
    sort(heights.begin(), heights.end()); // Sắp xếp danh sách chiều cao
    int count = 0;
    int n = heights.size();

    int left = 0;
    int right = 0;

    while (left < n) {
        // Tìm kiếm vị trí của right
        while (right < n && heights[right] - heights[left] < k) {
            right++;
        }

        // Nếu chênh lệch chiều cao bằng k
        if (right < n && heights[right] - heights[left] == k) {
            // Đếm số chiều cao giống nhau ở bên trái
            int countLeft = 1;
            while (left + 1 < n && heights[left] == heights[left + 1]) {
                countLeft++;
                left++;
            }

            // Đếm số chiều cao giống nhau ở bên phải
            int countRight = 1;
            while (right + 1 < n && heights[right] == heights[right + 1]) {
                countRight++;
                right++;
            }

            // Cộng vào tổng số cặp
            count += countLeft * countRight;
        }

        left++;
    }

    return count;
}

int main() {
    ifstream infile("KHIEUVU.INP");
    ofstream outfile("KHIEUVU.OUT");

    int n, k;
    infile >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        infile >> heights[i];
    }

    // Tính số cặp đôi và ghi vào tệp
    int result = countDancingPairs(heights, k);
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
