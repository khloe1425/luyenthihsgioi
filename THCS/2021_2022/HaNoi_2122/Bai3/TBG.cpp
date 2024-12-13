#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("TBG.INP");
    ofstream output("TBG.OUT");

    long long X, Y, Z;
    input >> X >> Y >> Z;

    long long T0 = 0; // Thời gian chờ ban đầu
    while (true) {
        bool valid = true;

        // Kiểm tra điều kiện với tất cả t trong [1, Z]
        for (long long t = 1; t <= Z; t++) {
            long long download = (t + T0) * Y; // Dung lượng tải được
            long long required = t * X;       // Dung lượng cần phát
            if (download < required) {
                valid = false; // Điều kiện không thỏa mãn
                break;
            }
        }

        if (valid) {
            // Nếu tất cả điều kiện thỏa mãn, ghi T0 và thoát
            output << T0 << endl;
            break;
        }

        T0++; // Tăng thời gian chờ
    }

    input.close();
    output.close();
    return 0;
}
