#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("SHOES.INP");
    ofstream output("SHOES.OUT");

    int n, d;
    input >> n >> d;

    vector<int> shoes(n);
    for (int i = 0; i < n; i++) {
        input >> shoes[i];
    }

    // Sắp xếp độ sáng của giày
    sort(shoes.begin(), shoes.end());

    int count = 0; // Đếm số trận đấu
    int i = 0; // Con trỏ bắt đầu
    while (i < n - 1) {
        if (shoes[i + 1] - shoes[i] <= d) {
            count++;
            i += 2; // Bỏ qua 2 đôi giày đã chọn
        } else {
            i++; // Duyệt tiếp
        }
    }

    output << count << endl;

    input.close();
    output.close();

    return 0;
}
