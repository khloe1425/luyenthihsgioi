#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ifstream input("SUMOFNEG.INP");
    ofstream output("SUMOFNEG.OUT");

    int n;
    input >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    int minLength = INT_MAX;
    bool foundNegative = false;

    // Two-pointer technique
    for (int start = 0, end = 0; end < n; ++end) {
        // Nếu số hiện tại là âm
        if (a[end] < 0) {
            foundNegative = true;
            minLength = min(minLength, end - start + 1);
            // Di chuyển con trỏ "start" để kiểm tra các đoạn ngắn hơn
            while (start <= end && a[start] >= 0) {
                ++start;
                minLength = min(minLength, end - start + 1);
            }
        }
    }

    // In kết quả
    if (foundNegative) {
        output << minLength << endl;
    } else {
        output << 0 << endl;
    }

    input.close();
    output.close();

    return 0;
}
