#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    // Mở file input và output
    ifstream input("DCOUNT.INP");
    ofstream output("DCOUNT.OUT");

    int N;
    input >> N; // Đọc số lượng phần tử trong dãy

    unordered_map<int, int> freq; // Map để lưu tần suất xuất hiện của mỗi số

    // Đọc dãy số và đếm tần suất
    for (int i = 0; i < N; ++i) {
        int x;
        input >> x;
        freq[x]++;
    }

    int odd_count = 0; // Đếm số lượng số có tần suất xuất hiện là lẻ

    // Kiểm tra tần suất xuất hiện
    for (auto &entry : freq) {
        if (entry.second % 2 != 0) { // Nếu tần suất là lẻ
            odd_count++;
        }
    }

    // Ghi kết quả ra file output
    output << odd_count << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
