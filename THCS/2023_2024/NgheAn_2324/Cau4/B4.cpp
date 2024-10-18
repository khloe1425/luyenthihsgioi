#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream infile("B4.INP");
    ofstream outfile("B4.OUT");

    int k;
    infile >> k;  // Số hàng
    string row1, row2;
    infile >> row1;  // Ống tre hàng 1

    // Ống tre hàng 2 nếu k = 2
    if (k == 2) {
        infile >> row2;
    }

    // Tạo danh sách ống tre
    vector<char> pipes;  // Danh sách ống tre

    // Thêm ống từ hàng đầu tiên
    for (char c : row1) {
        pipes.push_back(c);
    }

    // Thêm ống từ hàng thứ hai nếu có
    if (k == 2) {
        for (char c : row2) {
            pipes.push_back(c);
        }
    }

    // Biến đếm số thẻ bài đã bỏ
    int cards_used = 0;

    // Chỉ số để theo dõi các ống đã sử dụng
    int next_pipe_index = 0;  // Chỉ số ống tiếp theo có thể sử dụng

    // Duyệt qua thẻ bài từ 1 đến 1000000
    for (int card = 1; card <= 1000000; ++card) {
        // Nếu đã dùng hết các ống tre thì bỏ qua
        if (next_pipe_index >= pipes.size()) {
            break;
        }

        if (card % 2 == 0) {  // Thẻ chẵn
            // Tìm ống xanh tiếp theo
            while (next_pipe_index < pipes.size() && pipes[next_pipe_index] != 'B') {
                next_pipe_index++;
            }
            // Nếu tìm thấy ống xanh, bỏ thẻ vào
            if (next_pipe_index < pipes.size()) {
                cards_used++;
                next_pipe_index++;  // Chuyển sang ống tiếp theo
            }
        } else {  // Thẻ lẻ
            // Tìm ống đỏ tiếp theo
            while (next_pipe_index < pipes.size() && pipes[next_pipe_index] != 'R') {
                next_pipe_index++;
            }
            // Nếu tìm thấy ống đỏ, bỏ thẻ vào
            if (next_pipe_index < pipes.size()) {
                cards_used++;
                next_pipe_index++;  // Chuyển sang ống tiếp theo
            }
        }
    }

    // Tính điểm số cao nhất An có thể đạt được
    long long score = 1000000 - cards_used;

    // Ghi kết quả ra tệp
    outfile << score << endl;

    infile.close();
    outfile.close();
    return 0;
}
