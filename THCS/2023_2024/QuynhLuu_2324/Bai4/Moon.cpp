#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("Moon.INP");
    ofstream outfile("Moon.OUT");

    // Đọc số lượng học sinh
    int n;
    infile >> n;

    vector<int> cakes(n);
    for (int i = 0; i < n; i++) {
        infile >> cakes[i];
    }

    // Mảng để lưu số bánh tối đa mà mỗi bạn nhận được
    vector<int> result(n, 1); // Bắt đầu với mỗi bạn có 1 bánh

    // Phát bánh từ trái sang phải
    for (int i = 1; i < n; i++) {
        if (cakes[i] > cakes[i - 1]) {
            result[i] = result[i - 1] + 1; // Nếu bạn bên trái có ít hơn
        }
    }

    // Phát bánh từ phải sang trái
    for (int i = n - 2; i >= 0; i--) {
        if (cakes[i] > cakes[i + 1]) {
            result[i] = max(result[i], result[i + 1] + 1); // Đảm bảo max
        }
    }

    // Kết quả là số bánh mà An nhận được (tại vị trí đầu tiên)
    int an_cakes = result[0];

    outfile << an_cakes << endl;

    infile.close();
    outfile.close();

    return 0;
}
