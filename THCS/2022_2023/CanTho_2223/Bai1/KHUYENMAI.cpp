#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Khai báo biến
    long long a, b, c, n;
    
    // Đọc dữ liệu từ file KHUYENMAI.INP
    ifstream fin("KHUYENMAI.INP");
    fin >> a >> b >> c >> n;
    fin.close();

    // Số lượng sách nhận được trong mỗi lần mua
    long long total_books_per_purchase = a + b;
    
    // Số lần mua đầy đủ
    long long full_purchase_times = n / total_books_per_purchase;
    
    // Số sách còn thiếu sau các lần mua đầy đủ
    long long remaining_books = n % total_books_per_purchase;

    // Tính tổng số tiền
    long long total_cost = full_purchase_times * a * c;

    // Xử lý số sách còn thiếu nếu cần mua thêm
    if (remaining_books > 0) {
        if (remaining_books <= a) {
            total_cost += remaining_books * c;
        } else {
            total_cost += a * c;
        }
    }

    // Ghi kết quả ra file KHUYENMAI.OUT
    ofstream fout("KHUYENMAI.OUT");
    fout << total_cost;
    fout.close();

    return 0;
}
