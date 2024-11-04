#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // Đọc dữ liệu
    int n, k, p;
    ifstream infile("query.inp");
    infile >> n >> k >> p;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        infile >> a[i];
    }

    string queries;
    infile >> queries;
    infile.close();

    // Xử lý các truy vấn
    ofstream outfile("query.out");
    for (char query : queries) {
        if (query == '!') {
            // Truy vấn loại 1: Dịch chuyển phần tử cuối về đầu
            int last = a[n - 1];
            for (int i = n - 1; i > 0; --i) {
                a[i] = a[i - 1];
            }
            a[0] = last; // Đặt phần tử cuối vào đầu
        } else if (query == '?') {
            // Truy vấn loại 2: Tìm đoạn con có nhiều 1 nhất
            int max_count = 0;
            int current_count = 0;

            // Tính số lượng 1 trong đoạn đầu tiên
            for (int i = 0; i < k; ++i) {
                if (a[i] == 1) {
                    current_count++;
                }
            }
            max_count = current_count;

            // Di chuyển đoạn con
            for (int i = k; i < n; ++i) {
                // Cập nhật số lượng 1
                current_count += (a[i] == 1) ? 1 : 0;    // thêm phần tử mới
                current_count -= (a[i - k] == 1) ? 1 : 0; // bỏ phần tử cũ

                max_count = max(max_count, current_count);
            }

            // Ghi kết quả cho truy vấn loại 2
            outfile << max_count << endl;
        }
    }

    outfile.close();
    return 0;
}
