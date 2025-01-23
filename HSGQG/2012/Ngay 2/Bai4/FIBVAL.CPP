#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Hàm sinh chuỗi Fibonacci
vector<long long> generateFibonacci(long long limit) {
    vector<long long> fibonacci = {1, 2};
    while (true) {
        long long next = fibonacci[fibonacci.size() - 1] + fibonacci[fibonacci.size() - 2];
        if (next > limit) break;
        fibonacci.push_back(next);
    }
    return fibonacci;
}

// Kiểm tra chu kỳ Fibonacci
bool isFibonacciCyclic(const vector<long long>& fib, long long u, long long v) {
    for (long long i = 0; i < fib.size(); i++) {
        if (fib[i] >= u && fib[i] <= v) {
            return true; // Tồn tại Fibonacci trong khoảng
        }
    }
    return false;
}

int main() {
    ifstream fin("FIBVAL.INP");
    ofstream fout("FIBVAL.OUT");

    int k;
    fin >> k;

    vector<long long> results;

    // Đọc từng bộ test
    for (int test = 0; test < k; test++) {
        long long u, v;
        fin >> u >> v;

        // Sinh các số Fibonacci trong khoảng
        vector<long long> fib = generateFibonacci(v);

        // Kiểm tra chu kỳ Fibonacci
        if (isFibonacciCyclic(fib, u, v)) {
            fout << v - u + 1 << endl; // Chu kỳ Fibonacci
        } else {
            fout << -1 << endl; // Không tồn tại chu kỳ Fibonacci
        }
    }

    fin.close();
    fout.close();

    return 0;
}
