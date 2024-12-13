#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm đảo ngược số
int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Hàm tính số thứ K của bài toán 1
int findKthInSequence1(int K) {
    int current = 1;
    for (int i = 2; i <= K; i++) {
        current = reverseNumber(current) + 2;
    }
    return current;
}

// Hàm tính số thứ K của bài toán 2
int findKthInSequence2(int K) {
    int count = 0;
    int current = 1;
    while (count < K) {
        if (current % 2 == 1 && current % 5 != 0) {
            count++;
            if (count == K) {
                return current;
            }
        }
        current++;
    }
    return -1; // Trường hợp không xảy ra
}

int main() {
    ifstream inputFile("BAI05.INP");
    ofstream outputFile("BAI05.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    long long K;
    inputFile >> K;

    // Kết quả bài toán 1
    int result1 = findKthInSequence1(K);

    // Kết quả bài toán 2
    int result2 = findKthInSequence2(K);

    // Ghi kết quả ra file
    outputFile << result1 << endl;
    outputFile << result2 << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
