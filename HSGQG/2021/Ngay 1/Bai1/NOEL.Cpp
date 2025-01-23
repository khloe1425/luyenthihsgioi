#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ file input
    ifstream fin("NOEL.INP");
    ofstream fout("NOEL.OUT");

    int n, d;
    fin >> n >> d;

    vector<int> gifts(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        fin >> gifts[i];
    }

    // Sắp xếp mảng quà tăng dần
    sort(gifts.begin(), gifts.end());
    cout << "Mảng quà sau khi sắp xếp: ";
    for (int x : gifts) cout << x << " ";
    cout << endl;

    int i = 0, j = 2 * n - 1; // i: chỉ số đầu, j: chỉ số cuối
    int max_kids = 0;

    // Duyệt qua các cặp quà
    while (i < j) {
        cout << "Xét cặp: (" << gifts[i] << ", " << gifts[j] << ")" << endl;
        if (gifts[j] - gifts[i] <= d) {
            // Nếu chênh lệch <= d, tặng quà cho 1 bạn nhỏ
            max_kids++;
            cout << "Tặng quà cho 1 bạn! Số bạn hiện tại: " << max_kids << endl;
            i++;
            j--;
        } else {
            // Nếu không, bỏ món quà lớn hơn (giảm j)
            cout << "Chênh lệch lớn hơn " << d << ". Bỏ quà lớn hơn.\n";
            j--;
        }
    }

    // Ghi kết quả ra file output
    fout << max_kids << endl;
    cout << "Số lượng bạn nhỏ tối đa: " << max_kids << endl;

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}
