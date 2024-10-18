#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("bina.inp");
    ofstream output("bina.out");

    int n, k;
    input >> n >> k;
    string s;
    input >> s;

    int changes = 0;
    string result = s;

    for (int i = 0; i < n;) {
        int count = 1; // Đếm số bit giống nhau liên tiếp

        // Đếm số bit giống nhau liên tiếp
        while (i + 1 < n && result[i] == result[i + 1]) {
            count++;
            i++;
        }

        // Nếu số bit giống nhau liên tiếp lớn hơn k, cần sửa đổi
        if (count > k) {
            // Cần sửa đổi bit
            for (int j = k; j < count; j++) {
                // Chọn bit cần sửa
                result[i - j + 1] = (result[i - j + 1] == '1') ? '0' : '1'; // Lật bit
                changes++;
            }
        }

        i++; // Tiến tới ký tự tiếp theo
    }

    // Ghi kết quả ra tệp
    output << changes << endl;
    output << result << endl;

    return 0;
}
