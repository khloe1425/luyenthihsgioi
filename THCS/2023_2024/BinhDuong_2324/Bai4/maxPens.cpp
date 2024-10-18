#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm để tính số lượng bút tối đa mà Nam có thể mua
int maxPens(int N, int M, vector<pair<int, int>>& pens) {
    // Sắp xếp các loại bút theo giá
    sort(pens.begin(), pens.end());

    int totalPens = 0; // Tổng số bút đã mua

    for (int i = 0; i < N; ++i) {
        int price = pens[i].first; // Giá của loại bút hiện tại
        int quantity = pens[i].second; // Số lượng của loại bút hiện tại

        if (M <= 0) {
            break; // Nếu không còn tiền, dừng lại
        }

        // Tính số bút có thể mua từ loại này
        int maxCanBuy = min(quantity, M / price);

        // Cập nhật tổng số bút và số tiền còn lại
        totalPens += maxCanBuy;
        M -= maxCanBuy * price;
    }

    return totalPens;
}

int main() {
    int N, M;
    cout << "Nhập số loại bút N: ";
    cin >> N;
    cout << "Nhập số tiền M: ";
    cin >> M;

    vector<pair<int, int>> pens(N);
    for (int i = 0; i < N; ++i) {
        int price, quantity;
        cout << "Nhập giá và số lượng của từng loại bút: ";
        cin >> price >> quantity;
        pens[i] = make_pair(price, quantity);
    }

    int result = maxPens(N, M, pens);

    cout << "Số lượng bút tối đa mà Nam có thể mua: " << result << endl;

    return 0;
}
