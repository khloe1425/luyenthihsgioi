#include <iostream>
#include <fstream>

using namespace std;

// Hàm để tính UCLN của hai số a và b
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ifstream infile("UCLN.INP"); // Mở file để đọc
    ofstream outfile("UCLN.OUT"); // Mở file để ghi

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file!" << endl; // Kiểm tra lỗi mở file
        return 1;
    }

    int a, b, c;
    infile >> a >> b >> c; // Đọc ba số nguyên dương a, b, c

    int ucln = gcd(a, b); // Tính UCLN của a và b

    // Kiểm tra xem c có phải là UCLN hay không
    if (ucln == c) {
        outfile << 1 << endl; // Nếu c là UCLN, ghi 1
    } else {
        outfile << 0 << endl; // Ngược lại, ghi 0
    }

    infile.close(); // Đóng file đọc
    outfile.close(); // Đóng file ghi
    return 0;
}
