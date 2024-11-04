#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("TONG.INP");
    ofstream outfile("TONG.OUT");
    
    // Đọc N và K
    int N, K;
    infile >> N >> K;

    vector<int> numbers(N);
    
    // Đọc dãy số
    for (int i = 0; i < N; i++) {
        infile >> numbers[i];
    }

    // Sắp xếp dãy số theo thứ tự giảm dần
    sort(numbers.begin(), numbers.end(), greater<int>());
    
    // Tính tổng K phần tử lớn nhất
    int largest_sum = 0;
    for (int i = 0; i < K; i++) {
        largest_sum += numbers[i];
    }

    outfile << largest_sum << endl;

    infile.close();
    outfile.close();

    return 0;
}
