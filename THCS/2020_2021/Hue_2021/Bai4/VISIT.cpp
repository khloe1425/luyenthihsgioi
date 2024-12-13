// VISIT.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("VISIT.INP");
    ofstream output("VISIT.OUT");

    int m, n;
    input >> m >> n;

    vector<vector<int>> students(m, vector<int>(n));
    vector<int> total_students;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> students[i][j];
            total_students.push_back(students[i][j]);
        }
    }

    int total = accumulate(total_students.begin(), total_students.end(), 0);
    int half = total / 2;
    vector<vector<bool>> dp(total_students.size() + 1, vector<bool>(half + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= total_students.size(); ++i) {
        for (int j = 0; j <= half; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= total_students[i - 1] && dp[i - 1][j - total_students[i - 1]]) {
                dp[i][j] = true;
            }
        }
    }

    int best = 0;
    for (int j = half; j >= 0; --j) {
        if (dp[total_students.size()][j]) {
            best = j;
            break;
        }
    }

    vector<int> allocation(total_students.size(), 0);
    int remaining = best;
    for (int i = total_students.size(); i > 0; --i) {
        if (remaining >= total_students[i - 1] && dp[i - 1][remaining - total_students[i - 1]]) {
            allocation[i - 1] = 1;
            remaining -= total_students[i - 1];
        }
    }

    int total_first_bus = 0, total_second_bus = 0;
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (allocation[idx] == 1) {
                output << "1 ";
                total_first_bus += students[i][j];
            } else {
                output << "0 ";
                total_second_bus += students[i][j];
            }
            idx++;
        }
        output << endl;
    }

    output << total_first_bus << " " << total_second_bus << endl;

    input.close();
    output.close();

    return 0;
}
