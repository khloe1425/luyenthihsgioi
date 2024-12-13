#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Mở file input và output
    ifstream fileNhap("BAI1.INP");
    ofstream fileXuat("BAI1.OUT");

    if (!fileNhap.is_open() || !fileXuat.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int tongTien, soConGa, soConVit;
    fileNhap >> tongTien >> soConGa >> soConVit; // Đọc dữ liệu từ file

    int soCach = 0;

    // Lặp qua tất cả các giá trị có thể của giá gà
    for (int giaGa = 1; giaGa <= tongTien; ++giaGa) {
        // Tính giá vịt dựa trên công thức còn lại
        int giaVit = (tongTien - giaGa * soConGa) / soConVit;
        
        // Kiểm tra nếu giá vịt hợp lệ và thỏa mãn phương trình
        if (giaVit > 0 && giaGa * soConGa + giaVit * soConVit == tongTien) {
            soCach++;
        }
    }

    // Ghi kết quả vào file output
    fileXuat << soCach << endl;

    // Đóng file
    fileNhap.close();
    fileXuat.close();

    return 0;
}
