#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;
int N;
long long H[MAXN], C[MAXN];
long long left_max[MAXN], right_max[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("CAU2.INP");
    ofstream fout("CAU2.OUT");

    fin >> N;
    for (int i = 1; i <= N; i++) fin >> H[i];
    for (int i = 1; i <= N; i++) fin >> C[i];

    long long result = 0;

    // Duyệt cây j làm cây giữa
    for (int j = 2; j < N; j++) {
        // Tính max giá trị thẩm mỹ bên trái (cây i)
        long long best_left = 0;
        for (int i = 1; i < j; i++) {
            if (H[i] < H[j]) {
                best_left = max(best_left, C[i]);
            }
        }

        // Tính max giá trị thẩm mỹ bên phải (cây k)
        long long best_right = 0;
        for (int k = j + 1; k <= N; k++) {
            if (H[j] < H[k]) {
                best_right = max(best_right, C[k]);
            }
        }

        // Cập nhật kết quả lớn nhất
        if (best_left > 0 && best_right > 0) {
            result = max(result, best_left + C[j] + best_right);
        }
    }

    fout << result << "\n";

    fin.close();
    fout.close();
    return 0;
}
