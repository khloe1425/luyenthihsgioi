#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Đọc dữ liệu từ file thamquan.inp
    ifstream infile("thamquan.inp");
    ofstream outfile("thamquan.out");

    int t, a, b;
    infile >> t >> a >> b;  // Đọc dữ liệu: t là thứ, a là giờ vào, b là giờ ra

    int total = 0;  // Biến lưu tổng số tiền

    // Xác định ngày thường hay ngày lễ
    bool isHoliday = (t == 1 || t == 7);  // Chủ nhật và thứ 7 là ngày lễ

    // Tính tiền từ 6 giờ đến 12 giờ
    if (a < 12) {
        int end = min(b, 12);  // Tính khoảng thời gian trong đoạn từ 6 đến 12
        if (isHoliday) {
            total += (end - a) * 10;  // Ngày lễ giá 10 đồng/giờ
        } else {
            total += (end - a) * 6;   // Ngày thường giá 6 đồng/giờ
        }
        a = end;  // Cập nhật giờ bắt đầu tiếp theo
    }

    // Tính tiền từ 12 giờ đến 18 giờ
    if (a < 18 && b > 12) {
        int end = min(b, 18);  // Tính khoảng thời gian trong đoạn từ 12 đến 18
        if (isHoliday) {
            total += (end - a) * 15;  // Ngày lễ giá 15 đồng/giờ
        } else {
            total += (end - a) * 10;  // Ngày thường giá 10 đồng/giờ
        }
        a = end;  // Cập nhật giờ bắt đầu tiếp theo
    }

    // Tính tiền phạt nếu ra sau 18 giờ
    if (b > 18) {
        total += (b - 18) * 20;  // Phạt 20 đồng/giờ sau 18 giờ
    }

    // Ghi kết quả vào file thamquan.out
    outfile << total << endl;

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
