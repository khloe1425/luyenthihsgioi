#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

int countZeroSumSubarrays(const vector<int>& arr) {
    unordered_map<int, int> prefixSumCounts;
    prefixSumCounts[0] = 1; // Để xử lý trường hợp tổng bằng 0 từ đầu dãy
    int currentSum = 0;
    int count = 0;

    for (int number : arr) {
        currentSum += number;
        // Nếu tổng đã xuất hiện trước đó, nghĩa là có đoạn con tổng bằng 0
        if (prefixSumCounts.find(currentSum) != prefixSumCounts.end()) {
            count += prefixSumCounts[currentSum];
            prefixSumCounts[currentSum]++;
        } else {
            prefixSumCounts[currentSum] = 1;
        }
    }

    return count;
}

int main() {
    ifstream infile("TONG.INP");
    ofstream outfile("TONG.OUT");

    int n;
    infile >> n; // Đọc số phần tử

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        infile >> arr[i]; // Đọc các phần tử của dãy
    }

    // Tính số đoạn con có tổng bằng 0
    int result = countZeroSumSubarrays(arr);

    // Ghi kết quả vào file
    outfile << result << endl;

    infile.close();
    outfile.close();
    
    return 0;
}
