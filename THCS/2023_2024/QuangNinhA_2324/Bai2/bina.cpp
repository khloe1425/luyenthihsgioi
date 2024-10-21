#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream infile("bina.inp");
    int n, k;
    infile >> n >> k; // Đọc n và k
    string s;
    infile >> s; // Đọc chuỗi nhị phân

    // Biến để đếm số thao tác và lưu chuỗi sửa đổi
    int operations = 0;
    string result = s; // Lưu chuỗi sửa đổi

    // Duyệt qua chuỗi để kiểm tra và sửa
    int count = 1; // Đếm số lượng bit giống nhau liên tiếp
    for (int i = 1; i < n; ++i) {
        if (result[i] == result[i - 1]) { // Nếu bit giống nhau
            count++;
        } else {
            count = 1; // Đặt lại đếm nếu gặp bit khác
        }

        // Nếu số lượng bit giống nhau vượt quá k
        if (count > k) {
            // Lật bit hiện tại
            operations++;
            result[i] = (result[i] == '1') ? '0' : '1'; // Đảo bit
            count = 1; // Reset đếm về 1 vì vừa lật bit
        }
    }

    // Ghi kết quả ra file
    ofstream outfile("bina.out");
    outfile << operations << endl; // Số thao tác tối thiểu
    outfile << result; // Chuỗi đã sửa đổi

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
