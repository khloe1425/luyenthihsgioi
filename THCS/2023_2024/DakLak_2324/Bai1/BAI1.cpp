#include <iostream>
using namespace std;

long long S(int N) {
    return (static_cast<long long>(N) * (N + 1) * (2 * N + 7)) / 6;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << S(N) << endl;
    }
    return 0;
}
