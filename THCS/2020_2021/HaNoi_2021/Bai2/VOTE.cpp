#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("VOTE.INP");
    ofstream outputFile("VOTE.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    vector<int> votes(N, 0); // Mảng lưu số phiếu của mỗi nhân viên

    // Đọc dữ liệu và đếm số phiếu
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char vote;
            inputFile >> vote;
            if (vote == 'X') {
                votes[j]++;
            }
        }
    }

    // Tìm số phiếu bầu cao nhất
    int maxVotes = *max_element(votes.begin(), votes.end());

    // Tìm danh sách nhân viên có số phiếu bầu cao nhất
    vector<int> topEmployees;
    for (int i = 0; i < N; i++) {
        if (votes[i] == maxVotes) {
            topEmployees.push_back(i + 1); // Chuyển từ chỉ số sang thứ tự
        }
    }

    // Ghi kết quả ra file
outputFile << maxVotes << "\n";
for (size_t i = 0; i < topEmployees.size(); i++) {
    if (i > 0) outputFile << " ";
    outputFile << topEmployees[i];
}
outputFile << "\n";


    inputFile.close();
    outputFile.close();

    return 0;
}
