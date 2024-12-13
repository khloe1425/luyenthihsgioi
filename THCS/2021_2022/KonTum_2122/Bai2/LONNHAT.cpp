#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("LONNHAT.INP");
    ofstream output("LONNHAT.OUT");

    int n, m;
    input >> n >> m;

    int maxReward = 0;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = 0; j < m; j++) {
            int reward;
            input >> reward;
            currentSum += reward;
        }
        maxReward = max(maxReward, currentSum);
    }

    output << maxReward << endl;

    input.close();
    output.close();

    return 0;
}
