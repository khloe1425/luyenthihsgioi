#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Hàm để kiểm tra xem P có chứa tất cả các chữ số khác nhau hay không
bool containsDistinctDigits(int P, const set<int>& distinctDigits) {
    set<int> digits;
    while (P > 0) {
        digits.insert(P % 10);
        P /= 10;
    }
    return includes(digits.begin(), digits.end(), distinctDigits.begin(), distinctDigits.end());
}

int main() {
    ifstream inputFile("dayso.inp");
    ofstream outputFile("ketqua.out");

    int n, M;
    inputFile >> n >> M;

    set<int> distinctDigits; // Tập hợp để lưu trữ các giá trị khác nhau
    for (int i = 0; i < n; ++i) {
        int ai;
        inputFile >> ai;
        distinctDigits.insert(ai);
    }
    inputFile.close();

    // Tìm số P
    for (int P = M + 1; P < 2000000000; ++P) {
        if (containsDistinctDigits(P, distinctDigits)) {
            outputFile << P << endl;
            outputFile.close();
            return 0; // Kết thúc chương trình sau khi tìm được P
        }
    }

    outputFile << "Không tìm được" << endl;
    outputFile.close();
    return 0;
}
