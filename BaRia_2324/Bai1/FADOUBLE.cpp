#include <iostream>
#include <fstream>

using namespace std;

// Hàm tính giá trị n!!
long long double_factorial(int n) {
    if (n == 0) {
        return 1;
    }
    
    long long result = 1;
    if (n % 2 == 0) { // n chẵn
        for (int i = 2; i <= n; i += 2) {
            result *= i;
        }
    } else { // n lẻ
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
    }
    return result;
}

int main() {
    ifstream input("FADOUBLE.INP");
    ofstream output("FADOUBLE.OUT");

    int n;
    input >> n; 

    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            total -= double_factorial(i); 
        } else {
            total += double_factorial(i); 
        }
    }

    output << total << endl;

    input.close();
    output.close();

    return 0;
}
