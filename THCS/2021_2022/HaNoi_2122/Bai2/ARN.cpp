#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("ARN.INP");
    ofstream output("ARN.OUT");

    string S, X;
    input >> S >> X;

    int count = 0; // Số lần xuất hiện không chồng lấn
    size_t pos = 0; // Vị trí bắt đầu tìm kiếm

    // Tìm chuỗi X trong S
    while ((pos = S.find(X, pos)) != string::npos) {
        count++;
        pos += X.size(); // Nhảy qua toàn bộ chuỗi X để không chồng lấn
    }

    output << count << endl;

    input.close();
    output.close();

    return 0;
}
