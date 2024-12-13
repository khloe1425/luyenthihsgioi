#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("DOIBAN.INP");
    ofstream outputFile("DOIBAN.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    long long a, b;
    inputFile >> a >> b;
    inputFile.close();

    // Tìm bước lặp lại giữa hai bạn (Bộc chung)
    long long lcm_ab = lcm(a, b);

    // Tính số lần trực của hai bạn
    long long u = lcm_ab / a;
    long long v = lcm_ab / b;

    // Ghi kết quả ra file
    outputFile << lcm_ab << endl;
    outputFile << u << " " << v << endl;
    outputFile.close();

    return 0;
}
