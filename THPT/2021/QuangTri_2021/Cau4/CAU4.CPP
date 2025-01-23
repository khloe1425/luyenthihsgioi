#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
bool isPrime[MAXN];      // Đánh dấu số nguyên tố
int divisorCount[MAXN];  // Số lượng ước của mỗi số
bool isSongPrime[MAXN];  // Đánh dấu số song nguyên tố
int prefixCount[MAXN];   // Mảng tiền tố đếm số song nguyên tố

// Sàng Eratosthenes để tìm các số nguyên tố
void sieve() {
    fill(isPrime, isPrime + MAXN, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// Tiền xử lý để tính số lượng ước và đánh dấu số song nguyên tố
void preprocess() {
    sieve();

    // Tính số lượng ước cho từng số
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisorCount[j]++;
        }
    }

    // Đánh dấu số song nguyên tố
    for (int i = 1; i < MAXN; i++) {
        if (isPrime[divisorCount[i]]) {
            isSongPrime[i] = true;
        }
    }

    // Tính mảng tiền tố
    for (int i = 1; i < MAXN; i++) {
        prefixCount[i] = prefixCount[i - 1] + (isSongPrime[i] ? 1 : 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("CAU4.INP");
    ofstream fout("CAU4.OUT");

    preprocess(); // Tiền xử lý

    int T;
    fin >> T;

    while (T--) {
        int a, b;
        fin >> a >> b;
        fout << prefixCount[b] - prefixCount[a - 1] << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
