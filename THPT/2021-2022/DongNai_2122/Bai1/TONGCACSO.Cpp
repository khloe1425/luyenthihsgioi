#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Mở file input và output
    ifstream infile("TONGCACSO.INP");
    ofstream outfile("TONGCACSO.OUT");

    string N; // Lưu số lớn dưới dạng chuỗi
    infile >> N;

    long long sum = 0; // Biến lưu tổng các chữ số

    // Tính tổng các chữ số
    for (char digit : N) {
        sum += (digit - '0'); // Chuyển ký tự thành số và cộng vào tổng
    }

    // Ghi kết quả ra file
    outfile << sum << endl;

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
