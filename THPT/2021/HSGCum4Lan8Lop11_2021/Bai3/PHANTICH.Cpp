#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("PHANTICH.INP");
    ofstream fout("PHANTICH.OUT");

    int N;
    fin >> N;

    vector<int> divisors;

    // Tìm các ước số của N
    for (int i = 1; i <= sqrt(N); ++i) {
        if (N % i == 0) {
            divisors.push_back(i);
            if (i != N / i) { // Tránh trùng lặp nếu i*i = N
                divisors.push_back(N / i);
            }
        }
    }

    // Sắp xếp các ước số tăng dần
    sort(divisors.begin(), divisors.end());

    // Ghi số lượng ước số
    fout << divisors.size() << "\n";

    // Ghi các ước số, mỗi dòng tối đa 10 số
    for (size_t i = 0; i < divisors.size(); ++i) {
        fout << divisors[i];
        if ((i + 1) % 10 == 0 || i == divisors.size() - 1) {
            fout << "\n";
        } else {
            fout << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
