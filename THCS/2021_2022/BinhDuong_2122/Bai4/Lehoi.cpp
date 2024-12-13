#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream infile("Lehoi.INP"); // Mở tệp đầu vào "Lehoi.INP" để đọc
    ofstream outfile("Lehoi.OUT"); // Mở tệp đầu ra "Lehoi.OUT" để ghi

    int N;
    infile >> N;
    vector<pair<int, int>> activities(N);

    // Nhập thời gian bắt đầu và kết thúc của mỗi trò chơi từ tệp
    for (int i = 0; i < N; i++) {
        infile >> activities[i].first >> activities[i].second;
    }

    // Sắp xếp các trò chơi theo thời gian kết thúc
    sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0;
    int last_end_time = 0;

    // Chọn các trò chơi dựa trên thuật toán tham lam
    for (const auto& activity : activities) {
        if (activity.first >= last_end_time) {
            count++;
            last_end_time = activity.second;
        }
    }

    // Ghi số lượng trò chơi tối đa không trùng nhau vào tệp đầu ra
    outfile << count << endl;

    // Đóng các tệp đầu vào và đầu ra
    infile.close();
    outfile.close();

    return 0;
}
