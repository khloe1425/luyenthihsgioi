#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Hàm tìm ước của một số
vector<long long> findDivisors(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// Hàm tìm ước chung lớn nhất (GCD) sử dụng thuật toán Euclid
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ifstream input("UOCCHUNG.INP");
    ofstream output("UOCCHUNG.OUT");
    
    long long A, B;
    input >> A >> B;

    // Tìm ước chung lớn nhất (GCD)
    long long gcdValue = gcd(A, B);

    // Tìm các ước của GCD
    vector<long long> divisors = findDivisors(gcdValue);

    // Lấy ước lớn thứ hai
    long long secondLargestDivisor = (divisors.size() > 1) ? divisors[divisors.size() - 2] : divisors[0];

    // Ghi kết quả vào tệp
    output << secondLargestDivisor << endl;

    input.close();
    output.close();

    return 0;
}
