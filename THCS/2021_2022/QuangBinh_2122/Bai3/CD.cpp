#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("CD.INP");   // Đọc dữ liệu từ file
    ofstream output("CD.OUT"); // Ghi dữ liệu ra file

    int N, K;
    input >> N >> K;

    // Tìm nghiệm thỏa mãn
    bool found = false;
    for (int x = 0; x <= N; ++x) { // Duyệt số gà từ 0 đến N
        int y = N - x;             // Tính số chó
        if (2 * x + 4 * y == K) {  // Kiểm tra tổng số chân
            output << x << " " << y << endl;
            found = true;
            break;
        }
    }

    // Nếu không tìm thấy nghiệm nào
    if (!found) {
        output << -1 << endl;
    }

    input.close();
    output.close();
    return 0;
}
