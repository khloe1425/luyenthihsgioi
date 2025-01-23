#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm dãy tăng dần dài nhất từ mảng nguyên tố
vector<int> findLIS(const vector<int>& primes) {
    vector<int> dp(primes.size(), 1); // dp[i] là độ dài LIS kết thúc tại i
    vector<int> prev(primes.size(), -1); // prev[i] lưu chỉ số phần tử trước đó trong LIS
    int maxLength = 0, lastIndex = -1;

    // Tìm LIS
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (primes[j] < primes[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        // Cập nhật độ dài LIS lớn nhất
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    // Truy vết lại dãy LIS đầu tiên
    vector<int> lis;
    for (int i = lastIndex; i >= 0; i = prev[i]) {
        lis.push_back(primes[i]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    ifstream input("NGUYENTO.INP");
    ofstream output("NGUYENTO.OUT");

    int N;
    input >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        input >> A[i];
    }

    // Lọc các số nguyên tố trong mảng
    vector<int> primes;
    for (int i = 0; i < N; ++i) {
        if (isPrime(A[i])) {
            primes.push_back(A[i]);
        }
    }

    // Tìm LIS từ các số nguyên tố
    vector<int> lis = findLIS(primes);

    // Ghi kết quả ra file
    output << lis.size() << endl;
    for (int num : lis) {
        output << num << " ";
    }
    output << endl;

    input.close();
    output.close();

    return 0;
}
