#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Hàm kiểm tra nếu có thể tạo ra bộ sưu tập giá trị lớn hơn hoặc bằng `k` từ các gói tiền
bool canCollect(int k, int Z0, int S0, int M0, vector<int> Z, vector<int> S, vector<int> M, vector<int> cost) {
    int n = Z.size();
    for (int i = 0; i < (1 << n); i++) { // Kiểm tra tất cả các tổ hợp
        int z = Z0, s = S0, m = M0, value = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // Nếu chọn gói tiền thứ j
                z += Z[j];
                s += S[j];
                m += M[j];
                value += cost[j];
                if (z > 4 || s > 4 || m > 4) break; // Vi phạm giới hạn
            }
        }
        if (value >= k) return true; // Nếu đạt giá trị >= k
    }
    return false;
}

int main() {
    ifstream fin("COLLECT.INP");
    ofstream fout("COLLECT.OUT");
    int T;
    fin >> T;

    while (T--) {
        int k, Z0, S0, M0, n;
        fin >> k >> Z0 >> S0 >> M0 >> n;
        vector<int> Z(n), S(n), M(n), cost(n);
        for (int i = 0; i < n; i++) {
            fin >> Z[i] >> S[i] >> M[i] >> cost[i];
        }

        if (canCollect(k, Z0, S0, M0, Z, S, M, cost)) {
            fout << "1\n";
        } else {
            fout << "0\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
