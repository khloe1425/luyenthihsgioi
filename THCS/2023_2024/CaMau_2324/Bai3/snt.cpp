#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm thực hiện Sieve of Eratosthenes
vector<bool> sieve_of_eratosthenes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 và 1 không phải là số nguyên tố

    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    ifstream infile("snt.inp");
    ofstream outfile("snt.out");

    int N;
    infile >> N;

    vector<pair<int, int>> ranges(N);
    for (int i = 0; i < N; ++i) {
        infile >> ranges[i].first >> ranges[i].second;
    }

    // Giới hạn để tính số nguyên tố
    const int MAX_LIMIT = 10000000;

    // Tìm các số nguyên tố
    vector<bool> is_prime = sieve_of_eratosthenes(MAX_LIMIT);

    // Tạo mảng tích lũy để đếm số lượng số nguyên tố
    vector<int> prime_count(MAX_LIMIT + 1, 0);
    for (int i = 1; i <= MAX_LIMIT; ++i) {
        prime_count[i] = prime_count[i - 1] + (is_prime[i] ? 1 : 0);
    }

    for (const auto& range : ranges) {
        int Li = range.first;
        int Ri = range.second;
        int count = prime_count[Ri] - prime_count[Li - 1];
        outfile << count << endl;
    }

    return 0;
}
