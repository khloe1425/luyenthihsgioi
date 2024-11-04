#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tính số chỗ đỗ xe tối thiểu
int min_parking_spaces(vector<int>& arrival, vector<int>& departure, int n) {
    // Sắp xếp thời gian đến và rời bến
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int spaces_needed = 0;  // Số chỗ đỗ xe hiện tại
    int max_spaces = 0;     // Số chỗ đỗ tối đa
    int i = 0, j = 0;       // Chỉ số cho thời gian đến và đi

    // Duyệt qua các xe
    while (i < n && j < n) {
        if (arrival[i] < departure[j]) {
            // Nếu có xe đến trước khi xe rời đi, tăng số chỗ đỗ cần thiết
            spaces_needed++;
            max_spaces = max(max_spaces, spaces_needed);
            i++;
        } else {
            // Nếu có xe rời đi, giảm số chỗ đỗ cần thiết
            spaces_needed--;
            j++;
        }
    }

    return max_spaces;
}

int main() {
    ifstream infile("MINPLACES.INP");
    ofstream outfile("MINPLACES.OUT");

    int T;
    infile >> T;  // Đọc số bộ dữ liệu

    while (T--) {
        int N;
        infile >> N;  // Đọc số xe trong bộ dữ liệu

        vector<int> arrival(N), departure(N);

        // Đọc danh sách thời gian đến
        for (int i = 0; i < N; ++i) {
            infile >> arrival[i];
        }

        // Đọc danh sách thời gian rời bến
        for (int i = 0; i < N; ++i) {
            infile >> departure[i];
        }

        // Tính số chỗ đỗ xe tối thiểu
        int result = min_parking_spaces(arrival, departure, N);
        outfile << result << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
