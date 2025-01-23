#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_M = 1000000;

vector<int> num_divisors(MAX_M + 1, 1);
vector<vector<int>> prime_factors(MAX_M + 1);

void preprocess() {
    for (int i = 2; i <= MAX_M; ++i) {
        if (prime_factors[i].empty()) { // i là số nguyên tố
            for (int j = i; j <= MAX_M; j += i) {
                prime_factors[j].push_back(i);

                int tmp = j, count = 0;
                while (tmp % i == 0) {
                    tmp /= i;
                    count++;
                }
                num_divisors[j] *= (count + 1);
            }
        }
    }
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("NTO.INP");
    ofstream output("NTO.OUT");

    int T;
    input >> T;

    preprocess(); // Tiền xử lý sàng Eratosthenes

    while (T--) {
        int M;
        input >> M;

        // Số lượng ước của M
        int divisors = num_divisors[M];

        // Danh sách thừa số nguyên tố
        vector<int> factors = prime_factors[M];

        // Ghi kết quả
        output << divisors << " ";
        for (int i = 0; i < factors.size(); ++i) {
            int factor = factors[i];
            int power = 0, tmp = M;
            while (tmp % factor == 0) {
                tmp /= factor;
                power++;
            }
            output << factor;
            if (power > 1) output << "^" << power;
            if (i < factors.size() - 1) output << "*";
        }
        output << endl;
    }

    // Đóng file
    input.close();
    output.close();

    return 0;
}
