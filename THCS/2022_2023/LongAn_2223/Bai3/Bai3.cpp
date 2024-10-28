#include <iostream>
#include <unordered_set>

using namespace std;

// Hàm tính tổng bình phương các chữ số của n
long long sum_of_squares_of_digits(long long n) {
    long long total = 0;
    while (n > 0) {
        int digit = n % 10;
        total += digit * digit;
        n /= 10;
    }
    return total;
}

// Hàm kiểm tra xem n có dẫn đến 1 không
bool leads_to_one(long long n) {
    unordered_set<long long> seen;  // Tập hợp để lưu các số đã thấy
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = sum_of_squares_of_digits(n);
    }
    return n == 1;
}

// Hàm tìm số K
long long find_k(long long n) {
    long long k = n + 1;  // Bắt đầu từ N + 1
    while (true) {
        if (leads_to_one(k)) {
            return k;
        }
        k++;  // Kiểm tra số tiếp theo
    }
}

int main() {
    long long N;
    cout << "Nhập số nguyên dương N: ";
    cin >> N;  // Nhập N từ bàn phím
    long long K = find_k(N);
    cout << K << endl;  // Xuất K ra màn hình
    return 0;
}
