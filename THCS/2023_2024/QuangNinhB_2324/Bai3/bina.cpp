#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Mở file đầu vào và đầu ra
    ifstream inputFile("bina.inp");
    ofstream outputFile("bina.out");

    // Đọc n và k
    int n, k;
    inputFile >> n >> k;

    // Đọc xâu nhị phân s
    string s;
    inputFile >> s;

    int operations = 0;

    // Thực hiện thay đổi xâu để không có hơn k bít giống nhau liên tiếp
    for (int i = 0; i < n - k; ++i) {
        // Nếu phát hiện k + 1 bít liên tiếp giống nhau
        if (s[i] == s[i + 1]) {
            int count = 1;
            while (i + count < n && s[i] == s[i + count] && count <= k) {
                count++;
            }
            if (count > k) {
                // Lật bít tại vị trí k+1 để phá chuỗi liên tiếp
                s[i + k] = (s[i + k] == '0') ? '1' : '0';
                operations++;
                i += k; // Bỏ qua các bít đã kiểm tra
            }
        }
    }

    // Ghi kết quả ra file output
    outputFile << operations << endl;
    outputFile << s << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
