#include <iostream>
#include <fstream>

int main() {
    // Khai báo các biến
    int a, b, u, v, x, y;
    
    // Đọc dữ liệu từ file TICKET.INP
    std::ifstream input("TICKET.INP");
    input >> a >> b >> u >> v >> x >> y;
    input.close();

    // Tính số người lớn
    int adults = x - y;

    // Tính tổng chi phí
    int total_cost = (a * adults) + (b * y) + (u * adults) + (v * y);

    // Ghi kết quả vào file TICKET.OUT
    std::ofstream output("TICKET.OUT");
    output << total_cost;
    output.close();

    return 0;
}