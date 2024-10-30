#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream infile("TAMGIAC.INP");
    ofstream outfile("TAMGIAC.OUT");

    int T;
    infile >> T; // Số bộ test

    for (int i = 0; i < T; ++i) {
        int a, b, c;
        infile >> a >> b >> c; // Đọc ba số góc

        // Kiểm tra điều kiện của tam giác
        if (a + b + c != 180 || a <= 0 || b <= 0 || c <= 0) {
            outfile << 0 << endl; // Không phải là số đo của tam giác
        } else {
            // Xác định loại tam giác
            if (a < 90 && b < 90 && c < 90) {
                outfile << "NHON" << endl; // Tam giác nhọn
            } else if (a == 90 || b == 90 || c == 90) {
                outfile << "VUONG" << endl; // Tam giác vuông
            } else {
                outfile << "TU" << endl; // Tam giác tù
            }
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
