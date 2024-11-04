#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Khai báo các mệnh giá
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100};
    int N;

    // Nhập số tiền N từ bàn phím
    cout << "Nhập số N: ";
    cin >> N;

    // Khởi tạo số lượng tờ tiền cho từng mệnh giá
    vector<int> counts(7, 0);

    // Tính số lượng tờ tiền cho từng mệnh giá
    for (int i = 0; i < denominations.size(); ++i) {
        // Đối với mệnh giá đầu tiên, nhận toàn bộ số tiền có thể
        counts[i] = N / denominations[i];
        N -= counts[i] * denominations[i];
    }

    // Bắt đầu từ mệnh giá lớn nhất để đảm bảo số tờ tiền không vượt quá
    for (int i = denominations.size() - 1; i > 0; --i) {
        if (counts[i] > counts[i - 1]) {
            counts[i - 1] = counts[i];
        }
    }

    // Cập nhật lại N để đảm bảo rằng tổng số tờ tiền được sử dụng là tối thiểu
    N = 0;
    for (int i = 0; i < denominations.size(); ++i) {
        N += counts[i] * denominations[i];
    }

    // Ghi kết quả vào tệp tien.out
    ofstream outputFile("tien.out");
    for (int i = 0; i < denominations.size(); ++i) {
        outputFile << denominations[i] << " " << counts[i] << endl;
    }
    outputFile.close();

    return 0;
}
