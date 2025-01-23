#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// Hàm tính phép OR của các phần tử trong tổ hợp
long long calculateOR(const vector<int>& subset) {
    long long result = 0;
    for (int num : subset) {
        result |= num;
    }
    return result;
}

// Hàm sinh tổ hợp k phần tử từ n phần tử
void generateCombinations(const vector<int>& arr, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < arr.size(); i++) {
        current.push_back(arr[i]);
        generateCombinations(arr, k, i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    ifstream fin("OR.INP");
    ofstream fout("OR.OUT");

    if (!fin || !fout) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc input
    int n, k, L, R;
    fin >> n >> k >> L >> R;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    vector<vector<int>> combinations;
    vector<int> current;

    // Sinh tổ hợp
    generateCombinations(arr, k, 0, current, combinations);

    long long result = 0;

    // Kiểm tra từng tổ hợp
    for (const auto& subset : combinations) {
        long long orValue = calculateOR(subset);
        if (orValue >= L && orValue <= R && orValue % 3 == 0) {
            result++;
        }
    }

    // Ghi kết quả
    fout << result % MOD << endl;

    fin.close();
    fout.close();

    return 0;
}
