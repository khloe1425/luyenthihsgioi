#include <iostream>
#include <fstream>
#include <algorithm> // Thư viện để sử dụng hàm __gcd (Greatest Common Divisor)

using namespace std;

// Hàm đọc dữ liệu từ file RUTGON.INP
void read_rutgon_inp(const string& file_path, int& a, int& b) {
    ifstream file(file_path);
    if (file.is_open()) {
        // Đọc hai số a và b
        file >> a >> b;
        file.close();
    }
}

// Hàm ghi kết quả vào file RUTGON.OUT
void write_rutgon_out(const string& file_path, int a, int b) {
    ofstream file(file_path);
    if (file.is_open()) {
        file << a << " " << b << endl;
        file.close();
    }
}

// Hàm rút gọn phân số
void simplify_fraction(int& a, int& b) {
    int gcd_ab = __gcd(a, b); // Tìm ước số chung lớn nhất của a và b
    a /= gcd_ab;              // Chia cả tử số và mẫu số cho ước số chung lớn nhất
    b /= gcd_ab;
}

int main() {
    // Đường dẫn file
    string file_path_inp = "RUTGON.INP";
    string file_path_out = "RUTGON.OUT";

    int a, b;

    // Đọc dữ liệu từ file RUTGON.INP
    read_rutgon_inp(file_path_inp, a, b);

    // Rút gọn phân số
    simplify_fraction(a, b);

    // Ghi kết quả vào file RUTGON.OUT
    write_rutgon_out(file_path_out, a, b);

    return 0;
}
