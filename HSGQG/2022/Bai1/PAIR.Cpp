#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("PAIR.INP");
    ofstream fout("PAIR.OUT");

    int n, d;
    fin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    // Sắp xếp điểm
    sort(a.begin(), a.end());

    int count = 0;
    int left = 0, right = n - 1;

    while (left < right) {
        if (a[left] + a[right] <= a[right] + d) {
            count++;
            left++;
            right--;
        } else {
            right--;
        }
    }

    fout << count << endl;

    fin.close();
    fout.close();
    return 0;
}
