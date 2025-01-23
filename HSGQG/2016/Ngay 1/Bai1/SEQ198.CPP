#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

// Hàm kiểm tra dãy có phải là SEQ198 hay không
bool isSEQ198(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = abs(arr[i] - arr[j]);
            if (diff == 1 || diff == 8 || diff == 9) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream input("SEQ198.INP");
    ofstream output("SEQ198.OUT");

    // Kiểm tra mở file
    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int m;
    input >> m;

    vector<int> arr(m);
    for (int i = 0; i < m; ++i) {
        input >> arr[i];
    }

    // Kiểm tra nếu dãy ban đầu đã là SEQ198
    if (isSEQ198(arr)) {
        output << "0" << endl;
        input.close();
        output.close();
        return 0;
    }

    // Thử loại bỏ từng phần tử
    for (int i = 0; i < m; ++i) {
        vector<int> temp = arr;
        temp.erase(temp.begin() + i); // Loại bỏ phần tử thứ i

        if (isSEQ198(temp)) {
            output << i + 1 << endl; // Ghi chỉ số 1-based của phần tử bị loại bỏ
            input.close();
            output.close();
            return 0;
        }
    }

    // Nếu không tìm được phần tử thỏa mãn
    output << "0" << endl;

    input.close();
    output.close();
    return 0;
}
