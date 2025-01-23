#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("BAI3.INP");
    ofstream output("BAI3.OUT");

    long long N, M;
    input >> N >> M;

    vector<long long> coins(N + 1, 0); // Mảng lưu số đồng xu, index từ 1 đến N

    // Đọc các lượt phát đồng xu
    for (long long i = 0; i < M; ++i) {
        long long L, R;
        input >> L >> R;
        if (L <= R) {
            coins[L] += 1;
            if (R + 1 <= N) coins[R + 1] -= 1;
        } else {
            coins[L] += 1;
            if (N + 1 <= N) coins[N + 1] -= 1; // Không thực sự cần vì N+1 ngoài mảng
            coins[1] += 1;
            if (R + 1 <= N) coins[R + 1] -= 1;
        }
    }

    // Tính toán số đồng xu thực tế nhận được
    vector<long long> final_coins(N + 1, 0);
    long long maxCoins = 0, countMaxCoins = 0;

    for (long long i = 1; i <= N; ++i) {
        coins[i] += coins[i - 1]; // Tích lũy
        if (coins[i] > maxCoins) {
            maxCoins = coins[i];
            countMaxCoins = 1;
        } else if (coins[i] == maxCoins) {
            countMaxCoins++;
        }
    }

    // Ghi kết quả ra file
    output << maxCoins << " " << countMaxCoins << endl;

    input.close();
    output.close();

    return 0;
}
