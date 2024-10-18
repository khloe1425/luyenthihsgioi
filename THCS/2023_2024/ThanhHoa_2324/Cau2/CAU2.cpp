#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Đọc dữ liệu từ tệp CAU2.INP
    ifstream inputFile("CAU2.INP");
    long long n;
    inputFile >> n;
    inputFile.close();

    // Biến đếm số cách mua gà và chó
    long long count = 0;

    // Duyệt giá tiền gà từ 1 đến n//2
    for (long long x = 1; x <= n / 2; x++) {
        long long max_y = n - x; // Giá trị lớn nhất có thể của chó
        if (x < max_y) {
            count += (max_y - x);
        }
    }

    // Ghi kết quả ra tệp CAU2.OUT
    ofstream outputFile("CAU2.OUT");
    outputFile << count << endl;
    outputFile.close();

    return 0;
}
