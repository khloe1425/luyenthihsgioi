#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Event {
    int start, end, cost;
};

// So sánh các sự kiện theo thời gian kết thúc
bool compare(Event &a, Event &b) {
    return a.end < b.end;
}

int main() {
    ifstream input("REHALL.INP");
    ofstream output("REHALL.OUT");

    int n;
    input >> n;

    vector<Event> events(n);
    for (int i = 0; i < n; ++i) {
        input >> events[i].start >> events[i].end >> events[i].cost;
    }

    // Sắp xếp các sự kiện theo thời gian kết thúc
    sort(events.begin(), events.end(), compare);

    // Sử dụng map để lưu thời gian kết thúc và tổng chi phí tối ưu
    map<int, long long> dp;
    dp[0] = 0; // Khởi tạo trạng thái ban đầu

    long long max_profit = 0;

    for (auto &e : events) {
        // Tìm sự kiện có thể chọn trước sự kiện hiện tại mà không trùng thời gian
        auto it = dp.lower_bound(e.start);
        --it; // Lùi lại để lấy giá trị nhỏ hơn hoặc bằng e.start
        long long current_profit = it->second + e.cost;
        
        // Cập nhật tổng lợi nhuận tối ưu tại thời điểm e.end
        if (current_profit > dp[e.end]) {
            dp[e.end] = current_profit;
            max_profit = max(max_profit, current_profit);
        }
    }

    // Ghi kết quả ra file
    output << max_profit << endl;

    input.close();
    output.close();

    return 0;
}
