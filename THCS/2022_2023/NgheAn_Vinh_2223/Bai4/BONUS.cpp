#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tính tổng phần thưởng của các dãy con liên tiếp
long long calculate_reward(const vector<int>& A, int n) {
    long long total_reward = 0;

    // Duyệt qua tất cả các dãy con liên tiếp
    for (int i = 0; i < n; ++i) {
        int min_element = A[i];
        int max_element = A[i];
        for (int j = i; j < n; ++j) {
            // Cập nhật phần tử nhỏ nhất và lớn nhất cho dãy con từ i đến j
            min_element = min(min_element, A[j]);
            max_element = max(max_element, A[j]);

            // Cộng trọng số của dãy con này vào tổng
            total_reward += (max_element - min_element);
        }
    }

    return total_reward;
}

int main() {
    // Mở file input và output
    ifstream infile("BONUS.INP");
    ofstream outfile("BONUS.OUT");

    // Đọc số phần tử của dãy A
    int n;
    infile >> n;

    // Đọc các phần tử của dãy A
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        infile >> A[i];
    }

    // Tính tổng phần thưởng
    long long result = calculate_reward(A, n);

    // Ghi kết quả ra file
    outfile << result << endl;

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
