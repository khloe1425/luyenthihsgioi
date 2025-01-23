#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("CHIA3NHAN2.INP");
    ofstream fout("CHIA3NHAN2.OUT");

    int n; // Số lượng phần tử
    fin >> n;

    vector<int> divisibleBy3, doubledNumbers;

    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        if (x % 3 == 0) {
            divisibleBy3.push_back(x); // Số chia hết cho 3
        } else {
            doubledNumbers.push_back(x * 2); // Số không chia hết cho 3 nhân đôi
        }
    }

    // Sắp xếp nhóm chia hết cho 3 giảm dần
    sort(divisibleBy3.begin(), divisibleBy3.end(), greater<int>());
    // Sắp xếp nhóm không chia hết cho 3 (đã nhân đôi) tăng dần
    sort(doubledNumbers.begin(), doubledNumbers.end());

    // Ghi kết quả
    for (int x : divisibleBy3) {
        fout << x << " ";
    }
    for (int x : doubledNumbers) {
        fout << x << " ";
    }
    fout << "\n";

    fin.close();
    fout.close();
    return 0;
}
