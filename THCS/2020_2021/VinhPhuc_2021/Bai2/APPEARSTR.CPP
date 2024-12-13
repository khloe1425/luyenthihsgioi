// APPEARSTR.CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("APPEARSTR.INP");
    ofstream output("APPEARSTR.OUT");

    string S;
    input >> S;

    // Mảng đếm số lần xuất hiện của mỗi ký tự ASCII
    vector<int> count(256, 0);

    // Đếm số lần xuất hiện của từng ký tự
    for (char c : S) {
        count[c]++;
    }

    // In các ký tự và số lần xuất hiện theo thứ tự từ điển
    for (int i = 0; i < 256; ++i) {
        if (count[i] > 0) {
            output << (char)i << " " << count[i] << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}
