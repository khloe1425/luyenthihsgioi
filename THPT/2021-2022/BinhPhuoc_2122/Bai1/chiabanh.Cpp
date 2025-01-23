#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("chiabanh.inp");
    ofstream outfile("chiabanh.out");

    long long N;
    infile >> N;

    vector<pair<long long, long long>> results;

    // Tìm tất cả các ước của N
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            results.push_back({i, N / i});  // Cặp (i, N/i)
            if (i != N / i) {  // Tránh lặp lại nếu i * i == N
                results.push_back({N / i, i});  // Cặp (N/i, i)
            }
        }
    }

    // Sắp xếp các cặp để đảm bảo thứ tự tăng dần
    sort(results.begin(), results.end());

    // Ghi kết quả ra file
    for (auto &pair : results) {
        outfile << pair.first << " " << pair.second << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
