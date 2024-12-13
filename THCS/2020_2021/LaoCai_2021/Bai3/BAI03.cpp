#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("BAI03.INP");
    ofstream outputFile("BAI03.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int N;
    inputFile >> N;
    vector<int> lengths(N);

    for (int i = 0; i < N; i++) {
        inputFile >> lengths[i];
    }

    // Sắp xếp độ dài giảm dần
    sort(lengths.rbegin(), lengths.rend());

    int maxSquareSize = 0;

    for (int k = 1; k <= N; k++) {
        // Kiểm tra nếu có ít nhất k tấm có độ dài >= k
        if (lengths[k - 1] >= k) {
            maxSquareSize = k;
        } else {
            break;
        }
    }

    outputFile << maxSquareSize << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
