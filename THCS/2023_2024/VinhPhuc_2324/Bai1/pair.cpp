#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Hàm Sieve of Eratosthenes để tạo danh sách số nguyên tố
vector<bool> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;  // 0 và 1 không phải là số nguyên tố
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Hàm đếm cặp số nguyên tố
int count_prime_pairs(int n, int k) {
    vector<bool> is_prime = sieve_of_eratosthenes(n);
    int count = 0;
    for (int x = 2; x <= n - k; ++x) { // x phải lớn hơn 1 và y = x + k <= n
        int y = x + k;
        if (is_prime[x] && y <= n && is_prime[y]) {
            count++;
        }
    }
    return count;
}

int main() {
    // Đọc dữ liệu từ file input
    ifstream infile("pair.inp");
    int n, k;
    infile >> n >> k;
    infile.close();

    // Tính toán số lượng cặp
    int result = count_prime_pairs(n, k);

    // Ghi kết quả vào file output
    ofstream outfile("pair.out");
    outfile << result << endl;
    outfile.close();

    return 0;
}
