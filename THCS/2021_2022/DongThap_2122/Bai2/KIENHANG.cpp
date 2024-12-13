#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("KIENHANG.INP");
    ofstream output("KIENHANG.OUT");

    int n, M, k;
    input >> n >> M >> k;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        input >> weights[i];
    }

    // Tính tổng tải trọng trước kiện hàng thứ k
    int totalWeight = 0;
    vector<int> removableItems; // Các kiện hàng có thể bỏ lại

    for (int i = 0; i < k; i++) {
        totalWeight += weights[i];
        if (i != k - 1) { // Không thêm kiện hàng thứ k vào danh sách có thể bỏ
            removableItems.push_back(weights[i]);
        }
    }

    // Nếu tải trọng vượt quá M, phải loại bỏ bớt kiện hàng
    int itemsToRemove = 0;
    sort(removableItems.begin(), removableItems.end(), greater<int>()); // Sắp xếp giảm dần
    while (totalWeight > M) {
        totalWeight -= removableItems.front(); // Bỏ kiện nặng nhất trước
        removableItems.erase(removableItems.begin());
        itemsToRemove++;
    }

    output << itemsToRemove << endl;

    input.close();
    output.close();

    return 0;
}
