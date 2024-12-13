#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("BAI1.INP");
    ofstream output("BAI1.OUT");

    string s;
    input >> s;

    // Mảng đếm tần số cho các ký tự từ '0'-'9' và 'A'-'Z'
    vector<int> count(36, 0);

    // Đếm số lần xuất hiện
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            count[c - '0']++;
        } else if (c >= 'A' && c <= 'Z') {
            count[c - 'A' + 10]++;
        }
    }

    // Ghi tần số ra file, theo thứ tự '0'-'9' và 'A'-'Z'
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) { // Chỉ xuất nếu tần số > 0
            output << char('0' + i) << " " << count[i] << endl;
        }
    }
    for (int i = 10; i < 36; i++) {
        if (count[i] > 0) { // Chỉ xuất nếu tần số > 0
            output << char('A' + (i - 10)) << " " << count[i] << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}
