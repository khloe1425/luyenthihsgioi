#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flower {
    long long a, b;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Flower> flowers(n);
    for (int i = 0; i < n; i++) {
        cin >> flowers[i].a >> flowers[i].b;
    }

    // Sắp xếp hoa theo độ vui vẻ tăng dần
    sort(flowers.begin(), flowers.end(), [](const Flower &f1, const Flower &f2) {
        return f1.b > f2.b; // Sắp xếp giảm dần theo b
    });

    long long maxHappiness = 0;
    for (const auto &flower : flowers) {
        // Mua một bông hoa này
        maxHappiness += flower.a; 
        // Nếu còn bông hoa, mua tối đa
        if (m > 1) {
            maxHappiness += (m - 1) * flower.b;
        }
        // Trừ số bông hoa đã mua
        m--;
        if (m <= 0) break;
    }

    cout << maxHappiness << endl;
    return 0;
}
