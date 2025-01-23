#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000000; // Giới hạn R
vector<bool> is_prime;

// Hàm kiểm tra số nguyên tố
void sieve(long long R) {
    is_prime.assign(R + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= R; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= R; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Hàm kiểm tra xâu nhị phân có đối xứng không
bool is_palindrome_binary(int n) {
    string binary = "";
    while (n > 0) {
        binary += (n % 2) + '0'; // Chuyển bit thành ký tự
        n /= 2;
    }
    int l = 0, r = binary.size() - 1;
    while (l < r) {
        if (binary[l] != binary[r]) return false;
        ++l; --r;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("NGTODX.INP");
    ofstream fout("NGTODX.OUT");

    long long L, R;
    fin >> L >> R;

    // Bước 1: Sàng nguyên tố từ 1 đến R
    sieve(R);

    // Bước 2: Kiểm tra và đếm số nguyên tố có xâu nhị phân đối xứng
    int count = 0;
    for (long long i = L; i <= R; ++i) {
        if (is_prime[i] && is_palindrome_binary(i)) {
            count++;
        }
    }

    fout << count << "\n";

    fin.close();
    fout.close();
    return 0;
}
