#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream input("HAUCAN.INP");
    ofstream output("HAUCAN.OUT");

    // Kiểm tra mở file
    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc dữ liệu từ file
    long long L, Q, K, D;
    input >> L >> Q >> K >> D;

    // Nếu khoảng cách giữa hai bể chứa lớn hơn dung tích bình xăng -> Không thể đi được
    if (D > K) {
        output << -1 << endl;
        return 0;
    }

    // Tính lượng xăng vận chuyển tối đa
    long long fuel_carried = Q;      // Lượng xăng ban đầu được vận chuyển
    long long current_fuel = Q;      // Lượng xăng hiện tại trên xe

    // Duyệt qua từng đoạn đường
    for (long long pos = 0; pos < L; pos += D) {
        long long distance_to_next = min(D, L - pos); // Khoảng cách đến bể tiếp theo hoặc đến đích

        // Nếu lượng xăng hiện tại không đủ, cần nạp thêm
        if (current_fuel < distance_to_next) {
            long long fuel_needed = distance_to_next - current_fuel;

            // Kiểm tra nếu lượng xăng cần vượt quá khả năng nạp
            if (fuel_needed > Q) {
                output << -1 << endl;
                return 0;
            }

            // Nạp thêm xăng
            current_fuel += fuel_needed;
        }

        // Di chuyển đến bể tiếp theo, giảm xăng
        current_fuel -= distance_to_next;
    }

    // Ghi kết quả lượng xăng vận chuyển
    output << fuel_carried << endl;

    input.close();
    output.close();
    return 0;
}
