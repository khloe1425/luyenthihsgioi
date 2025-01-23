#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("Chohang.inp");
    ofstream outfile("Chohang.out");

    int N, A, B;
    infile >> N >> A >> B;

    int max_weight = 0;

    // Duyệt qua tất cả các giá trị x (số hộp loại A)
    for (int x = 0; x <= N / A; x++) {
        // Tính số hộp loại B tối đa
        int remaining = N - x * A;
        int y = remaining / B;

        // Tính tổng trọng lượng
        int weight = x * A + y * B;

        // Cập nhật trọng lượng tối đa
        if (weight > max_weight) {
            max_weight = weight;
        }
    }

    // Ghi kết quả
    outfile << max_weight << endl;

    infile.close();
    outfile.close();

    return 0;
}
