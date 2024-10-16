#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("CAU01.INP");
    ofstream output("CAU01.OUT");

    int N;
    input >> N;

    vector<int> sum_divisors(N + 1, 1);  // Khởi tạo 1 vì tất cả số nguyên dương đều có ước là 1
    sum_divisors[1] = 0; // 1 không có ước nào ngoại trừ chính nó

    // Tính tổng các ước cho tất cả các số từ 1 đến N
    for (int i = 2; i <= N; ++i) {
        for (int j = i * 2; j <= N; j += i) {
            sum_divisors[j] += i;
        }
    }

    int count = 0;

    // Đếm các cặp số anh em
    for (int A = 1; A <= N; ++A) {
        int B = sum_divisors[A];
        // Kiểm tra nếu B thỏa mãn các điều kiện để là cặp số anh em của A
        if (B > A && B <= N && sum_divisors[B] == A) {
            ++count;
        }
    }

    output << count << endl;

    input.close();
    output.close();

    return 0;
}
