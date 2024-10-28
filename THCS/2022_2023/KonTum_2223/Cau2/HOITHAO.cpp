#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm đọc dữ liệu từ file HOITHAO.INP
void read_hoithao_inp(const string &file_path, int &n, vector<int> &a) {
    ifstream file(file_path);
    if (file.is_open()) {
        file >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            file >> a[i];
        }
        file.close();
    }
}

// Hàm ghi kết quả vào file HOITHAO.OUT
void write_hoithao_out(const string &file_path, int distinct_count, int most_common_event) {
    ofstream file(file_path);
    if (file.is_open()) {
        file << distinct_count << endl;
        file << most_common_event << endl;
        file.close();
    }
}

int main() {
    // Đường dẫn file
    string file_path_inp = "HOITHAO.INP";
    string file_path_out = "HOITHAO.OUT";

    // Đọc dữ liệu từ file HOITHAO.INP
    int n;
    vector<int> a;
    read_hoithao_inp(file_path_inp, n, a);

    // Bước 1: Tìm số lượng nội dung thi đấu khác nhau
    unordered_set<int> distinct_events(a.begin(), a.end());
    int distinct_count = distinct_events.size();

    // Bước 2: Tìm nội dung thi đấu có nhiều học sinh đăng ký nhất
    unordered_map<int, int> event_count;
    for (int event : a) {
        event_count[event]++;
    }

    int most_common_event = -1;
    int max_count = 0;
    
    // Duyệt qua từng nội dung và tìm nội dung có số lượng học sinh đăng ký nhiều nhất
    for (const auto &pair : event_count) {
        if (pair.second > max_count || (pair.second == max_count && pair.first < most_common_event)) {
            most_common_event = pair.first;
            max_count = pair.second;
        }
    }

    // Ghi kết quả vào file HOITHAO.OUT
    write_hoithao_out(file_path_out, distinct_count, most_common_event);

    return 0;
}
