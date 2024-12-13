#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Mở file input và output
    ifstream inputFile("ANALYSE4.INP");
    ofstream outputFile("ANALYSE4.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n; // Đọc giá trị n từ file input

    int count = 0;

    // Duyệt qua tất cả các bộ số (x, y, z, t) thỏa mãn
    for (int x = 1; x <= n; x++) {
        for (int y = x; y <= n; y++) {
            for (int z = y; z <= n; z++) {
                int t = n - (x + y + z);
                if (t >= z) {
                    count++;
                }
            }
        }
    }

    // Ghi kết quả ra file output
    outputFile << count << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
