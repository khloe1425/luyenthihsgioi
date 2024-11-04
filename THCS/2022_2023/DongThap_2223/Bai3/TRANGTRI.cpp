#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ tệp TRANGTRI.INP
    ifstream input("TRANGTRI.INP");
    ofstream output("TRANGTRI.OUT");

    int n, k;
    input >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        input >> heights[i];
    }

    // Sắp xếp chiều cao của các cây
    sort(heights.begin(), heights.end());

    int max_count = 1;  // Số cây tối đa có thể lắp đèn
    int current_count = 1;

    for (int i = 1; i < n; ++i) {
        // Kiểm tra xem chiều cao chênh lệch có nằm trong khoảng cho phép không
        if (heights[i] - heights[i - 1] <= k) {
            current_count++;  // Tăng số cây liên tiếp
        } else {
            max_count = max(max_count, current_count);  // Cập nhật số cây tối đa
            current_count = 1;  // Reset lại số cây liên tiếp
        }
    }
    
    // Cập nhật max_count cho lần cuối
    max_count = max(max_count, current_count);

    // Ghi kết quả vào tệp TRANGTRI.OUT
    output << max_count << endl;

    input.close();
    output.close();

    return 0;
}
