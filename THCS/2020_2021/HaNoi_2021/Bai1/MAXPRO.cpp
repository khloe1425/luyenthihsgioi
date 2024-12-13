#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Hàm tính phần dư một cách an toàn
long long safeModulo(long long x, long long m) {
    return (x % m + m) % m;
}

int main() {
    ifstream inputFile("MAXPRO.INP");
    ofstream outputFile("MAXPRO.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    long long a, b, c, m;
    inputFile >> a >> b >> c >> m;

    // Tính các tích có thể xảy ra
    long long prod1 = a * b;
    long long prod2 = a * c;
    long long prod3 = b * c;

    // Tìm tích lớn nhất
    long long maxProduct = max({prod1, prod2, prod3});

    // Tính phần dư
    long long result = safeModulo(maxProduct, m);

    // Ghi kết quả ra file
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
