#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Hàm sinh dãy Fibonacci
vector<long long> generateFibonacci(long long maxLimit) {
    vector<long long> fib = {1, 2};
    while (true) {
        long long nextFib = fib.back() + fib[fib.size() - 2];
        if (nextFib > maxLimit) break;
        fib.push_back(nextFib);
    }
    return fib;
}

// Hàm tìm tập con thỏa mãn điều kiện
bool findSubset(const vector<long long>& fib, int n, long long k, vector<long long>& subset) {
    int total = 1 << n; // Tổng số tập hợp con (2^n)
    for (int mask = 0; mask < total; ++mask) {
        long long sum = 0;
        subset.clear();
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // Chọn số Fibonacci thứ i
                sum += fib[i];
                subset.push_back(fib[i]);
            }
        }
        if (sum == k) return true; // Tìm thấy tập con có tổng bằng k
    }
    return false; // Không tìm thấy
}

int main() {
    // Mở file để đọc và ghi
    ifstream input("FIBSEQ.INP");
    ofstream output("FIBSEQ.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Sinh dãy Fibonacci
    long long maxLimit = 1e15;
    vector<long long> fib = generateFibonacci(maxLimit);

    // Đọc số lượng bộ dữ liệu
    int T;
    input >> T;
    while (T--) {
        int n;
        long long k;
        input >> n >> k;

        vector<long long> subset;
        if (findSubset(fib, n, k, subset)) {
            output << subset.size();
            for (long long num : subset) {
                output << " " << num;
            }
            output << endl;
        } else {
            output << "0" << endl; // Không tìm thấy tập con thỏa mãn
        }
    }

    input.close();
    output.close();
    return 0;
}
