#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
using namespace std;

int find_minimum_steps(int N, const vector<int>& a) {
    int current_balance = 0; // Số tiền hiện tại
    int total_steps = 0; // Số bước đã đi
    int total_sum = accumulate(a.begin(), a.end(), 0); // Tổng số tiền trong danh sách

    // Nếu tổng tiền >= 0, Bo có thể trả hết nợ
    if (total_sum >= 0) {
        // Duyệt qua danh sách để tìm số bước tối thiểu
        for (int i = 0; i < 2 * N; i++) { // Duyệt tối đa 2 vòng
            current_balance += a[i % N];
            total_steps++;

            // Nếu trả hết nợ, dừng lại
            if (current_balance >= 0) {
                return total_steps;
            }
        }
    }

    // Nếu không thể trả hết nợ, phải đi hết toàn bộ danh sách
    return N;
}

int main() {
    ifstream infile("TinhToan.inp");
    ofstream outfile("TinhToan.out");

    int N;
    infile >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        infile >> a[i];
    }

    int result = find_minimum_steps(N, a);
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
