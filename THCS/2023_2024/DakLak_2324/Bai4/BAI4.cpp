#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Để sử dụng hằng số INT_MAX

using namespace std;

// Hàm tính tổng lượng thu hoạch khi chọn ngưỡng K
int total_harvest(int K, const vector<int>& a) {
    int total = 0;
    for (int ai : a) {
        if (ai > K) {
            total += (ai - K);
        }
    }
    return total;
}

// Hàm tìm K tối ưu để đạt hoặc vượt qua mục tiêu thu hoạch S
int find_optimal_K(int S, const vector<int>& a) {
    int low = 0, high = *max_element(a.begin(), a.end());
    int best_K = low;
    int min_excess = INT_MAX; // Khởi tạo dư thừa lớn nhất có thể

    for (int i = low; i <= high; ++i) {
        int current_total = total_harvest(i, a);
        if (current_total >= S) {
            int excess = current_total - S;
            if (excess < min_excess) {
                min_excess = excess;
                best_K = i;
            }
        }
    }
    return best_K;
}

int main() {
    int N, S;
    cin >> N >> S;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int result = find_optimal_K(S, a);
    cout << "Optimal K: " << result << endl;

    return 0;
}
