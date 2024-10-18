#include <iostream>
#include <fstream>

using namespace std;
void count_occurrences(const string &input_file, const string &output_file) {
    ifstream infile(input_file);
    ofstream outfile(output_file);

    long long n, k;
    infile >> n >> k;

    long long count = 0;

    // Tìm tất cả các ước số của k
    for (long long i = 1; i * i <= k; ++i) {
        if (k % i == 0) { // i là ước của k
            long long j = k / i; // Tính j

            // Kiểm tra (i, j) và (j, i) có hợp lệ hay không
            if (i <= n && j <= n) {
                count++; // Đếm (i, j)
            }
            if (i != j && j <= n && i <= n) {
                count++; // Đếm (j, i) nếu khác nhau
            }
        }
    }

    outfile << count << endl;

    infile.close();
    outfile.close();
}

int main() {
    count_occurrences("BANGSO.INP", "BANGSO.OUT");

    return 0;
}
