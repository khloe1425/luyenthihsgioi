#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Đọc dữ liệu từ file DEMSO.INP
    ifstream input("DEMSO.INP");
    ofstream output("DEMSO.OUT");

    int n;
    input >> n; // Số lượng phần tử
    int count = 0; // Bộ đếm số lượng thỏa mãn điều kiện

    for (int i = 0; i < n; i++) {
        int x;
        input >> x;

        // Kiểm tra điều kiện: chia hết cho 3 nhưng không chia hết cho 9
        if (x % 3 == 0 && x % 9 != 0) {
            count++;
        }
    }

    // Ghi kết quả vào file DEMSO.OUT
    output << count << endl;

    input.close();
    output.close();

    return 0;
}
