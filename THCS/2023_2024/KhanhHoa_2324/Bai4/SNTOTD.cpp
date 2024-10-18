#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số nguyên tố toàn diện
bool is_complete_prime(int x) {
    // Kiểm tra x có phải là số nguyên tố
    if (!is_prime(x)) return false;

    // Kiểm tra loại bỏ các chữ số bên phải
    int temp = x;
    while (temp > 0) {
        if (!is_prime(temp)) return false;
        temp /= 10;  // Bỏ chữ số bên phải
    }

    // Kiểm tra thêm các chữ số từ 0 đến 9 vào bên phải
    for (int d = 0; d < 10; d++) {
        if (is_prime(x * 10 + d)) return true;  // Nếu có ít nhất 1 số nguyên tố
    }
    return false;
}

int main() {
    // Đọc dữ liệu từ tệp
    ifstream infile("SNTOTD.INP");
    ofstream outfile("SNTOTD.OUT");

    int n;
    infile >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        infile >> A[i];
    }

    int m;
    infile >> m;
    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; i++) {
        infile >> queries[i].first >> queries[i].second;
    }

    // Tạo danh sách số nguyên tố toàn diện
    vector<int> complete_primes(n);
    for (int i = 0; i < n; i++) {
        complete_primes[i] = is_complete_prime(A[i]) ? 1 : 0;
    }

    // Tính prefix sum cho số nguyên tố toàn diện
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + complete_primes[i - 1];
    }

    // Xử lý các câu hỏi
    for (const auto& query : queries) {
        int u = query.first, v = query.second;
        int count = prefix_sum[v] - prefix_sum[u - 1];
        outfile << count << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
