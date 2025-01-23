#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("sokhop.inp");
    ofstream output("sokhop.out");

    int n, m;
    input >> n >> m;

    set<int> b_set; // Tập hợp chứa các số trong dãy thứ hai

    // Đọc dãy thứ nhất
    int a[n];
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    // Đọc dãy thứ hai và đưa vào tập hợp
    for (int i = 0; i < m; ++i) {
        int b;
        input >> b;
        b_set.insert(b);
    }

    // Đếm số phần tử của dãy thứ nhất xuất hiện trong dãy thứ hai
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (b_set.find(a[i]) != b_set.end()) {
            count++;
        }
    }

    // Ghi kết quả ra file
    output << count << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
