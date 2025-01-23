#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ifstream input("DONCAY.INP");
    ofstream output("DONCAY.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    input >> n;

    vector<int> h(n);  // Chiều cao của các cây
    for (int i = 0; i < n; ++i) {
        input >> h[i];
    }

    vector<int> result;  // Lưu danh sách các cây bị đốn
    int count = 0;       // Số lượng cây bị đốn

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            // Cây đầu tiên luôn có thể đổ về trái
            result.push_back(-(i + 1));  // Âm: đổ về trái
            count++;
        } else if (i == n - 1) {
            // Cây cuối cùng luôn có thể đổ về phải
            result.push_back(i + 1);  // Dương: đổ về phải
            count++;
        } else {
            // Kiểm tra nếu cây i có thể đổ về trái
            if (i > 0 && h[i] < h[i - 1]) {
                result.push_back(-(i + 1));  // Âm: đổ về trái
                count++;
            } 
            // Kiểm tra nếu cây i có thể đổ về phải
            else if (i < n - 1 && h[i] < h[i + 1]) {
                result.push_back(i + 1);  // Dương: đổ về phải
                count++;
            }
        }
    }

    // Xuất kết quả
    output << count << endl;
    for (int x : result) {
        output << x << " ";
    }
    output << endl;

    input.close();
    output.close();

    return 0;
}
