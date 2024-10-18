#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Line; // Cặp (a, b) biểu diễn đường thẳng

int countParallelLines(vector<Line> &lines) {
    int n = lines.size();
    sort(lines.begin(), lines.end()); // Sắp xếp theo hệ số góc a

    int count = 0;
    int prevA = lines[0].first;
    for (int i = 1; i < n; ++i) {
        if (lines[i].first == prevA && lines[i].second != lines[i - 1].second) {
            count++;
        }
        prevA = lines[i].first;
    }

    return count;
}

int main() {
    freopen("CAU4.INP", "r", stdin);
    freopen("CAU4.OUT", "w", stdout);

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; ++i) {
        cin >> lines[i].second >> lines[i].first; // Lưu ý: đổi chỗ a và b để sắp xếp theo a
    }

    int result = countParallelLines(lines);
    cout << result << endl;

    return 0;
}