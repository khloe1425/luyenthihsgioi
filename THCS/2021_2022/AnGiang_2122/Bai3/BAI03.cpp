#include <iostream>
#include <fstream>

// Hàm thực hiện phép lũy thừa theo modulo
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Hàm tìm số nguyên nhỏ nhất a sao cho a^a chia hết cho N
int find_smallest_a(int N) {
    int a = 1;
    while (true) {
        if (mod_exp(a, a, N) == 0) {
            return a;
        }
        a++;
    }
}

int main() {
    std::ifstream infile("BAI03.INP");
    std::ofstream outfile("BAI03.OUT");

    if (!infile || !outfile) {
        std::cerr << "Lỗi mở file đầu vào hoặc đầu ra!" << std::endl;
        return 1;
    }

    int N;
    while (infile >> N) {
        int result = find_smallest_a(N);
        outfile << result << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}