#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI5.INP");
    ofstream fout("BAI5.OUT");

    int n;
    fin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    long long totalCost = 0; // Tổng chi phí
    int start = 0;

    while (start < n) {
        // Lấy các món hàng cho giỏ hàng hiện tại (tối đa 39 món)
        vector<int> basket;
        for (int i = start; i < min(start + 39, n); i++) {
            basket.push_back(a[i]);
        }

        // Sắp xếp giỏ hàng để áp dụng khuyến mãi
        sort(basket.begin(), basket.end());

        long long currentCost = accumulate(basket.begin(), basket.end(), 0LL);

        // Áp dụng khuyến mãi
        int size = basket.size();
        if (size >= 10 && size <= 19) {
            currentCost -= basket[0]; // Giảm món rẻ nhất
        } else if (size >= 20 && size <= 29) {
            currentCost -= basket[1]; // Giảm món rẻ nhì
        } else if (size >= 30 && size <= 39) {
            currentCost -= basket[2]; // Giảm món rẻ thứ ba
        }

        totalCost += currentCost; // Cộng chi phí của giỏ hiện tại
        start += basket.size();   // Tiến đến giỏ hàng tiếp theo
    }

    fout << totalCost << "\n";

    fin.close();
    fout.close();
    return 0;
}
