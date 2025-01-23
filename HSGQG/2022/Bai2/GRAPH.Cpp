#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, b;
vector<int> a;

bool isValid(const vector<int>& arr, int b) {
    for (int x : arr) {
        if (x > b) return false;
    }
    return true;
}

int countWays(const vector<int>& arr, int f, int b) {
    vector<int> unknown_positions;
    int fixed_value = -1;

    // Tìm vị trí chưa biết và giá trị cố định
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == -1) {
            unknown_positions.push_back(i);
        } else if (fixed_value == -1) {
            fixed_value = arr[i];
        }
    }

    if (fixed_value == -1) return 1;

    // Đếm số cách điền các giá trị
    int ways = 1;
    for (int pos : unknown_positions) {
        ways = (ways * fixed_value) % MOD;
    }

    return ways;
}

int main() {
    ifstream fin("GRAPH.INP");
    ofstream fout("GRAPH.OUT");

    fin >> n >> b;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    int result = 0;
    for (int f = 0; f <= b; ++f) {
        vector<int> temp = a;

        for (int& x : temp) {
            if (x == -1) x = f;
        }

        if (isValid(temp, b)) {
            result = (result + countWays(a, f, b)) % MOD;
        }
    }

    fout << result << endl;

    fin.close();
    fout.close();
    return 0;
}
