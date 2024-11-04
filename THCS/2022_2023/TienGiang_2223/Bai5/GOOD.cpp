#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream infile("GOOD.INP");
    ofstream outfile("GOOD.OUT");

    int n, m;
    infile >> n >> m;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        infile >> weights[i];
    }

    // Sắp xếp trọng lượng kiện hàng theo thứ tự giảm dần
    sort(weights.begin(), weights.end(), greater<int>());

    vector<int> selected_goods;
    int current_load = 0;

    // Chọn các kiện hàng thỏa mãn điều kiện
    for (int weight : weights) {
        if (current_load + weight <= m) {
            selected_goods.push_back(weight);
            current_load += weight;
        }
    }

    // Ghi kết quả vào file
    for (size_t i = 0; i < selected_goods.size(); ++i) {
        if (i > 0) {
            outfile << " "; // Thêm khoảng trắng giữa các trọng lượng
        }
        outfile << selected_goods[i];
    }
    outfile << endl;

    infile.close();
    outfile.close();

    return 0;
}
