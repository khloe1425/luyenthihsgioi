#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coin {
    int index;  // Vị trí ban đầu
    int a;      // Giá trị theo Vinh
    int b;      // Giá trị theo Sơn
};

bool compareBySon(const Coin &c1, const Coin &c2) {
    // Sơn chọn theo giá trị b giảm dần, nếu bằng thì theo index tăng dần
    if (c1.b == c2.b) return c1.index < c2.index;
    return c1.b > c2.b;
}

bool compareByVinh(const Coin &c1, const Coin &c2) {
    // Vinh chọn theo giá trị a giảm dần, nếu bằng thì theo index tăng dần
    if (c1.a == c2.a) return c1.index < c2.index;
    return c1.a > c2.a;
}

int main() {
    ifstream input("DIVIDE.INP");
    ofstream output("DIVIDE.OUT");

    int N;
    input >> N;

    vector<Coin> coins(N);
    for (int i = 0; i < N; i++) {
        coins[i].index = i + 1;
        input >> coins[i].a;
    }
    for (int i = 0; i < N; i++) {
        input >> coins[i].b;
    }

    int totalSon = 0;
    vector<pair<int, int>> steps;

    bool turn = true; // true: Sơn, false: Vinh
    while (!coins.empty()) {
        if (turn) {
            // Sơn chọn
            sort(coins.begin(), coins.end(), compareBySon);
            totalSon += coins[0].b;
            steps.push_back({coins[0].index, -1});
            coins.erase(coins.begin());
        } else {
            // Vinh chọn
            sort(coins.begin(), coins.end(), compareByVinh);
            steps.back().second = coins[0].index;
            coins.erase(coins.begin());
        }
        turn = !turn; // Đổi lượt
    }

    // Ghi kết quả
    output << totalSon << endl;
    for (const auto &step : steps) {
        output << step.first << " " << step.second << endl;
    }

    input.close();
    output.close();
    return 0;
}
