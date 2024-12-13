#include <iostream>
#include <fstream>
using namespace std;

const int MOD = 1000000007;

// Hàm tính tổng các số trong dãy từ A đến B
int calculateSum(int A, int B) {
    int total = 0;
    int current = 1; // Giá trị bắt đầu của dãy
    int count = 1;   // Số lần lặp hiện tại
    int index = 1;   // Chỉ số hiện tại trong dãy

    while (index <= B) {
        for (int i = 0; i < count; i++) {
            if (index >= A && index <= B) {
                total = (total + current) % MOD;
            }
            index++;
            if (index > B) break;
        }
        current++;
        count++;
    }
    return total;
}

int main() {
    ifstream input("BE.INP");
    ofstream output("BE.OUT");

    int A, B;
    input >> A >> B;

    int result = calculateSum(A, B);
    output << result << endl;

    input.close();
    output.close();
    return 0;
}
