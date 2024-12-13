#include <iostream>
#include <vector>
#include <fstream>

// Hàm tìm độ dài ngắn nhất của mẫu lặp lại trong chuỗi hạt
int timDoDaiMauLap(const std::vector<int>& hat, int N) {
    for (int doDai = 1; doDai <= N; ++doDai) {
        bool laMau = true;
        
        // Kiểm tra từng đoạn có độ dài tương đương doDai
        for (int i = doDai; i < N; ++i) {
            if (hat[i] != hat[i % doDai]) {
                laMau = false;
                break;
            }
        }
        
        // Nếu tìm thấy mẫu lặp, trả về độ dài của mẫu
        if (laMau) return doDai;
    }
    
    // Nếu không tìm thấy mẫu, trả về N (độ dài toàn chuỗi)
    return N;
}

int main() {
    std::ifstream inputFile("Vongtay.INP");  // Mở file Vongtay.INP để đọc dữ liệu
    std::ofstream outputFile("Vongtay.OUT"); // Mở file Vongtay.OUT để ghi kết quả

    int N;
    inputFile >> N; // Đọc số lượng hạt
    std::vector<int> hat(N);
    
    // Đọc dãy hạt từ file Vongtay.INP
    for (int i = 0; i < N; ++i) {
        inputFile >> hat[i];
    }
    
    // Tính toán kết quả
    int ketQua = timDoDaiMauLap(hat, N);
    
    // Ghi kết quả ra file Vongtay.OUT
    outputFile << ketQua << std::endl;

    // Đóng file sau khi xử lý xong
    inputFile.close();
    outputFile.close();

    return 0;
}
