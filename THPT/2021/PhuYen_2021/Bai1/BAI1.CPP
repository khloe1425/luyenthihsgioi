#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm sinh các số siêu nguyên tố
void generateSuperPrimes(int n, int current, int digits, vector<int>& result) {
    if (digits == n) { // Nếu đạt đủ n chữ số, lưu kết quả
        result.push_back(current);
        return;
    }

    for (int d = 1; d <= 9; d += 2) { // Thêm các chữ số lẻ (vì chữ số chẵn sẽ không là số nguyên tố trừ 2)
        int nextNumber = current * 10 + d;
        if (isPrime(nextNumber)) { // Kiểm tra số mới có phải nguyên tố không
            generateSuperPrimes(n, nextNumber, digits + 1, result);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI1.INP");
    ofstream fout("BAI1.OUT");

    int n;
    fin >> n;

    vector<int> result;

    // Bắt đầu từ các số nguyên tố có 1 chữ số: 2, 3, 5, 7
    vector<int> startPrimes = {2, 3, 5, 7};
    for (int prime : startPrimes) {
        generateSuperPrimes(n, prime, 1, result);
    }

    // In kết quả ra file
    sort(result.begin(), result.end());
    for (int num : result) {
        fout << num << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
