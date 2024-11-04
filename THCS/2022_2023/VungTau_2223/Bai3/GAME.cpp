#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    // Đọc dữ liệu từ file GAME.INP
    ifstream infile("GAME.INP");
    int N, K;
    infile >> N >> K;

    vector<int> energies(N);
    for (int i = 0; i < N; i++) {
        infile >> energies[i];
    }
    infile.close();

    // Khởi tạo mảng chi phí tối thiểu
    vector<long long> min_cost(N, numeric_limits<long long>::max());
    min_cost[0] = 0;  // Chi phí để đứng ở ô 1 là 0

    // Tính toán chi phí tối thiểu
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i + j < N) {
                min_cost[i + j] = min(min_cost[i + j], min_cost[i] + abs(energies[i + j] - energies[i]));
            }
        }
    }

    // Ghi kết quả vào file GAME.OUT
    ofstream outfile("GAME.OUT");
    outfile << min_cost[N - 1] << endl;  // Chi phí tối thiểu để đến ô N
    outfile.close();

    return 0;
}
