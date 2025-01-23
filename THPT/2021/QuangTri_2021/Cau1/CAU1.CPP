#include <bits/stdc++.h>
using namespace std;

// Hàm tính tổng chữ số đến khi còn 1 chữ số
int calcLuckyNumber(string M) {
    int sum = 0;
    for (char c : M) { 
        sum += c - '0'; // Chuyển ký tự số thành số nguyên và cộng tổng
    }
    // Lặp lại quá trình tính tổng chữ số cho đến khi còn 1 chữ số
    while (sum >= 10) {
        int temp = 0;
        while (sum > 0) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("CAU1.INP");
    ofstream fout("CAU1.OUT");

    int T; // Số lượng test
    fin >> T;

    while (T--) {
        string M; // Đọc số M dưới dạng chuỗi (hỗ trợ số lớn)
        fin >> M;
        fout << calcLuckyNumber(M) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
