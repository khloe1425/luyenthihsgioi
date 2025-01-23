#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("CAU1.INP");
    ofstream output("CAU1.OUT");

    int n;
    input >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    int max_length = 1;     // Độ dài lớn nhất của dãy con không giảm
    int current_length = 1; // Độ dài dãy không giảm hiện tại

    // Duyệt qua mảng để tìm dãy con không giảm
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            current_length++;
        } else {
            max_length = max(max_length, current_length);
            current_length = 1;
        }
    }

    // Cập nhật max_length nếu dãy cuối là dài nhất
    max_length = max(max_length, current_length);

    // Ghi kết quả ra file
    output << max_length << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
