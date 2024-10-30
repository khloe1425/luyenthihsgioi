#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool is_prime(int n) {
    if (n <= 1) return false; // Số nhỏ hơn hoặc bằng 1 không phải số nguyên tố
    if (n <= 3) return true;  // 2 và 3 là số nguyên tố
    if (n % 2 == 0 || n % 3 == 0) return false; // Loại trừ số chẵn và bội số của 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm đếm số chữ số chẵn và lẻ
void count_even_odd_digits(int n, int &even_count, int &odd_count) {
    even_count = 0;
    odd_count = 0;

    while (n > 0) {
        int digit = n % 10; // Lấy chữ số cuối cùng
        if (digit % 2 == 0) {
            even_count++; // Chữ số chẵn
        } else {
            odd_count++; // Chữ số lẻ
        }
        n /= 10; // Bỏ chữ số cuối
    }
}

int main() {
    ifstream infile("SODB.INP");
    ofstream outfile("SODB.OUT");

    int N;
    infile >> N; // Đọc số lượng phần tử

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        infile >> A[i]; // Đọc từng số nguyên
    }

    int special_count = 0;

    for (int i = 0; i < N; ++i) {
        int even_count = 0;
        int odd_count = 0;

        if (is_prime(A[i])) { // Kiểm tra nếu số nguyên là số nguyên tố
            count_even_odd_digits(A[i], even_count, odd_count); // Đếm chữ số chẵn và lẻ

            // Kiểm tra điều kiện số đặc biệt
            if (even_count != odd_count) {
                special_count++;
            }
        }
    }

    outfile << special_count << endl; // Ghi kết quả

    infile.close();
    outfile.close();

    return 0;
}
