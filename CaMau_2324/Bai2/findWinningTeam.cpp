#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string input_path = "trochoi.inp";
    string output_path = "trochoi.out";

    ifstream infile(input_path);
    if (!infile.is_open()) {
        cerr << "Không thể mở tệp: " << input_path << endl;
        return 1;
    }

    int m, n;
    infile >> m >> n;

    // Tạo vector để lưu tổng điểm của từng đội
    vector<int> scores(n, 0);

    // Đọc điểm của từng đội cho mỗi câu hỏi
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int points;
            infile >> points;
            scores[j] += points;  // Cộng điểm cho từng đội
        }
    }

    infile.close();

    // Tìm đội có tổng điểm cao nhất
    int max_score = scores[0];
    int winning_team_index = 0;  // Chỉ số đội bắt đầu từ 0

    for (int i = 1; i < n; ++i) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            winning_team_index = i;  // Cập nhật chỉ số đội chiến thắng
        }
    }

    ofstream outfile(output_path);
    if (!outfile.is_open()) {
        cerr << "Không thể mở tệp: " << output_path << endl;
        return 1;
    }

    outfile << winning_team_index + 1 << " " << max_score << endl; // Thêm 1 để có thứ tự bắt đầu từ 1

    outfile.close();

    return 0;
}
