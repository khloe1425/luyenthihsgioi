#include <bits/stdc++.h>
using namespace std;

int N, K; // N: Tổng cần phân tích, K: Giá trị nhỏ nhất của các số hạng
vector<int> current; // Lưu cách phân tích hiện tại
bool hasSolution = false;
ofstream fout; // File output

// Hàm quay lui để tìm các cách phân tích
void backtrack(int sum, int last) {
    if (sum == N) { // Nếu tổng bằng N, ghi kết quả ra file
        hasSolution = true;
        fout << current.size() << " " << last << "\n";
        return;
    }

    // Duyệt các số từ K đến N - sum
    for (int i = K; sum + i <= N; i++) {
        current.push_back(i);
        backtrack(sum + i, i); // Gọi đệ quy với tổng mới
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("PHANTICH.INP");
    fout.open("PHANTICH.OUT");

    while (fin >> N >> K) {
        current.clear();
        hasSolution = false;

        backtrack(0, 0); // Gọi hàm quay lui từ tổng bằng 0

        if (!hasSolution) { // Nếu không tìm thấy cách nào hợp lệ
            fout << "0\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
