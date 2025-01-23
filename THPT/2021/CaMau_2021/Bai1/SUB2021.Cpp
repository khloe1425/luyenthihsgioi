#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    // Đọc file input
    ifstream input("SUB2021.INP");
    ofstream output("SUB2021.OUT");

    int N;
    input >> N; // Đọc số lượng phần tử trong dãy

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        input >> a[i]; // Đọc các phần tử trong dãy
    }

    // Sử dụng hash map để lưu giá trị dư
    unordered_map<int, int> prefix_remainder;
    prefix_remainder[0] = -1; // Khởi tạo để xử lý trường hợp tổng từ đầu chia hết cho 2021

    int prefix_sum = 0;
    int result_sum = -1; // Lưu tổng đoạn con cần tìm

    for (int i = 0; i < N; ++i) {
        prefix_sum += a[i]; // Tính tổng tích lũy
        int remainder = prefix_sum % 2021;

        // Nếu dư âm (negative), điều chỉnh về dư dương
        if (remainder < 0) {
            remainder += 2021;
        }

        // Kiểm tra nếu dư này đã xuất hiện trước đó
        if (prefix_remainder.count(remainder)) {
            result_sum = 2021; // Tổng đoạn con chia hết cho 2021
            break; // Kết thúc vì đã tìm thấy
        } else {
            prefix_remainder[remainder] = i; // Lưu chỉ số hiện tại
        }
    }

    // Xuất kết quả
    if (result_sum != -1) {
        output << result_sum << endl;
    } else {
        output << -1 << endl; // Không tìm thấy đoạn con
    }

    input.close();
    output.close();

    return 0;
}
