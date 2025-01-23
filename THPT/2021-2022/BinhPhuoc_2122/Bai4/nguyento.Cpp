#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm sử dụng sàng Eratosthenes để tạo danh sách các số nguyên tố
vector<int> sieveOfEratosthenes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false; // 0 và 1 không phải số nguyên tố
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    ifstream infile("nguyento.inp");
    ofstream outfile("nguyento.out");

    int T;
    infile >> T;

    vector<int> queries(T);
    int maxN = 0;

    // Đọc các giá trị N và tìm giá trị lớn nhất
    for (int i = 0; i < T; i++) {
        infile >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    // Dự đoán số lượng nguyên tố cần tìm (dưới maxN * log(maxN))
    int limit = maxN * 15; // Đủ để bao gồm maxN số nguyên tố đầu tiên
    vector<int> primes = sieveOfEratosthenes(limit);

    // Tính kết quả cho từng N
    for (int n : queries) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += primes[i];
        }
        outfile << sum << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
