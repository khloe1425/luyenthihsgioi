#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

// Hàm tiền xử lý để tìm các số phong phú
void preprocess(vector<bool>& isAbundant, vector<int>& prefixAbundant) {
    vector<int> sumDivisors(MAX_N + 1, 0);

    // Tính tổng ước số cho mỗi số
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 2 * i; j <= MAX_N; j += i) {
            sumDivisors[j] += i;
        }
    }

    // Đánh dấu số phong phú
    for (int i = 1; i <= MAX_N; i++) {
        if (sumDivisors[i] > i) {
            isAbundant[i] = true;
        }
    }

    // Tạo mảng prefixAbundant
    for (int i = 1; i <= MAX_N; i++) {
        prefixAbundant[i] = prefixAbundant[i - 1] + (isAbundant[i] ? 1 : 0);
    }
}

int main() {
    ifstream input("RICHNUM.INP");
    ofstream output("RICHNUM.OUT");

    int Q;
    input >> Q;

    vector<bool> isAbundant(MAX_N + 1, false);
    vector<int> prefixAbundant(MAX_N + 1, 0);

    // Tiền xử lý
    preprocess(isAbundant, prefixAbundant);

    // Xử lý các truy vấn
    while (Q--) {
        int L, R;
        input >> L >> R;
        int result = prefixAbundant[R] - prefixAbundant[L - 1];
        output << result << endl;
    }

    input.close();
    output.close();

    return 0;
}
