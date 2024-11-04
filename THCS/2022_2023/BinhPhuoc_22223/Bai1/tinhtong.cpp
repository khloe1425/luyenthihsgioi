#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Mở file để đọc dữ liệu
    ifstream infile("tinhtong.inp");
    ofstream outfile("tinhtong.out");

    long long n;
    infile >> n; // Đọc số nguyên dương chẵn từ file

    // Tính tổng các số chẵn nhỏ hơn n
    long long total = 0;
    if (n > 2) {
        long long k = (n / 2) - 1;
        total = k * (n / 2);
    }

    // Ghi kết quả vào file tinhtong.out
    outfile << total << endl;

    // Đóng file
    infile.close();
    outfile.close();

    return 0;
}
