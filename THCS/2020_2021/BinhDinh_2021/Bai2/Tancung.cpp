#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Mở file input và output
    freopen("TANCUNG.INP", "r", stdin);
    freopen("TANCUNG.OUT", "w", stdout);

    long long P, Q;
    cin >> P >> Q;

    // Lấy chữ số tận cùng của P
    int lastDigit = P % 10;

    // Tìm chu kỳ của lastDigit
    vector<int> cycle;
    int current = lastDigit;
    do {
        cycle.push_back(current);
        current = (current * lastDigit) % 10;
    } while (current != lastDigit);

    // Xác định vị trí trong chu kỳ
    int cycleLength = cycle.size();
    int position = (Q - 1) % cycleLength; // Q-1 vì chu kỳ bắt đầu từ 0

    // Kết quả là phần tử tại vị trí `position` trong chu kỳ
    cout << cycle[position] << endl;

    return 0;
}
