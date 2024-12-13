#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("CAU4.INP");
    ofstream output("CAU4.OUT");

    int N;
    input >> N;

    vector<int> factors;

    // Phân tích N thành tích của các số từ 2 đến 9
    for (int i = 9; i >= 2; --i) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    // Nếu không thể phân tích hoàn toàn (N > 1), nghĩa là không hợp lệ
    if (N > 1) {
        output << -1 << endl;
    } else {
        // Sắp xếp các thừa số tăng dần
        sort(factors.begin(), factors.end());

        // Tính tích để tạo ra số nhỏ nhất
        int result = 1;
        for (int factor : factors) {
            result *= factor;
        }

        // Ghi kết quả vào file
        output << result << endl;
    }

    input.close();
    output.close();

    return 0;
}
