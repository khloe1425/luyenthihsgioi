#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("MINAB.INP");
    ofstream fout("MINAB.OUT");

    int n, m;
    fin >> n >> m;

    vector<int> A(n), B(m);
    for (int i = 0; i < n; ++i) fin >> A[i];
    for (int j = 0; j < m; ++j) fin >> B[j];

    int min_value = INT_MAX; // Giá trị nhỏ nhất ban đầu

    // Duyệt qua mọi cặp (A[i], B[j])
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            min_value = min(min_value, abs(A[i] + B[j]));
        }
    }

    fout << min_value << "\n";

    fin.close();
    fout.close();

    return 0;
}
