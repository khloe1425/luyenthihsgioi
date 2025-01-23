#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Hàm tính tổng điểm tối đa
int getMaxBonus(int n, int m, const vector<string>& cards, const vector<int>& points, const vector<pair<int, int>>& luckyPairs) {
    vector<int> dp(n, 0);

    // Tính dp cho từng thẻ
    for (int i = 0; i < n; i++) {
        dp[i] = points[i]; // Điểm ban đầu là điểm của chính thẻ đó

        // Xét tất cả các cặp số may mắn
        for (const auto& pair : luckyPairs) {
            int p1 = pair.first;
            int p2 = pair.second;

            // Nếu thẻ hiện tại là một phần của cặp may mắn
            if (points[i] == p1 || points[i] == p2) {
                dp[i] = max(dp[i], p1 + p2);
            }
        }
    }

    // Trả về điểm lớn nhất
    return *max_element(dp.begin(), dp.end());
}

int main() {
    ifstream fin("BONUS.INP");
    ofstream fout("BONUS.OUT");

    if (!fin || !fout) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;

    vector<string> cards(n);
    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        fin >> cards[i] >> points[i];
    }

    vector<pair<int, int>> luckyPairs(m);
    for (int i = 0; i < m; i++) {
        fin >> luckyPairs[i].first >> luckyPairs[i].second;
    }

    int result = getMaxBonus(n, m, cards, points, luckyPairs);
    fout << result << endl;

    fin.close();
    fout.close();

    return 0;
}
