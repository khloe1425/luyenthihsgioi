#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Hàm kiểm tra điều kiện chia hết cho 30
bool isDivisibleBy30(const string& number) {
    // Kiểm tra chia hết cho 2
    if (number.find('0') == string::npos) {
        return false; // Không có chữ số 0, không chia hết cho 2
    }

    // Kiểm tra chia hết cho 3
    int sumDigits = 0;
    for (char c : number) {
        sumDigits += (c - '0');
    }

    return (sumDigits % 3 == 0);
}

int main() {
    ifstream input("BAI2.INP");
    ofstream output("BAI2.OUT");

    string N;
    input >> N;

    // Kiểm tra điều kiện
    if (!isDivisibleBy30(N)) {
        output << -1 << endl;
    } else {
        // Sắp xếp các chữ số theo thứ tự giảm dần
        sort(N.rbegin(), N.rend());
        output << N << endl;
    }

    input.close();
    output.close();

    return 0;
}
