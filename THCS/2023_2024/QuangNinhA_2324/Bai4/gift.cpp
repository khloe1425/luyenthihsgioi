#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Hàm tính ước chung lớn nhất (GCD)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ifstream input_file("gift.inp");
    ofstream output_file("gift.out");

    int n;
    input_file >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        input_file >> a[i];
    }

    // Tính tích toàn bộ dãy
    long long total_product = accumulate(a.begin(), a.end(), 1LL, std::multiplies<long long>());

    long long product_prefix = 1;

    for (int l = 0; l < n - 1; ++l) {  // Không tính đến phần tử cuối cùng
        product_prefix *= a[l];

        // Tính tích phần sau
        long long product_suffix = total_product / product_prefix;

        // Kiểm tra nếu GCD của hai tích bằng 1
        if (gcd(product_prefix, product_suffix) == 1) {
            output_file << l + 1 << endl;  // Ghi vị trí cắt vào tệp
            break;
        }
    }

    input_file.close();
    output_file.close();
    return 0;
}
