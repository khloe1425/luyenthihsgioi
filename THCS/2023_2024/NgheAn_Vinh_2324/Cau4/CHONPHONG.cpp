#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ file CHONPHONG.INP
    ifstream infile("CHONPHONG.INP");
    int N, K;
    infile >> N >> K;

    string S;
    infile >> S;
    infile.close();

    // Tạo danh sách vị trí các phòng trống
    vector<int> empty_rooms;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            empty_rooms.push_back(i);
        }
    }

    int min_distance = N; // Khởi tạo khoảng cách lớn nhất có thể
    int num_empty = empty_rooms.size();

    // Duyệt qua các nhóm phòng trống với kích thước K+1
    for (int i = 0; i <= num_empty - K - 1; ++i) {
        // Phòng của Thầy Nam là phòng ở giữa nhóm
        int teacher_room = empty_rooms[i + K / 2];
        // Khoảng cách lớn nhất từ phòng của Thầy Nam đến phòng của học sinh xa nhất
        int max_distance = max(teacher_room - empty_rooms[i], empty_rooms[i + K] - teacher_room);
        min_distance = min(min_distance, max_distance);
    }

    // Ghi kết quả ra file CHONPHONG.OUT
    ofstream outfile("CHONPHONG.OUT");
    outfile << min_distance << endl;
    outfile.close();

    return 0;
}
