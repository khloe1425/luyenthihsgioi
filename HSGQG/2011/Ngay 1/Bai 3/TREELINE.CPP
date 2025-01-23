#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const long long MOD = 1e9;

// Hàm kiểm tra nếu dãy cây thỏa mãn điều kiện không có 3 cây liên tiếp giảm dần
bool isValid(const vector<int>& trees) {
    int n = trees.size();
    for (int i = 0; i < n - 2; ++i) {
        if (trees[i] > trees[i + 1] && trees[i + 1] > trees[i + 2]) {
            return false; // Tồn tại 3 cây liên tiếp giảm dần
        }
    }
    return true;
}

int main() {
    ifstream input("TREELINE.INP");
    ofstream output("TREELINE.OUT");

    int n, h;
    input >> n >> h;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        input >> heights[i];
    }
    input.close();

    // Đếm số cách chèn cây
    long long validWays = 0;
    for (int i = 0; i <= n; ++i) {
        // Chèn cây mới vào vị trí i
        vector<int> newHeights = heights;
        newHeights.insert(newHeights.begin() + i, h);

        // Kiểm tra nếu thỏa mãn điều kiện
        if (isValid(newHeights)) {
            validWays++;
        }
    }

    // Tính số ngày lớn nhất
    long long maxDays = validWays % MOD;

    // Ghi kết quả ra file
    output << validWays << endl;
    output << maxDays << endl;

    output.close();
    return 0;
}
