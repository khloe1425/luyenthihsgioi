#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

// Hàm chuyển một số thành cấu trúc đẳng cấu dựa trên số lần xuất hiện của các chữ số
string encode(int num) {
    int digit_count[10] = {0}; // Đếm số lần xuất hiện của mỗi chữ số (0-9)
    string s = to_string(num);

    for (char c : s) {
        digit_count[c - '0']++;
    }

    string encoded = "";
    for (int i = 0; i < 10; ++i) {
        if (digit_count[i] > 0) {
            encoded += to_string(i) + ":" + to_string(digit_count[i]) + ";";
        }
    }

    return encoded;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("DANGCAU.INP");
    ofstream output("DANGCAU.OUT");

    int N;
    input >> N;

    unordered_map<string, int> structure_count; // Đếm số lượng mỗi cấu trúc
    long long total = 0;

    // Duyệt qua tất cả các số từ 1 đến N
    for (int i = 1; i <= N; ++i) {
        string structure = encode(i);
        structure_count[structure]++;
    }

    // Tính tổng F(1) + F(2) + ... + F(N)
    for (auto &entry : structure_count) {
        int count = entry.second;
        total += 1LL * count * count; // Tổng các số đẳng cấu
    }

    // Ghi kết quả ra file
    output << total << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
