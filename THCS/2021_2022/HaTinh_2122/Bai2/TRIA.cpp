#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm đếm số tam giác cân và đều
int countTriangles(const vector<int>& a) {
    int n = a.size();
    int count = 0;

    // Đếm tam giác đều (x, x, x)
    for (int i = 0; i < n - 2; i++) {
        if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
            count++; // Tam giác đều
        }
    }

    // Đếm tam giác cân (x, x, y) hoặc (x, y, y)
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (a[i] == a[j]) { // Tam giác dạng (x, x, y)
                for (int k = j + 1; k < n; k++) {
                    if (a[j] + a[i] > a[k]) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    ifstream input("TRIA.INP");
    ofstream output("TRIA.OUT");

    int n;
    input >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }

    // Sắp xếp mảng
    sort(a.begin(), a.end());

    // Đếm tam giác
    int result = countTriangles(a);

    // Ghi kết quả
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
