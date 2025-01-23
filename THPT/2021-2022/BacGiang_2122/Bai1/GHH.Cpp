#include <iostream>
#include <vector>
using namespace std;

// Hàm tính tổng các ước số của một số
int sumOfDivisors(int x) {
    int sum = 0;
    for (int i = 1; i <= x / 2; ++i) {
        if (x % i == 0) {
            sum += i;
        }
    }
    sum += x; // Thêm chính số đó
    return sum;
}

int main() {
    // Đọc dữ liệu từ file
    freopen("GHH.INP", "r", stdin);
    freopen("GHH.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n; ++i) {
        int x = numbers[i];
        int T = sumOfDivisors(x);
        if (2 * x <= T) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;

    return 0;
}
