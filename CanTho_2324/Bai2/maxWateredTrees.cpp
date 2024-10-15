#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void max_watered_trees(const string &input_file, const string &output_file) {
    ifstream infile(input_file);
    ofstream outfile(output_file);

    int n;
    long long k;
    infile >> n >> k;

    vector<long long> water_needed(n);
    for (int i = 0; i < n; ++i) {
        infile >> water_needed[i];
    }

    int max_count = 0;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += water_needed[right];  // Thêm nước cần tưới cho cây hiện tại

        // Nếu tổng nước cần tưới vượt quá k, di chuyển bên trái
        while (current_sum > k) {
            current_sum -= water_needed[left];
            left++;
        }

        // Cập nhật số lượng cây liên tục tưới được
        max_count = max(max_count, right - left + 1);
    }

    // Ghi kết quả vào tệp
    outfile << max_count << endl;

    infile.close();
    outfile.close();
}

int main() {
    max_watered_trees("MUAHE.INP", "MUAHE.OUT");
    return 0;
}
