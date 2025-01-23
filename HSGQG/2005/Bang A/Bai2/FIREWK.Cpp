#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("FIREWK.INP");
    ofstream fout("FIREWK.OUT");

    int n, m, k, C;
    fin >> n >> m >> k >> C;

    vector<int> codes(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        fin >> codes[i];
    }

    vector<int> matching_indices;

    for (int i = 0; i < 2 * n; ++i) {
        if (codes[i] == C) {
            matching_indices.push_back(i + 1); // Thêm vị trí (tính từ 1)
        }
    }

    // Sắp xếp theo thứ tự từ điển (danh sách các chỉ số đã tự động có thứ tự)
    fout << matching_indices.size() << endl; // Số lượng mã hoa thỏa mãn
    for (int x : matching_indices) {
        fout << x << " ";
    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}
