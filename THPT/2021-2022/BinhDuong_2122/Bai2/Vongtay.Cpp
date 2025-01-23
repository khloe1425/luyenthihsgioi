#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm kiểm tra nếu chuỗi mẫu có thể lặp lại để tạo thành chuỗi gốc
bool is_valid_pattern(const string& s, int k) {
    // Chuỗi mẫu là đoạn đầu dài k
    string pattern = s.substr(0, k);

    // So sánh từng ký tự trong chuỗi gốc với chuỗi mẫu lặp lại
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != pattern[i % k]) {
            return false; // Nếu có ký tự không khớp, chuỗi mẫu không hợp lệ
        }
    }
    return true; // Nếu tất cả ký tự khớp, chuỗi mẫu hợp lệ
}

int main() {
    ifstream infile("Vongtay.inp");
    ofstream outfile("Vongtay.out");

    int N;
    string s;

    // Đọc dữ liệu từ file
    infile >> N;
    infile >> s;

    // Tìm độ dài chuỗi mẫu nhỏ nhất
    for (int k = 1; k <= N; k++) {
        if (N % k == 0 && is_valid_pattern(s, k)) {
            outfile << k << endl; // Ghi kết quả vào file
            break; // Thoát vòng lặp ngay khi tìm thấy chu kỳ hợp lệ
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
