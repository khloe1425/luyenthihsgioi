#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Mở file input và output
    ifstream input("QUANXE.INP");
    ofstream output("QUANXE.OUT");

    int n; // Kích thước bàn cờ
    input >> n;

    for (int i = 1; i <= n; i++) {
        int x, y; // Vị trí ban đầu của quân xe
        input >> x >> y;

        // Tính toán vị trí mới
        int newRow = i;        // Hàng mới giữ nguyên thứ tự đầu vào
        int newCol = n - x + 1; // Cột mới tính theo công thức n - x + 1

        // Ghi vị trí mới vào file output
        output << newRow << " " << newCol << endl;
    }

    input.close();
    output.close();

    return 0;
}
