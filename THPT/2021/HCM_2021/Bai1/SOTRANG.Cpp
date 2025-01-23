#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll countDigits(ll P) {
    ll total = 0, digits = 1, base = 4;
    while (base <= P) {
        ll nextBase = min(P + 1, base * 10); // Mốc tiếp theo
        total += (nextBase - base) * digits;
        base = nextBase;
        digits++;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("SOTRANG.INP");
    ofstream fout("SOTRANG.OUT");

    ll N;
    fin >> N;

    ll low = 4, high = 10000000, result = 4; // Bắt đầu từ trang 4
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (countDigits(mid) < N) {
            low = mid + 1;
        } else {
            result = mid;
            high = mid - 1;
        }
    }

    fout << result << "\n";
    fin.close();
    fout.close();
    return 0;
}
