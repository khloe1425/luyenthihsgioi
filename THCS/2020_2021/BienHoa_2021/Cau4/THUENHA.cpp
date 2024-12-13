#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("THUENHA.INP");
    ofstream outputFile("THUENHA.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int N, M, K;
    inputFile >> N >> M >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> a[i];
    }
    inputFile.close();

    int minDistance = INT_MAX;
    int result = -1;

    for (int i = 0; i < N; ++i) {
        if (a[i] > 0 && a[i] <= K) {  // Tâm có đủ tiền thuê nhà này
            int distance = abs(i + 1 - M);  // Khoảng cách từ vị trí M đến nhà thứ i+1
            if (distance < minDistance) {
                minDistance = distance;
                result = distance * 10;  // Khoảng cách tính bằng 10 mét
            }
        }
    }

    outputFile << result << endl;
    outputFile.close();

    return 0;
}
