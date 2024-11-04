#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("CHUSO.INP");
    ofstream output("CHUSO.OUT");

    string a0;
    int n, m;

    input >> a0; // Đọc a0
    input >> n >> m; // Đọc n và m

    // Biến để lưu độ dài của các số a_i
    long long length = a0.length(); // Độ dài của a0
    long long current_length = length; // Độ dài hiện tại

    // Tính độ dài của a_n
    for (int i = 0; i < n; ++i) {
        current_length = current_length * 2; // Mỗi lần nhân đôi chiều dài
        // Kiểm tra xem chiều dài có vượt quá m không
        if (current_length >= m) {
            break; // Nếu đã đủ dài thì dừng lại
        }
    }

    // Nếu độ dài của a_n nhỏ hơn m thì không tìm được chữ số thứ m
    if (current_length < m) {
        output << -1 << endl;
        return 0;
    }

    // Xác định chữ số thứ m trong a_n
    for (int i = n; i >= 0; --i) {
        // Tính chiều dài của a_i
        long long len_ai = length * (1LL << i); // 1LL << i tương đương với 2^i

        if (m > len_ai) {
            m -= len_ai; // Giảm m để tìm trong phần tiếp theo
        } else {
            // Xác định phần nào trong a_i mà chúng ta cần
            if (m <= length) {
                output << a0[m - 1] << endl; // Nếu nằm trong phần đầu
            } else {
                m -= length; // Giảm m để tìm trong phần sau
                output << a0[length - m] << endl; // Tìm trong phần đảo ngược
            }
            return 0;
        }
    }

    // Nếu không tìm thấy
    output << -1 << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
