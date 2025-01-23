#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("Xanhdep.Inp");
    ofstream fout("Xanhdep.Out");

    int N;
    fin >> N;

    int maxLen = 0; // Kết quả lớn nhất

    for (int i = 0; i < N; i++) {
        string road;
        fin >> road;

        char currentChar = road[0];
        int currentLen = 1;

        for (int j = 1; j < road.size(); j++) {
            if (road[j] == currentChar) {
                currentLen++;
            } else {
                maxLen = max(maxLen, currentLen);
                currentChar = road[j];
                currentLen = 1;
            }
        }
        // Cập nhật kết quả cho đoạn cuối cùng
        maxLen = max(maxLen, currentLen);
    }

    fout << maxLen << "\n";

    fin.close();
    fout.close();
    return 0;
}
