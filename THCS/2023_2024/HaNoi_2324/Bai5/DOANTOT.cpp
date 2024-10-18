#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Segment {
    int l, r;
};

int main() {
    const int MOD = 1e9 + 7;
    ifstream infile("DOANTOT.INP");
    ofstream outfile("DOANTOT.OUT");

    int N;
    infile >> N;

    vector<Segment> segments(N);
    for (int i = 0; i < N; ++i) {
        infile >> segments[i].l >> segments[i].r;
    }

    vector<vector<Segment>> groups;
    vector<int> results;

    for (int i = 0; i < N; ++i) {
        Segment current_segment = segments[i];
        bool merged = false;

        // Kiểm tra xem đoạn thẳng hiện tại có giao nhau với nhóm nào không
        for (int j = 0; j < groups.size(); ++j) {
            vector<Segment> &group = groups[j];
            // Kiểm tra giao nhau
            for (const auto& seg : group) {
                if (seg.l <= current_segment.r && seg.r >= current_segment.l) {
                    group.push_back(current_segment);
                    merged = true;
                    break;
                }
            }
            if (merged) break;
        }

        if (!merged) {
            // Tạo nhóm mới
            groups.push_back({current_segment});
        }

        // Tính tích độ tốt
        long long total_goodness = 1;
        for (const auto& group : groups) {
            total_goodness = (total_goodness * group.size()) % MOD;
        }

        results.push_back(total_goodness);
    }

    // Ghi kết quả ra tệp
    for (const auto& res : results) {
        outfile << res << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
