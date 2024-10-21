#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // Đọc dữ liệu từ file QUATANG.INP
    ifstream infile("QUATANG.INP");
    int N, K;
    infile >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        infile >> a[i];
    }
    infile.close();

    // Sử dụng unordered_map để đếm số lượng mỗi giá trị
    unordered_map<int, int> count_map;
    for (int num : a) {
        count_map[num]++;
    }

    int lucky_pairs = 0;

    // Tìm cặp thỏa mãn điều kiện |ai + aj| = K
    for (const auto& entry : count_map) {
        int ai = entry.first;
        int count_ai = entry.second;

        // Tìm giá trị cần thiết để thỏa mãn điều kiện
        int needed1 = K - ai;  // ai + aj = K  =>  aj = K - ai
        int needed2 = -K - ai; // ai + aj = -K => aj = -K - ai

        // Nếu needed1 tồn tại trong map, tăng số lượng cặp
        if (count_map.find(needed1) != count_map.end()) {
            if (needed1 == ai) {
                // Nếu ai == aj, thì chúng ta cần chọn 2 từ count_ai
                lucky_pairs += count_ai * (count_ai - 1) / 2;
            } else {
                lucky_pairs += count_ai * count_map[needed1];
            }
        }

        // Xử lý giá trị needed2 tương tự
        if (count_map.find(needed2) != count_map.end()) {
            if (needed2 == ai) {
                lucky_pairs += count_ai * (count_ai - 1) / 2;
            } else {
                lucky_pairs += count_ai * count_map[needed2];
            }
        }

        // Đánh dấu ai để tránh đếm lại cặp đã xử lý
        count_map.erase(ai);
    }

    // Ghi kết quả ra file QUATANG.OUT
    ofstream outfile("QUATANG.OUT");
    outfile << lucky_pairs << endl;
    outfile.close();

    return 0;
}
