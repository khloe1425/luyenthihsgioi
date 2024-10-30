#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Đọc dữ liệu từ file BAI4.INP
    ifstream inp_file("BAI4.INP");
    int N, K;
    inp_file >> N >> K;
    
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        inp_file >> scores[i];
    }
    inp_file.close();
    
    // Biến lưu tổng lớn nhất và chỉ số bắt đầu của đội
    int max_sum = -1;
    int start_index = 0;

    // Tính tổng của đội gồm K bạn liên tiếp
    int current_sum = 0;
    for (int i = 0; i < K; i++) {
        current_sum += scores[i];
    }
    max_sum = current_sum;
    start_index = 0;
    
    // Duyệt qua các đoạn con K phần tử
    for (int i = K; i < N; i++) {
        current_sum = current_sum - scores[i - K] + scores[i];  // Trượt cửa sổ
        if (current_sum > max_sum || (current_sum == max_sum && i > start_index + K - 1)) {
            max_sum = current_sum;
            start_index = i - K + 1;
        }
    }
    
    // Ghi kết quả vào file BAI4.OUT
    ofstream out_file("BAI4.OUT");
    out_file << max_sum << endl;
    for (int i = start_index; i < start_index + K; i++) {
        out_file << (i + 1) << " ";  // Số báo danh bắt đầu từ 1
    }
    out_file << endl;
    out_file.close();

    return 0;
}
