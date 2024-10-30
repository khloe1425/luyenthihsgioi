#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void prime_factorization(long long N, vector<pair<long long, int>>& factors) {
    // Xử lý số 2
    int count = 0;
    while (N % 2 == 0) {
        count++;
        N /= 2;
    }
    if (count > 0) {
        factors.push_back({2, count});
    }

    // Xử lý các số lẻ từ 3 đến sqrt(N)
    for (long long i = 3; i <= sqrt(N); i += 2) {
        count = 0;
        while (N % i == 0) {
            count++;
            N /= i;
        }
        if (count > 0) {
            factors.push_back({i, count});
        }
    }

    // Nếu N là một số nguyên tố lớn hơn 2
    if (N > 2) {
        factors.push_back({N, 1});
    }
}

int main() {
    // Đọc dữ liệu từ file
    ifstream infile("THUASONT.INP");
    long long N;
    infile >> N;
    infile.close();

    // Lưu các thừa số nguyên tố và số lần xuất hiện của chúng
    vector<pair<long long, int>> factors;

    // Phân tích N thành các thừa số nguyên tố
    prime_factorization(N, factors);

    // Ghi kết quả vào file
    ofstream outfile("THUASONT.OUT");
    outfile << factors.size() << endl; // Số lượng thừa số nguyên tố
    for (const auto& factor : factors) {
        outfile << factor.first << " " << factor.second << endl; // p_i và a_i
    }
    outfile.close();

    return 0;
}
