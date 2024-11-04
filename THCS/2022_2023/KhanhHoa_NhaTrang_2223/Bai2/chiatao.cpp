#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Thư viện cần thiết cho hàm find

using namespace std;

// Hàm tìm ước số của số nguyên
vector<int> getDivisors(int num) {
    vector<int> divisors;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            divisors.push_back(i);
            if (i != num / i) {
                divisors.push_back(num / i);
            }
        }
    }
    return divisors;
}

int main() {
    ifstream input("chiatao.inp");
    ofstream output("chiatao.out");

    int r, g;
    input >> r >> g;

    // Tìm ước số của r và g
    vector<int> divisorsR = getDivisors(r);
    vector<int> divisorsG = getDivisors(g);

    // Kiểm tra ước số chung và ghi kết quả
    for (int n : divisorsR) {
        if (find(divisorsG.begin(), divisorsG.end(), n) != divisorsG.end()) {
            // Tính số táo đỏ và táo xanh
            int x = r / n;
            int y = g / n;
            output << n << " " << x << " " << y << endl;
        }
    }

    input.close();
    output.close();
    return 0;
}
