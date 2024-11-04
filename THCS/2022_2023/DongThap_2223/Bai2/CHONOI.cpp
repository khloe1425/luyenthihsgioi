#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ tệp CHONOI.INP
    ifstream input("CHONOI.INP");
    ofstream output("CHONOI.OUT");
    
    int n, k;
    input >> n >> k;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        input >> weights[i];
    }
    
    // Sắp xếp danh sách trọng lượng
    sort(weights.begin(), weights.end());

    int count = 0;
    int left = 0, right = n - 1;

    // Sử dụng phương pháp hai con trỏ
    while (left < right) {
        if (weights[left] + weights[right] <= k) {
            count += (right - left);  // Đếm số cặp hợp lệ
            left++;
        } else {
            right--;
        }
    }

    // Ghi kết quả vào tệp CHONOI.OUT
    output << count << endl;

    input.close();
    output.close();

    return 0;
}
