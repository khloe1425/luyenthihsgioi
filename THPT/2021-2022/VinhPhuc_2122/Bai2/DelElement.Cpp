#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("DelElement.inp");
    ofstream output("DelElement.out");

    int N, k;
    input >> N >> k;

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        input >> a[i];
    }

    // Mảng đánh dấu các phần tử bị xóa
    vector<bool> is_removed(N + 1, false);

    // Xóa các bội số của từng phần tử trong mảng a
    for (int i = 0; i < k; ++i) {
        for (int j = a[i]; j <= N; j += a[i]) {
            is_removed[j] = true;
        }
    }

    // Đếm số phần tử còn lại
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (!is_removed[i]) {
            ++count;
        }
    }

    // Ghi kết quả ra file
    output << count << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
