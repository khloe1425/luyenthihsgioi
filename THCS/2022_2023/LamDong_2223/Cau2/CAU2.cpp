#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // cho std::pair
#include <cmath>   // cho sqrt

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra giả thuyết Goldbach
void checkGoldbachConjecture(int n, const vector<long long>& numbers, ofstream& outputFile) {
    for (long long k : numbers) {
        pair<long long, long long> bestPair(0, 0);
        bool found = false;

        // Tìm cặp số nguyên tố i và j sao cho i + j = k
        for (long long i = 2; i <= k / 2; i++) {
            long long j = k - i;
            if (isPrime(i) && isPrime(j)) {
                // Cập nhật cặp số nếu là cặp tốt hơn
                if (abs(i - j) > abs(bestPair.first - bestPair.second)) {
                    bestPair = make_pair(i, j);
                }
                found = true;
            }
        }

        // Ghi kết quả vào file
        if (found) {
            outputFile << min(bestPair.first, bestPair.second) << " " << max(bestPair.first, bestPair.second) << endl;
        } else {
            outputFile << "NO" << endl;
        }
    }
}

int main() {
    ifstream inputFile("CAU2.INP");
    ofstream outputFile("CAU2.OUT");

    int n;
    inputFile >> n; // Đọc số lượng test
    vector<long long> numbers(n);

    // Đọc các số chẵn
    for (int i = 0; i < n; i++) {
        inputFile >> numbers[i];
    }

    // Kiểm tra giả thuyết Goldbach
    checkGoldbachConjecture(n, numbers, outputFile);

    inputFile.close();
    outputFile.close();
    return 0;
}
