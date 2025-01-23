#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ifstream inputFile("GIFTS.INP");
    ofstream outputFile("GIFTS.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int m; // Số lượng gói kẹo chứa quà
    inputFile >> m;

    vector<int> b(m); // Hiệu của các gói kẹo chứa quà
    for (int i = 0; i < m; ++i) {
        inputFile >> b[i];
    }

    int n; // Số khách hàng
    inputFile >> n;

    vector<int> a(n); // Số gói kẹo mỗi khách hàng muốn mua
    for (int i = 0; i < n; ++i) {
        inputFile >> a[i];
    }

    unordered_set<int> usedGifts; // Bộ chứa các gói kẹo chứa quà đã được bán

    for (int i = 0; i < n; ++i) {
        int wanted = a[i];
        for (int j = 0; j < m; ++j) {
            // Nếu hiệu b[j] là ước của wanted, gói b[j] được sử dụng
            if (wanted % b[j] == 0) {
                usedGifts.insert(b[j]);
            }
        }
    }

    // Ghi ra số lượng các gói kẹo chứa quà đã được bán
    outputFile << usedGifts.size() << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
