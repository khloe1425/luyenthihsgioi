#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ifstream inputFile("DC.INP");  // Mở file đầu vào
    ofstream outputFile("DC.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N, K;
    inputFile >> N >> K;

    map<long long, int> pointCount;

    // Đọc các đoạn thẳng và đếm số lần mỗi điểm thuộc đoạn
    for (int i = 0; i < N; ++i) {
        long long a, b;
        inputFile >> a >> b;

        // Đảm bảo a <= b
        if (a > b) swap(a, b);

        for (long long j = a; j <= b; ++j) {
            pointCount[j]++;
        }
    }

    // Đếm số điểm nằm trên đúng K đoạn thẳng
    int result = 0;
    for (auto &p : pointCount) {
        if (p.second == K) {
            result++;
        }
    }

    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
