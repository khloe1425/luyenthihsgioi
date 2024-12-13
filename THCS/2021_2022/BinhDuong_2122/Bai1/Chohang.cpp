#include <iostream>
#include <fstream>
#include <algorithm>

// Hàm tính khối lượng tối đa Bo có thể chở mà không vượt quá N
int max_weight(int N, int A, int B) {
    int max_weight_carried = 0;

    // Duyệt qua số lượng các gói hàng loại A có thể mang (tối đa là N / A gói)
    for (int x = 0; x * A <= N; ++x) {
        // Khối lượng còn lại sau khi mang x gói hàng loại A
        int remaining_capacity = N - x * A;

        // Số lượng tối đa gói hàng loại B có thể mang trong phần khối lượng còn lại
        int y = remaining_capacity / B;

        // Tính tổng khối lượng hàng có thể mang với x gói loại A và y gói loại B
        int total_weight = x * A + y * B;

        // Cập nhật khối lượng tối đa có thể mang nếu lớn hơn khối lượng đã tìm thấy trước đó
        max_weight_carried = std::max(max_weight_carried, total_weight);
    }

    return max_weight_carried;
}

int main() {
    // Mở file đầu vào
    std::ifstream infile("Chohang.INP");
    if (!infile) {
        std::cerr << "Lỗi mở file Chohang.INP!" << std::endl;
        return 1;
    }

    // Đọc dữ liệu từ file
    int N, A, B;
    infile >> N >> A >> B;
    infile.close();

    // Tính khối lượng tối đa có thể mang
    int result = max_weight(N, A, B);

    // Ghi kết quả vào file đầu ra
    std::ofstream outfile("Chohang.OUT");
    if (!outfile) {
        std::cerr << "Lỗi mở file Chohang.OUT!" << std::endl;
        return 1;
    }
    outfile << result << std::endl;
    outfile.close();

    return 0;
}
