#include <iostream>

using namespace std;

int countValidBoxes(int m, int n) {
    int count = 0; // Biến đếm số loại hộp bánh
    for (int i = 1; i <= n; i++) {
        // Tính tổng số gói bánh trong hộp
        int totalPackages = (i * (i + 1)) / 2; 
        // Kiểm tra xem tổng số gói bánh có chia đều cho m không
        if (totalPackages % m == 0) {
            count++;
        }
    }
    return count; // Trả về số loại hộp bánh
}

int main() {
    int m, n;
    
    // Nhập dữ liệu từ bàn phím
    cout << "Nhập số lượng học sinh (m): ";
    cin >> m;
    cout << "Nhập kích thước tối đa của hộp bánh (n): ";
    cin >> n;

    int result = countValidBoxes(m, n); // Tính số loại hộp bánh
    cout << result << endl; // In ra kết quả
    return 0;
}