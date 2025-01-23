#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits.h> // Để sử dụng INT_MIN
using namespace std;

struct Bid {
    string name;
    int value;
};

int main() {
    ifstream inputFile("DAUTHAU.INP");
    ofstream outputFile("DAUTHAU.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    vector<Bid> bids(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> bids[i].name >> bids[i].value;
    }

    // Tìm người chiến thắng
    string winner;
    int maxBid = INT_MIN; // Giá trị lớn nhất
    int earliestIndex = -1; // Chỉ số sớm nhất của giá thầu lớn nhất

    for (int i = 0; i < N; ++i) {
        if (bids[i].value > maxBid || (bids[i].value == maxBid && i < earliestIndex)) {
            maxBid = bids[i].value;
            winner = bids[i].name;
            earliestIndex = i;
        }
    }

    outputFile << winner << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
