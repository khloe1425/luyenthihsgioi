#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> groups(N);
    
    // Đọc số lượng học sinh trong từng nhóm
    for (int i = 0; i < N; ++i) {
        cin >> groups[i];
    }

    // Đếm số nhóm có số học sinh từ 1 đến 4
    int count[5] = {0}; // count[0] không dùng, chỉ sử dụng từ count[1] đến count[4]
    
    for (int i = 0; i < N; ++i) {
        count[groups[i]]++;
    }

    // Tính số bàn cần thiết
    int tables = count[4]; // Mỗi nhóm có 4 học sinh cần 1 bàn

    // Nhóm 3 học sinh
    tables += count[3];
    count[1] = max(0, count[1] - count[3]); // Số nhóm 1 còn lại sau khi kết hợp với nhóm 3

    // Nhóm 2 học sinh
    tables += count[2] / 2; // Hai nhóm 2 ngồi chung một bàn
    count[2] %= 2; // Kiểm tra nếu còn dư nhóm 2

    if (count[2] > 0) {
        // Nếu còn 1 nhóm 2, cần một bàn và kiểm tra xem còn nhóm 1 không
        tables++;
        count[1] = max(0, count[1] - 2); // Giảm số nhóm 1 đi 2 nếu có
    }

    // Cuối cùng, nhóm 1 học sinh
    tables += (count[1] + 3) / 4; // Chia số nhóm 1 cho 4, làm tròn lên

    cout << tables << endl;

    return 0;
}
