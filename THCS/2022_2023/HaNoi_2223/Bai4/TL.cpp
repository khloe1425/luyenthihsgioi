#include <bits/stdc++.h>
using namespace std;

struct Painting {
    long long size; // Kích thước
    long long value; // Giá trị
};

long long maxProfit(int n, vector<Painting>& paintings) {
    // Sắp xếp các bức tranh theo kích thước
    sort(paintings.begin(), paintings.end(), [](const Painting &a, const Painting &b) {
        return a.size < b.size;
    });

    long long max_H = LLONG_MIN; // Khởi tạo H lớn nhất
    long long current_sum = 0; // Tổng giá trị hiện tại
    int left = 0; // Chỉ số bên trái

    for (int right = 0; right < n; ++right) {
        current_sum += paintings[right].value; // Cộng giá trị của bức tranh bên phải

        // Kiểm tra tất cả các khoảng từ left đến right
        while (left <= right) {
            long long Amin = paintings[left].size; // Kích thước nhỏ nhất
            long long Amax = paintings[right].size; // Kích thước lớn nhất
            long long H = current_sum - (Amax - Amin); // Tính lợi nhuận
            
            max_H = max(max_H, H); // Cập nhật H lớn nhất
            
            // Nếu kích thước hiện tại đã đủ điều kiện, thì có thể tăng left
            if (left < right) {
                current_sum -= paintings[left].value; // Bớt giá trị bức tranh bên trái
                left++; // Di chuyển bên trái
            } else {
                break; // Nếu left == right thì không thể tiếp tục
            }
        }
    }

    return max_H;
}

int main() {
    // Đọc dữ liệu từ tệp
    ifstream inp("TL.INP");
    int n;
    inp >> n;
    vector<Painting> paintings(n);
    
    for (int i = 0; i < n; ++i) {
        inp >> paintings[i].size >> paintings[i].value;
    }
    inp.close();

    long long result = maxProfit(n, paintings);

    // Ghi kết quả ra tệp
    ofstream out("TL.OUT");
    out << result << endl;
    out.close();

    return 0;
}
