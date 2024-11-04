#include <iostream>
#include <fstream>
#include <numeric>
using namespace std;

// Hàm tính UCLN (GCD)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Hàm tính BCNN (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Hàm tính tổng các chữ số từ ngày, tháng, năm
int sum_of_digits(int day, int month, int year) {
    int total = 0;
    while (day > 0) {
        total += day % 10;
        day /= 10;
    }
    while (month > 0) {
        total += month % 10;
        month /= 10;
    }
    while (year > 0) {
        total += year % 10;
        year /= 10;
    }
    return total;
}

int main() {
    // Đọc dữ liệu từ file MATMA.INP
    ifstream infile("MATMA.INP");
    int mom_day, mom_month, mom_year;
    int dad_day, dad_month, dad_year;

    infile >> mom_day >> mom_month >> mom_year;
    infile >> dad_day >> dad_month >> dad_year;

    // Tính tổng các chữ số của ngày sinh mẹ và ba
    int sum_mom = sum_of_digits(mom_day, mom_month, mom_year);
    int sum_dad = sum_of_digits(dad_day, dad_month, dad_year);

    // Tính BCNN của tổng chữ số
    int password = lcm(sum_mom, sum_dad);

    // Ghi kết quả ra file MATMA.OUT
    ofstream outfile("MATMA.OUT");
    outfile << "Mat ma khoa xe la: " << password << endl;

    return 0;
}
