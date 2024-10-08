#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm phân tích số thành các thừa số nguyên tố
vector<int> prime_factors(int n) {
    vector<int> factors;
    
    // Kiểm tra số 2
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    
    // Kiểm tra các số lẻ từ 3 đến √n
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    
    // Nếu n là số nguyên tố lớn hơn 2
    if (n > 2) {
        factors.push_back(n);
    }
    
    return factors;
}

int main() {
    ifstream input("TSNT.INP");
    ofstream output("TSNT.OUT");

    int n;
    input >> n; 

    vector<int> factors = prime_factors(n);

    for (size_t i = 0; i < factors.size(); ++i) {
        output << factors[i];
        if (i < factors.size() - 1) {
            output << "."; 
        }
    }

    input.close();
    output.close();

    return 0;
}
