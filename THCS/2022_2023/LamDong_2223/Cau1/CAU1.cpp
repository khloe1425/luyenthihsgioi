#include <iostream>
#include <fstream>

using namespace std;

long long calculate_sum(long long n) {
    long long total_sum = 0;
    for (long long i = 1; i < n; i++) {
        total_sum += i * (i + 1) * (i + 2);
    }
    return total_sum;
}

int main() {
    long long n;

    // Đọc dữ liệu từ file
    ifstream input_file("CAU1.INP");
    input_file >> n;  // Đọc n
    input_file.close();

    // Tính tổng theo công thức đã cho
    long long result = calculate_sum(n);

    // Ghi kết quả vào file
    ofstream output_file("CAU1.OUT");
    output_file << result << endl;
    output_file.close();

    return 0;
}
