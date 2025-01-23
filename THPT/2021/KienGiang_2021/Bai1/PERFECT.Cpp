#include <bits/stdc++.h>
using namespace std;

// Danh sách các số hoàn hảo trong khoảng 10^6
vector<int> perfect_numbers = {6, 28, 496, 8128, 33550336};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("PERFECT.INP");
    ofstream fout("PERFECT.OUT");

    int M;
    fin >> M;  // Số lượng test

    while (M--) {
        int N;
        fin >> N;

        // Tìm số hoàn hảo lớn nhất <= N
        int result = -1;
        for (int num : perfect_numbers) {
            if (num <= N) result = num;
            else break;
        }

        fout << result << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
