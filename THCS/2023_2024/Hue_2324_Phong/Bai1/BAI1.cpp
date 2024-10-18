#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Hàm kiểm tra số chia hết hoàn toàn
bool chiaHetHoanToan(int num) {
    int original_num = num;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || original_num % digit != 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    ifstream infile("SOCHIAHET.INP");
    ofstream outfile("SOCHIAHET.OUT");

    int n;
    infile >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        infile >> arr[i];
    }

    vector<int> ketQua;
    for (int num : arr) {
        if (chiaHetHoanToan(num)) {
            ketQua.push_back(num);
        }
    }

    outfile << ketQua.size() << endl;
    for (int num : ketQua) {
        outfile << num << " ";
    }
    outfile << endl;

    infile.close();
    outfile.close();
    return 0;
}
