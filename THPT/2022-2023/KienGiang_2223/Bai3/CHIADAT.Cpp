#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Hàm đệ quy để phân chia đất
void divideLand(int index, const vector<int>& land, vector<int>& sums, string& currentDivision, vector<string>& results, int targetSum) {
    // Nếu đã phân chia hết các thửa đất
    if (index == land.size()) {
        // Kiểm tra nếu tất cả các nhóm có diện tích bằng nhau
        if (sums[0] == targetSum && sums[1] == targetSum && sums[2] == targetSum) {
            results.push_back(currentDivision);
        }
        return;
    }

    // Thêm thửa đất hiện tại vào nhóm A
    if (sums[0] + land[index] <= targetSum) {
        sums[0] += land[index];
        currentDivision[index] = 'A';
        divideLand(index + 1, land, sums, currentDivision, results, targetSum);
        sums[0] -= land[index]; // Quay lui
    }

    // Thêm thửa đất hiện tại vào nhóm B
    if (sums[1] + land[index] <= targetSum) {
        sums[1] += land[index];
        currentDivision[index] = 'B';
        divideLand(index + 1, land, sums, currentDivision, results, targetSum);
        sums[1] -= land[index]; // Quay lui
    }

    // Thêm thửa đất hiện tại vào nhóm C
    if (sums[2] + land[index] <= targetSum) {
        sums[2] += land[index];
        currentDivision[index] = 'C';
        divideLand(index + 1, land, sums, currentDivision, results, targetSum);
        sums[2] -= land[index]; // Quay lui
    }
}

int main() {
    ifstream inputFile("CHIADAT.INP");
    ofstream outputFile("CHIADAT.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N; // Số lượng thửa đất
    inputFile >> N;

    vector<int> land(N); // Diện tích các thửa đất
    int totalSum = 0;
    for (int i = 0; i < N; ++i) {
        inputFile >> land[i];
        totalSum += land[i];
    }

    // Nếu không thể chia đều, ghi -1 ra file
    if (totalSum % 3 != 0) {
        outputFile << -1 << endl;
        return 0;
    }

    int targetSum = totalSum / 3; // Tổng diện tích mỗi nhóm
    vector<int> sums(3, 0); // Diện tích của 3 nhóm
    string currentDivision(N, 'A'); // Cách chia hiện tại
    vector<string> results; // Lưu các cách chia hợp lệ

    // Bắt đầu phân chia đất
    divideLand(0, land, sums, currentDivision, results, targetSum);

    // Ghi kết quả
    if (results.empty()) {
        outputFile << -1 << endl;
    } else {
        outputFile << results.size() << endl;
        for (const string& division : results) {
            outputFile << division << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
