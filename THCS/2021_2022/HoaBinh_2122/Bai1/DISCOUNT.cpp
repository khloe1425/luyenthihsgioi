#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm kiểm tra xem số x có thỏa mãn yêu cầu với giá trị target
bool isValid(int x, int target) {
    string xStr = to_string(x);
    if (xStr.length() != 4) return false; // Kiểm tra số có đúng 4 chữ số

    int sumFirst = (xStr[0] - '0') + (xStr[1] - '0'); // Tổng 2 chữ số đầu
    int sumLast = (xStr[2] - '0') + (xStr[3] - '0');  // Tổng 2 chữ số cuối
    return (sumFirst * 10 + sumLast) == target;       // Kiểm tra tổng
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("DISCOUNT.INP");
    ofstream output("DISCOUNT.OUT");

    int n; // Giá trị cần tìm
    input >> n;

    bool found = false; // Đánh dấu nếu tìm thấy số hợp lệ
    for (int x = 1000; x <= 9999; x++) { // Duyệt qua tất cả các số 4 chữ số
        if (isValid(x, n)) {
            output << x << endl; // Ghi số tìm được vào file
            found = true;
            break;
        }
    }

    if (!found) {
        output << 0 << endl; // Ghi 0 nếu không tìm được
    }

    input.close();
    output.close();
    return 0;
}
