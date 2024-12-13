#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("WOOD.INP");
    ofstream outputFile("WOOD.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int prev2 = 0, prev1 = 0, current = 0;

    for (int i = 1; i <= n; i++) {
        int a;
        inputFile >> a;
        current = max(prev1, prev2 + a);
        prev2 = prev1;
        prev1 = current;
    }

    outputFile << current << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
