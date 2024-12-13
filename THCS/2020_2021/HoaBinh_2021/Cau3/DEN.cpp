#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("DEN.INP");
    ofstream outputFile("DEN.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int N;
    double L;
    inputFile >> N >> L;

    vector<double> A(N);
    for (int i = 0; i < N; i++) {
        inputFile >> A[i];
    }

    // Sắp xếp các cột đèn
    sort(A.begin(), A.end());

    // Tính khoảng cách lớn nhất giữa hai cột đèn liên tiếp
    double maxGap = 0.0;
    for (int i = 1; i < N; i++) {
        maxGap = max(maxGap, A[i] - A[i - 1]);
    }

    // Khoảng cách từ đầu đường đến cột đầu tiên và từ cột cuối đến cuối đường
    double startGap = A[0] - 0;
    double endGap = L - A[N - 1];

    // Tính bán kính chiếu sáng tối thiểu
    double d = max({maxGap / 2.0, startGap, endGap});

    // Ghi kết quả ra file với độ chính xác 2 chữ số thập phân
    outputFile << fixed << setprecision(2) << d << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
