#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("CAU3.INP");
    ofstream output("CAU3.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở tệp dữ liệu. Vui lòng kiểm tra!" << endl;
        return 1;
    }

    int K, M;
    input >> K >> M; // Đọc số lượng người tham gia và số chia M

    vector<int> participants(K); // Danh sách số của K người tham gia
    for (int i = 0; i < K; ++i) {
        input >> participants[i];
    }

    int N; // Số lượng người bốc thăm
    input >> N;

    vector<int> bocs(N); // Danh sách số của N người bốc thăm
    for (int i = 0; i < N; ++i) {
        input >> bocs[i];
    }

    // Kiểm tra từng số trong danh sách bốc thăm
    for (int i = 0; i < N; ++i) {
        if (bocs[i] % M == 0) { // Nếu số chia hết cho M
            output << 1 << endl;
        } else { // Nếu không chia hết
            output << 0 << endl;
        }
    }

    input.close();
    output.close();
    return 0;
}
