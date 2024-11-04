#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc lưu đơn đặt phòng
struct Booking {
    int start, end, profit;
};

// Hàm tìm kiếm nhị phân để tìm đơn cuối cùng không chồng chéo với đơn hiện tại
int findLastNonOverlapping(const vector<Booking>& bookings, int currentStart) {
    int left = 0, right = bookings.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (bookings[mid].end < currentStart) {
            if (mid + 1 < bookings.size() && bookings[mid + 1].end < currentStart) {
                left = mid + 1;
            } else {
                return mid;
            }
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Hàm tính lợi nhuận lớn nhất
int maxProfit(const vector<Booking>& bookings) {
    int n = bookings.size();
    vector<int> dp(n, 0);
    dp[0] = bookings[0].profit;

    for (int i = 1; i < n; i++) {
        int currentProfit = bookings[i].profit;

        // Tìm đơn không chồng chéo gần nhất với đơn i
        int lastIndex = findLastNonOverlapping(bookings, bookings[i].start);
        if (lastIndex != -1) {
            currentProfit += dp[lastIndex];
        }

        // Lợi nhuận tối đa tại đơn i là chọn hoặc không chọn đơn i
        dp[i] = max(dp[i - 1], currentProfit);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cout << "Nhập số lượng đơn đặt phòng: ";
    cin >> n;

    vector<Booking> bookings(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhập a, b, c: ";
        cin >> bookings[i].start >> bookings[i].end >> bookings[i].profit;
    }

    // Sắp xếp các đơn đặt phòng theo ngày trả phòng
    sort(bookings.begin(), bookings.end(), [](const Booking& a, const Booking& b) {
        return a.end < b.end;
    });

    cout << maxProfit(bookings) << endl;
    return 0;
}
