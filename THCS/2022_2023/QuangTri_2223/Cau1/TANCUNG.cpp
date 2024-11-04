#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm tính chữ số tận cùng của A^N
int lastDigit(int A, int N) {
    // Bảng chu kỳ chữ số tận cùng
    vector<vector<int>> cycles = {
        {0},        // 0^N
        {1},        // 1^N
        {2, 4, 8, 6}, // 2^N
        {3, 9, 7, 1}, // 3^N
        {4, 6},    // 4^N
        {5},        // 5^N
        {6},        // 6^N
        {7, 9, 3, 1}, // 7^N
        {8, 4, 2, 6}, // 8^N
        {9, 1}     // 9^N
    };
    
    if (A == 0) return 0; // Nếu A = 0 thì chữ số tận cùng là 0
    A = A % 10; // Lấy chữ số tận cùng của A

    // Tính chỉ số trong chu kỳ
    if (N == 0) return 1; // A^0 = 1
    int cycle_length = cycles[A].size();
    int index = (N - 1) % cycle_length; // -1 để chuyển từ 1-indexed sang 0-indexed
    return cycles[A][index];
}

int main() {
    // Mở file input và output
    ifstream infile("TANCUNG.INP");
    ofstream outfile("TANCUNG.OUT");

    int A, N;
    // Đọc A và N từ file
    infile >> A >> N;

    // Tính chữ số tận cùng của A^N
    int last_digit = lastDigit(A, N);

    // Ghi kết quả vào file
    outfile << last_digit << endl;

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
