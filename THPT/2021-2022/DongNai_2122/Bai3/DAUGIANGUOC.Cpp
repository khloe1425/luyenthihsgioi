#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("DAUGIANGUOC.INP");
    ofstream outfile("DAUGIANGUOC.OUT");

    int N;
    infile >> N;

    vector<int> bids(N);
    for (int i = 0; i < N; i++) {
        infile >> bids[i];
    }

    // Tìm giá trị nhỏ nhất và duy nhất
    const int MAX_VALUE = 10000; // Giá trị lớn nhất theo đề bài
    vector<int> frequency(MAX_VALUE + 1, 0);

    // Đếm tần suất xuất hiện của các giá trị
    for (int bid : bids) {
        frequency[bid]++;
    }

    // Tìm giá trị nhỏ nhất có tần suất là 1
    int result = -1;
    for (int i = 1; i <= MAX_VALUE; i++) {
        if (frequency[i] == 1) {
            result = i;
            break;
        }
    }

    // Ghi kết quả
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
