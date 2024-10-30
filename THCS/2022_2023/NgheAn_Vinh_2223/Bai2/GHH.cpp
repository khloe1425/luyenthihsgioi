#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Hàm tính tổng các ước dương của số x
long long sumDivisors(int x) {
    long long sum = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            sum += i;
            if (i != x / i) {
                sum += x / i;
            }
        }
    }
    return sum;
}

// Hàm kiểm tra số gần hoàn hảo
bool isNearlyPerfect(int x) {
    long long divisorSum = sumDivisors(x);
    return (2 * x <= divisorSum);
}

int main() {
    ifstream inputFile("GHH.INP");
    ofstream outputFile("GHH.OUT");

    int N;
    inputFile >> N; // Đọc số lượng phần tử N
    vector<int> A(N);

    // Đọc dãy số A
    for (int i = 0; i < N; ++i) {
        inputFile >> A[i];
    }

    // Kiểm tra từng phần tử trong dãy có phải là số "gần hoàn hảo" hay không
    for (int i = 0; i < N; ++i) {
        if (isNearlyPerfect(A[i])) {
            outputFile << "1" << endl;
        } else {
            outputFile << "0" << endl;
        }
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
