// WEIGHTLOSS.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAchieveDifficulty(const vector<int>& diffs, int K, int maxDiff) {
    int required = 0;
    for (int diff : diffs) {
        if (diff > maxDiff) {
            required += (diff - 1) / maxDiff;
        }
        if (required > K) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream input("WEIGHTLOSS.INP");
    ofstream output("WEIGHTLOSS.OUT");

    int N, K;
    input >> N >> K;
    vector<int> M(N);
    for (int i = 0; i < N; ++i) {
        input >> M[i];
    }

    // Tính các khoảng cách giữa các buổi tập
    vector<int> diffs;
    for (int i = 1; i < N; ++i) {
        diffs.push_back(M[i] - M[i - 1]);
    }

    // Tìm kiếm nhị phân trên độ khó nhỏ nhất
    int left = 1, right = *max_element(diffs.begin(), diffs.end()), result = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canAchieveDifficulty(diffs, K, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    output << result << endl;

    input.close();
    output.close();

    return 0;
}
