#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// Hàm tính UCLN
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tìm phân số tối giản nhỏ nhất
void findSmallestFraction(int a, int b, int c, int d, int& g, int& h) {
    // Tính giá trị lớn nhất của hai phân số a/b và c/d
    long long maxNum = max((long long)a * d, (long long)c * b); // Tử số lớn nhất
    long long maxDen = (long long)b * d;                       // Mẫu số chung

    // Duyệt qua các giá trị h để tìm g
    for (h = 1; ; h++) {
        // Tính tử số nhỏ nhất g để g/h > maxNum/maxDen
        g = (maxNum * h + maxDen - 1) / maxDen; // Tính ceil(maxNum / maxDen) * h

        // Kiểm tra nếu g/h > max(a/b, c/d)
        if ((long long)g * maxDen > maxNum * h) {
            // Rút gọn phân số
            int factor = gcd(g, h);
            g /= factor;
            h /= factor;
            return;
        }
    }
}

int main() {
    ifstream input("FRAC.INP");
    ofstream output("FRAC.OUT");

    int a, b, c, d;
    input >> a >> b >> c >> d;

    int g, h;
    findSmallestFraction(a, b, c, d, g, h);

    output << g << endl;
    output << h << endl;

    input.close();
    output.close();

    return 0;
}
