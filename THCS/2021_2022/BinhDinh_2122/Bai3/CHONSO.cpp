#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX_N = 40;

int main() {
    // Đọc dữ liệu từ file CHONSO.INP
    ifstream input("CHONSO.INP");
    if (!input) {
        cerr << "Không thể mở file CHONSO.INP. Kiểm tra file!" << endl;
        return 1;
    }

    ofstream output("CHONSO.OUT");
    if (!output) {
        cerr << "Không thể mở file CHONSO.OUT. Kiểm tra quyền ghi!" << endl;
        return 1;
    }

    int n, M;
    input >> n;
    if (n < 5 || n > 40) {
        cerr << "Số phần tử n không hợp lệ! n phải nằm trong khoảng [5, 40]." << endl;
        return 1;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }
    input >> M;

    // In kiểm tra dữ liệu đầu vào
    cout << "Đã đọc dữ liệu: n = " << n << ", M = " << M << endl;
    cout << "Mảng a: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Duyệt tất cả các tổ hợp (sử dụng bitmask)
    int limit = (1 << n); // 2^n tổ hợp
    vector<int> result;
    bool found = false;

    for (int mask = 0; mask < limit; mask++) {
        int sum = 0;
        vector<int> current(n, 0);

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // Nếu bit thứ i được chọn
                sum += a[i];
                current[i] = 1; // Đánh dấu bit i
            }
        }

        if (sum == M) {
            result = current;
            found = true;
            break;
        }
    }

    if (found) {
        // Ghi kết quả ra file CHONSO.OUT
        for (int i = 0; i < result.size(); i++) {
            output << result[i];
        }
        output << endl;
        cout << "Kết quả đã được ghi vào file CHONSO.OUT." << endl;
    } else {
        cerr << "Không tìm thấy tổ hợp nào thỏa mãn tổng M = " << M << "." << endl;
    }

    input.close();
    output.close();
    return 0;
}
