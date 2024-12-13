#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 5005;
long long D1_row[MAXN][MAXN], D0_row[MAXN][MAXN];
long long D1_col[MAXN][MAXN], D0_col[MAXN][MAXN];
long long prefixD1_row[MAXN][MAXN], prefixD0_row[MAXN][MAXN];
long long prefixD1_col[MAXN][MAXN], prefixD0_col[MAXN][MAXN];

void update_row(int r, int x, int y) {
    int mid = (x + y) / 2;

    // Cập nhật đoạn [x..mid]
    for (int j = x; j <= mid; j++) {
        D1_row[r][j]++;
        D0_row[r][j] -= (j - x);
    }

    // Cập nhật đoạn [mid+1..y]
    for (int j = mid + 1; j <= y; j++) {
        D1_row[r][j]--;
        D0_row[r][j] += (y - j);
    }
}

void update_col(int c, int x, int y) {
    int mid = (x + y) / 2;

    // Cập nhật đoạn [x..mid]
    for (int i = x; i <= mid; i++) {
        D1_col[c][i]++;
        D0_col[c][i] -= (i - x);
    }

    // Cập nhật đoạn [mid+1..y]
    for (int i = mid + 1; i <= y; i++) {
        D1_col[c][i]--;
        D0_col[c][i] += (y - i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, T, Q;
    cin >> N >> T;

    memset(D1_row, 0, sizeof(D1_row));
    memset(D0_row, 0, sizeof(D0_row));
    memset(D1_col, 0, sizeof(D1_col));
    memset(D0_col, 0, sizeof(D0_col));

    // Xử lý T thao tác
    for (int i = 0; i < T; i++) {
        int k, rc, x, y;
        cin >> k >> rc >> x >> y;

        if (k == 1) {
            update_row(rc, x, y);
        } else {
            update_col(rc, x, y);
        }
    }

    // Tính tiền tố cho các mảng hiệu
    for (int r = 1; r <= N; r++) {
        for (int j = 1; j <= N; j++) {
            prefixD1_row[r][j] = prefixD1_row[r][j - 1] + D1_row[r][j];
            prefixD0_row[r][j] = prefixD0_row[r][j - 1] + D0_row[r][j];
        }
    }

    for (int c = 1; c <= N; c++) {
        for (int i = 1; i <= N; i++) {
            prefixD1_col[c][i] = prefixD1_col[c][i - 1] + D1_col[c][i];
            prefixD0_col[c][i] = prefixD0_col[c][i - 1] + D0_col[c][i];
        }
    }

    // Xử lý Q truy vấn
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;

        // Đóng góp từ dòng và cột
        long long row_contrib = prefixD1_row[u][v] * v + prefixD0_row[u][v];
        long long col_contrib = prefixD1_col[v][u] * u + prefixD0_col[v][u];

        cout << row_contrib + col_contrib << '\n';
    }

    return 0;
}
