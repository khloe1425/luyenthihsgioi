#include <iostream>
#include <fstream>
#include <string>

// Hàm đếm tổng số ô trống của một số nguyên n
int count_holes(const std::string &n) {
    int total_holes = 0;

    // Bảng tra cứu số ô trống cho từng chữ số từ 0 đến 9
    int holes[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

    // Duyệt qua từng chữ số của n
    for (char digit : n) {
        int d = digit - '0';  // Chuyển ký tự thành số nguyên
        total_holes += holes[d];  // Cộng số ô trống của chữ số hiện tại vào tổng
    }

    return total_holes;
}

int main() {
    std::ifstream infile("EMPTHOLE.INP");
    std::ofstream outfile("EMPTHOLE.OUT");

    // Kiểm tra xem file đầu vào và đầu ra có mở thành công không
    if (!infile || !outfile) {
        std::cerr << "Lỗi mở file đầu vào hoặc đầu ra!" << std::endl;
        return 1;
    }

    std::string n;
    infile >> n;  // Đọc số nguyên n dưới dạng chuỗi để xử lý từng chữ số

    // Tính tổng số ô trống và ghi vào file đầu ra
    int result = count_holes(n);
    outfile << result << std::endl;

    infile.close();
    outfile.close();

    return 0;
}
