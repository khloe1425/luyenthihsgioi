#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Đọc dữ liệu từ file CAKE.INP
    std::ifstream infile("CAKE.INP");
    int N;
    infile >> N;
    std::string cake;
    infile >> cake;
    infile.close();

    // Biến lưu tổng số quả dâu và sim
    int totalD = 0, totalS = 0;

    // Tính tổng số quả dâu và sim
    for (char c : cake) {
        if (c == 'D') totalD++;
        else if (c == 'S') totalS++;
    }

    // Nếu tổng số quả dâu hoặc sim là lẻ thì không thể chia đều
    if (totalD % 2 != 0 || totalS % 2 != 0) {
        std::ofstream outfile("CAKE.OUT");
        outfile << -1 << std::endl;
        outfile.close();
        return 0;
    }

    // Biến lưu số lượng quả dâu và sim trong đoạn hiện tại
    int countD, countS;

    // Duyệt qua từng vị trí để tìm cách chia
    for (int start = 0; start < N; start++) {
        countD = 0;
        countS = 0;

        // Tính số lượng quả trong đoạn từ start đến start + N/2
        for (int length = 0; length < N; length++) {
            if (cake[(start + length) % N] == 'D') {
                countD++;
            } else {
                countS++;
            }

            // Kiểm tra nếu số lượng quả đến hiện tại đã đủ chia đều
            if (length + 1 >= N / 2) {
                // Kiểm tra điều kiện cắt bánh
                if (countD == totalD / 2 && countS == totalS / 2) {
                    int end = (start + length) % N;

                    // Định dạng kết quả a, b (a < b)
                    int a = start + 1;
                    int b = end + 1;

                    // Điều chỉnh b nếu b < a
                    if (b <= a) {
                        b += N;
                    }

                    std::ofstream outfile("CAKE.OUT");
                    outfile << a << " " << b << std::endl; // Ghi kết quả
                    outfile.close();
                    return 0; // Kết thúc chương trình
                }
            }
        }
    }

    // Nếu không tìm thấy cách chia, ghi -1 vào file
    std::ofstream outfile("CAKE.OUT");
    outfile << -1 << std::endl;
    outfile.close();

    return 0;
}
