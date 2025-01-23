#include <bits/stdc++.h>
using namespace std;

bool canUnlock(const string &T, const string &S) {
    if (T.size() != S.size()) return false; // Chiều dài khác nhau
    for (size_t i = 0; i < T.size(); i++) {
        if (T[i] != '?' && T[i] != S[i]) return false; // Không khớp
    }
    return true; // Thỏa mãn điều kiện mở khóa
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("CAU3.INP");
    ofstream fout("CAU3.OUT");

    string T; // Mã số thẻ
    int N;    // Số phòng
    fin >> T >> N;

    for (int i = 0; i < N; i++) {
        string S;
        fin >> S;
        if (canUnlock(T, S)) {
            fout << 1 << "\n";
        } else {
            fout << 0 << "\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
