#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

int main() {
    ifstream infile("sokhop.inp");
    ofstream outfile("sokhop.out");

    int n, m;
    infile >> n >> m;

    int a[n], b[m];
    unordered_set<int> bSet;

    // Đọc dãy thứ nhất
    for (int i = 0; i < n; i++) {
        infile >> a[i];
    }

    // Đọc dãy thứ hai và đưa vào set
    for (int i = 0; i < m; i++) {
        infile >> b[i];
        bSet.insert(b[i]);
    }

    // Kiểm tra từng phần tử của dãy thứ nhất trong set
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (bSet.find(a[i]) != bSet.end()) {
            count++;
        }
    }

    // Ghi kết quả ra file
    outfile << count << endl;

    infile.close();
    outfile.close();

    return 0;
}