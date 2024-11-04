#include <iostream>
#include <fstream>

// Hàm tính vị trí kim giờ sau khi xoay
int calculate_hour(int N) {
    int initial_position = 12; // Vị trí ban đầu là 12 giờ
    
    // Giảm N theo modulo 12 để lấy số giờ di chuyển thực sự
    int effective_N = N % 12;
    
    // Tính vị trí cuối cùng bằng cách cộng số giờ di chuyển thực sự vào vị trí ban đầu
    int final_position = (initial_position + effective_N) % 12;
    
    // Nếu vị trí cuối cùng là 0, thì nó nên được chuyển thành 12 (vì 12 giờ trên đồng hồ tương đương với vị trí 0)
    if (final_position == 0) {
        final_position = 12;
    }

    return final_position;
}

int main() {
    std::ifstream infile("BAI02.INP"); // Mở file đầu vào
    std::ofstream outfile("BAI02.OUT"); // Mở file đầu ra
    
    // Kiểm tra xem file có mở thành công không
    if (!infile || !outfile) {
        std::cerr << "Lỗi mở file đầu vào hoặc đầu ra!" << std::endl;
        return 1;
    }

    int N;
    // Đọc từng giá trị N từ file đầu vào
    while (infile >> N) {
        int result = calculate_hour(N); // Tính kết quả
        outfile << result << std::endl; // Ghi kết quả vào file đầu ra
    }
    
    // Đóng file sau khi xử lý xong
    infile.close();
    outfile.close();

    return 0;
}
