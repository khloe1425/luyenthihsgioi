#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("TrungThuong.INP");
    ofstream output("TrungThuong.OUT");

    int n;
    input >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        input >> c[i];
    }

    int count = 0;

    // Xét tất cả các cặp (i, j) với 1 ≤ i < j ≤ n
    for (int i = 0; i < n - 1; i++) {
        int x = c[i];
        int y = c[i];
        for (int j = i + 1; j < n; j++) {
            x = min(x, c[j]); // Giá trị nhỏ nhất trong đoạn [i, j]
            y = max(y, c[j]); // Giá trị lớn nhất trong đoạn [i, j]
            // Kiểm tra điều kiện thỏa mãn
            if ((c[i] == x && c[j] == y) || (c[i] == y && c[j] == x)) {
                count++;
            }
        }
    }

    output << count << endl;

    input.close();
    output.close();

    return 0;
}
