#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố bằng cách sử dụng Sàng Eratosthenes
void sieve_of_eratosthenes(int max_num, vector<bool>& is_prime) {
    is_prime.assign(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(max_num); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    // Đọc dữ liệu từ file BAI1.INP
    ifstream infile("BAI1.INP");
    ofstream outfile("BAI1.OUT");

    int N;
    infile >> N;

    // Sử dụng sàng để tìm các số nguyên tố
    vector<bool> is_prime;
    sieve_of_eratosthenes(N, is_prime);

    // Tìm hai số nguyên tố có tổng bằng N
    int a = 0, b = 0;
    for (int i = 2; i <= N / 2; i++) {
        if (is_prime[i] && is_prime[N - i]) {
            a = i;
            b = N - i;
            break; // Chỉ lấy cặp đầu tiên
        }
    }

    // Ghi kết quả ra file BAI1.OUT
    if (a > 0 && b > 0) {
        outfile << a << " " << b << endl;
    } else {
        outfile << "Không tìm được cặp số." << endl;
    }

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
