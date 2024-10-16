#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    ifstream infile("TROCHOI.INP");
    ofstream outfile("TROCHOI.OUT");

    long long N, M;
    infile >> N >> M;

    vector<pair<long long, long long>> skills(N);
    for (int i = 0; i < N; ++i) {
        infile >> skills[i].first >> skills[i].second;  // Đọc si và ei
    }

    long long max_power = 0;
    priority_queue<pair<long long, long long>> max_heap;

    // Thêm tất cả các kỹ năng vào heap
    for (const auto& skill : skills) {
        long long si = skill.first;
        long long ei = skill.second;
        max_heap.push({si + ei, ei});  // Thêm sức mạnh lần đầu tiên
    }

    // Nâng cấp trong M phút
    for (int i = 0; i < M; ++i) {
        if (!max_heap.empty()) {
            // Lấy kỹ năng có sức mạnh tối đa
            max_power += max_heap.top().first;  // Thêm sức mạnh vào kết quả
            long long next_power = max_heap.top().second;  // Chỉ số sức mạnh cho lần sau
            max_heap.pop();  // Xóa kỹ năng này
            max_heap.push({next_power, next_power});  // Thêm lại với chỉ số mới
        }
    }

    // Ghi kết quả ra tệp
    outfile << max_power << endl;

    infile.close();
    outfile.close();
    return 0;
}
