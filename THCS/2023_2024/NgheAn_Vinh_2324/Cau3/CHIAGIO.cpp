#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

// Hàm kiểm tra có thể chia thành các nhóm có tổng là target_sum
bool canDivideGroups(const vector<int>& hours, int target_sum, vector<vector<int>>& groups) {
    int current_sum = 0;
    vector<int> temp_group;

    for (int hour : hours) {
        current_sum += hour;
        temp_group.push_back(hour);

        if (current_sum == target_sum) {
            groups.push_back(temp_group);
            current_sum = 0;
            temp_group.clear();
        } else if (current_sum > target_sum) {
            return false; // Không thể chia nhóm với target_sum này
        }
    }
    
    return current_sum == 0;
}

int main() {
    // Đọc dữ liệu từ file CHIAGIO.INP
    ifstream infile("CHIAGIO.INP");
    int n;
    infile >> n;

    vector<int> hours(n);
    for (int i = 0; i < n; i++) {
        infile >> hours[i];
    }
    infile.close();

    // Tính tổng tất cả các giờ làm việc
    int total = accumulate(hours.begin(), hours.end(), 0);

    // Tìm tổng S lớn nhất có thể chia thành nhiều nhóm nhất
    int max_k = 0;
    int best_sum = 0;
    vector<vector<int>> best_groups;

    for (int S = 1; S <= total; S++) {
        if (total % S == 0) {
            vector<vector<int>> groups;
            if (canDivideGroups(hours, S, groups) && groups.size() > max_k) {
                max_k = groups.size();
                best_groups = groups;
                best_sum = S;
            }
        }
    }

    // Ghi kết quả ra file CHIAGIO.OUT
    ofstream outfile("CHIAGIO.OUT");
    outfile << max_k << " " << best_sum << endl;
    for (const auto& group : best_groups) {
        for (int hour : group) {
            outfile << hour << " ";
        }
        outfile << endl;
    }
    outfile.close();

    return 0;
}
