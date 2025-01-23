#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm tính tổng các chữ số của một số
int sumOfDigits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ifstream input("DOCAO.INP");
    ofstream output("DOCAO.OUT");

    int n, h;
    input >> n >> h;

    vector<int> result;

    // Duyệt qua tất cả các số từ 2 đến n
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i) && sumOfDigits(i) == h) {
            result.push_back(i);
        }
    }

    // Ghi các số nguyên tố thỏa mãn vào file
    for (int prime : result) {
        output << prime << endl;
    }

    // Ghi tổng số lượng số nguyên tố
    output << result.size() << endl;

    input.close();
    output.close();

    return 0;
}
