#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<bool> sieve_of_eratosthenes(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 và 1 không phải là số nguyên tố
    
    for (int p = 2; p * p <= max_num; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_num; i += p) {
                is_prime[i] = false; // Đánh dấu các bội số của p
            }
        }
    }
    return is_prime;
}

int count_primes_in_range(int A, int B) {
    // Tạo danh sách số nguyên tố từ 1 đến B
    vector<bool> is_prime = sieve_of_eratosthenes(B);
    
    // Đếm số lượng số nguyên tố trong đoạn [A, B]
    int count = 0;
    for (int i = A; i <= B; ++i) {
        if (is_prime[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    ifstream infile("CAU02.INP");
    ofstream outfile("CAU02.OUT");

    int A, B;
    infile >> A >> B; // Đọc A và B từ tệp

    // Đếm số lượng số nguyên tố
    int result = count_primes_in_range(A, B);

    // Ghi kết quả ra tệp
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
