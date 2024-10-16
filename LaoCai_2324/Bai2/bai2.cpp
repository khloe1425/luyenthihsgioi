#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính tích các thừa số nguyên tố khác nhau của n
long long calculateS(int n, const vector<int>& primes) {
    long long s = 1;
    for (int prime : primes) {
        if (prime > n) break; // Dừng nếu số nguyên tố lớn hơn n
        if (n % prime == 0) { // Nếu prime là thừa số của n
            s *= prime; // Nhân vào tích S
            // Loại bỏ tất cả các lần xuất hiện của prime trong n
            while (n % prime == 0) {
                n /= prime;
            }
        }
    }
    return s;
}

// Hàm chính
int main() {
    ifstream infile("bai2.inp");
    ofstream outfile("bai2.out");

    int M;
    infile >> M;

    // Sàng Eratosthenes để tìm tất cả các số nguyên tố <= M
    vector<bool> is_prime(M + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false; // 0 và 1 không phải là số nguyên tố
    for (int i = 2; i <= M; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= M; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Tìm số N ≤ M có S lớn nhất
    int resultN = 0;
    long long maxS = 0;

    for (int i = 2; i <= M; ++i) {
        long long s = calculateS(i, primes);
        // Cập nhật nếu tìm thấy giá trị S lớn hơn
        if (s > maxS) {
            maxS = s;
            resultN = i;
        } else if (s == maxS && i > resultN) {
            resultN = i; // Lưu số lớn nhất nếu S bằng nhau
        }
    }

    // Ghi kết quả vào tệp
    outfile << resultN << endl;

    infile.close();
    outfile.close();
    return 0;
}
