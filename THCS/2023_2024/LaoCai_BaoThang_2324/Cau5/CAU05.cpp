#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(const vector<int>& arr) {
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    ifstream input("CAU05.INP");
    ofstream output("CAU05.OUT");

    int N;
    input >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        input >> arr[i];
    }

    int result = maxSubarraySum(arr);

    output << result << endl;

    input.close();
    output.close();

    return 0;
}
