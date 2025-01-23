#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate minimum time to serve all customers
int calculateMinimumTime(int N, const vector<tuple<int, int, int>>& times) {
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        // Option 1: Serve one person
        dp[i] = min(dp[i], dp[i - 1] + get<0>(times[i - 1]));

        // Option 2: Serve two consecutive people
        if (i > 1) {
            dp[i] = min(dp[i], dp[i - 2] + get<1>(times[i - 2]));
        }

        // Option 3: Serve three consecutive people
        if (i > 2) {
            dp[i] = min(dp[i], dp[i - 3] + get<2>(times[i - 3]));
        }
    }

    return dp[N];
}

int main() {
    ifstream input("MUAVE.INP");
    ofstream output("MUAVE.OUT");

    int N;
    input >> N;

    vector<tuple<int, int, int>> times(N);
    for (int i = 0; i < N; ++i) {
        int A, B, C;
        input >> A >> B >> C;
        times[i] = make_tuple(A, B, C);
    }

    int result = calculateMinimumTime(N, times);

    output << result << endl;

    input.close();
    output.close();
    return 0;
}
