#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("CAU03.INP");
    ofstream outfile("CAU03.OUT");

    int N;
    infile >> N; // Đọc số chiến binh

    vector<int> your_army(N);
    vector<int> enemy_army(N);

    // Đọc sức mạnh của quân đội bạn
    for (int i = 0; i < N; ++i) {
        infile >> your_army[i];
    }

    // Đọc sức mạnh của quân đội đối phương
    for (int i = 0; i < N; ++i) {
        infile >> enemy_army[i];
    }

    // Sắp xếp sức mạnh của cả hai đội quân
    sort(your_army.begin(), your_army.end());
    sort(enemy_army.begin(), enemy_army.end());

    // Kiểm tra điều kiện thắng
    bool can_win = true;
    for (int i = 0; i < N; ++i) {
        if (your_army[i] <= enemy_army[i]) {
            can_win = false;
            break;
        }
    }

    // Ghi kết quả ra tệp
    if (can_win) {
        outfile << "Yes" << endl;
    } else {
        outfile << "No" << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
