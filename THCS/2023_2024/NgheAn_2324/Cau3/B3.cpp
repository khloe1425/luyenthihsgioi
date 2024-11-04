#include <bits/stdc++.h>
using namespace std;

int main() {
    // Mở file để đọc và ghi
    freopen("B3.INP", "r", stdin);
    freopen("B3.OUT", "w", stdout);

    int n, m;
    cin >> n >> m; // Đọc n và m
    vector<int> a(n); // Mảng chứa số gạch ban đầu ở các chồng
    vector<int> b(m); // Mảng chứa số gạch ở các lượt chơi

    // Đọc số gạch ở các chồng ban đầu
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Đọc các lượt chơi
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Mảng used đánh dấu các chồng gạch đã được xếp thêm
    vector<bool> used(n, false);

    // Xử lý các lượt chơi
    for (int i = 0; i < m; i++) {
        int x = b[i];

        // Tìm chồng gạch ít nhất mà chưa bị xếp thêm
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                if (idx == -1 || a[j] < a[idx]) {
                    idx = j;
                }
            }
        }

        // Nếu tìm được chồng phù hợp thì thêm x viên gạch vào
        if (idx != -1) {
            a[idx] += x;
            used[idx] = true; // Đánh dấu chồng này đã được sử dụng
        }
    }

    // Tìm số điểm là số gạch ít nhất trong các chồng
    int result = *min_element(a.begin(), a.end());
    cout << result << endl;

    return 0;
}
