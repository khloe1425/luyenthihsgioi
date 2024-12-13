#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream input("DRB.INP");
    ofstream output("DRB.OUT");

    long long S1, V1, S2, V2;
    input >> S1 >> V1 >> S2 >> V2;

    if (V1 == V2) {
        // Cùng vận tốc
        if (S1 == S2) {
            output << 0 << endl; // Gặp nhau tại thời điểm t = 0
        } else {
            output << -1 << endl; // Không bao giờ gặp nhau
        }
    } else {
        // Khác vận tốc
        double t = static_cast<double>(S2 - S1) / (V1 - V2);
        if (t > 0) {
            output << static_cast<long long>(floor(t)) << endl; // Lấy phần nguyên
        } else {
            output << -1 << endl; // Không gặp nhau
        }
    }

    input.close();
    output.close();

    return 0;
}
