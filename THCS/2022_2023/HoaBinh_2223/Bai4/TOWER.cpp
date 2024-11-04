#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_towers(int n, vector<int>& blocks) {
    vector<int> towers;

    for (int block : blocks) {
        // Tìm vị trí đầu tiên trong towers mà giá trị lớn hơn block
        auto pos = upper_bound(towers.begin(), towers.end(), block);
        
        if (pos != towers.end()) {
            *pos = block;  // Thay thế khối hộp trên đỉnh của tháp tại vị trí tìm thấy
        } else {
            towers.push_back(block);  // Tạo tháp mới
        }
    }

    return towers.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> blocks(n);

    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    cout << min_towers(n, blocks) << endl;

    return 0;
}
