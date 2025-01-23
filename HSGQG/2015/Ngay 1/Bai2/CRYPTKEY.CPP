#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

// Hàm tính GCD
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Hàm tính LCM
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ifstream input("CRYPTKEY.INP");
    ofstream output("CRYPTKEY.OUT");

    int T; // Số lượng bộ dữ liệu
    input >> T;

    while (T--) {
        int n;
        input >> n;

        vector<long long> keys(n);
        for (int i = 0; i < n; ++i) {
            input >> keys[i];
        }

        long long k;
        input >> k;

        // Tập hợp chứa các khóa
        set<long long> S(keys.begin(), keys.end());
        vector<long long> to_process(keys.begin(), keys.end());

        // Mở rộng tập S bằng GCD và LCM
        while (!to_process.empty()) {
            vector<long long> next_process;
            for (size_t i = 0; i < to_process.size(); ++i) {
                for (size_t j = i + 1; j < to_process.size(); ++j) {
                    long long new_gcd = gcd(to_process[i], to_process[j]);
                    long long new_lcm = lcm(to_process[i], to_process[j]);

                    if (S.insert(new_gcd).second) {
                        next_process.push_back(new_gcd);
                    }
                    if (new_lcm <= 1e12 && S.insert(new_lcm).second) {
                        next_process.push_back(new_lcm);
                    }
                }
            }
            to_process = move(next_process);
        }

        // Kiểm tra xem k có thuộc tập S không
        if (S.count(k)) {
            output << "YES" << endl;
        } else {
            output << "NO" << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}
