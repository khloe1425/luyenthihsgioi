#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Hàm đếm số ước nguyên tố của n
int countPrimeFactors(long long n) {
    int count = 0;
    
    // Kiểm tra các số nguyên tố từ 2 đến sqrt(n)
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) { // Nếu i là ước của n
            count++;
            while (n % i == 0) {
                n /= i; // Loại bỏ i khỏi n
            }
        }
    }
    
    // Nếu n > 1 thì n là số nguyên tố
    if (n > 1) {
        count++;
    }
    
    return count;
}

int main() {
    ifstream input("UocNT.Inp");
    ofstream output("UocNT.Out");

    long long n;
    input >> n;

    int result = countPrimeFactors(n);
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
