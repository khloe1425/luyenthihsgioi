#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI1.INP");
    ofstream fout("BAI1.OUT");

    long long N, a, b; // Dùng long long để xử lý N lớn
    fin >> N >> a >> b;

    long long min_people = N - b;          // Số người tối thiểu
    long long max_people = a + b;          // Số người tối đa

    fout << min_people << " " << max_people << "\n";

    fin.close();
    fout.close();

    return 0;
}
