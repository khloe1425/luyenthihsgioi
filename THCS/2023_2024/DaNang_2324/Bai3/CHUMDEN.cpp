#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarraysWithKOdds(const vector<int>& arr, int n, int k) {
    // Tạo mảng binary: 1 nếu số lẻ, 0 nếu số chẵn
    vector<int> binary(n);
    for (int i = 0; i < n; i++) {
        binary[i] = (arr[i] % 2 != 0) ? 1 : 0;
    }

    // Hash map để đếm số lần xuất hiện của từng prefix sum
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // Giá trị khởi đầu của prefix sum

    int prefix_sum = 0;
    int result = 0;

    // Duyệt qua từng phần tử của mảng binary
    for (int i = 0; i < n; i++) {
        // Cập nhật prefix sum
        prefix_sum += binary[i];

        // Tìm xem có bao nhiêu prefix_sum trước đó có tổng là (prefix_sum - k)
        if (prefixSumCount.find(prefix_sum - k) != prefixSumCount.end()) {
            result += prefixSumCount[prefix_sum - k];
        }

        // Cập nhật số lần xuất hiện của prefix_sum hiện tại
        prefixSumCount[prefix_sum]++;
    }

    return result;
}

int main() {
    freopen("CHUMDEN.INP", "r", stdin);
    freopen("CHUMDEN.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countSubarraysWithKOdds(arr, n, k);

    cout << result << endl;

    return 0;
}
