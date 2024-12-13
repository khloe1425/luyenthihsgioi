#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tính tổng các chữ số của một số
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    ifstream inputFile("TIMSNT.INP");
    ofstream outputFile("TIMSNT.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    vector<int> result;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i) && digitSum(i) == m) {
            result.push_back(i);
        }
    }

    outputFile << result.size() << endl;
    for (size_t i = 0; i < result.size(); i++) {
        outputFile << result[i];
        if (i < result.size() - 1) outputFile << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
