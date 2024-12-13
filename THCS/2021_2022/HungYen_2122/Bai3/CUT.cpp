#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm tìm số lần xuất hiện của xâu P trong xâu S
int countOccurrences(const string& S, const string& P) {
    int count = 0;
    size_t pos = 0;

    // Tìm kiếm các vị trí xuất hiện của P trong S
    while ((pos = S.find(P, pos)) != string::npos) {
        count++;
        pos += P.size(); // Tiếp tục tìm kiếm từ vị trí sau đoạn đã tìm thấy
    }

    return count;
}

int main() {
    ifstream input("CUT.INP");
    ofstream output("CUT.OUT");

    string S, P;
    getline(input, S);
    getline(input, P);

    // Đếm số lần xuất hiện của P trong S
    int maxOccurrences = countOccurrences(S, P);

    // Ghi kết quả ra file
    output << maxOccurrences << endl;

    input.close();
    output.close();

    return 0;
}
