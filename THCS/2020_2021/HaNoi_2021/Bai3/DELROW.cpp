#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// Hàm kiểm tra tính duy nhất của các cột
bool isUnique(const vector<string> &table, const vector<bool> &removedRows) {
    int M = table[0].size();
    set<string> columns; // Tập hợp lưu các cột
    for (int j = 0; j < M; j++) {
        string col = "";
        for (size_t i = 0; i < table.size(); i++) {
            if (!removedRows[i]) {
                col += table[i][j];
            }
        }
        if (columns.count(col)) {
            return false; // Nếu cột đã tồn tại, không duy nhất
        }
        columns.insert(col);
    }
    return true;
}

int main() {
    ifstream inputFile("DELROW.INP");
    ofstream outputFile("DELROW.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int N, M;
    inputFile >> N >> M;

    vector<string> table(N);
    for (int i = 0; i < N; i++) {
        inputFile >> table[i];
    }

    vector<bool> removedRows(N, false); // Dòng nào đã bị xóa
    int removedCount = 0;

    for (int i = 0; i < N; i++) {
        // Giả sử xóa dòng i
        removedRows[i] = true;
        if (isUnique(table, removedRows)) {
            // Nếu bảng vẫn thỏa mãn, giữ lại trạng thái xóa
            removedCount++;
        } else {
            // Nếu không thỏa mãn, khôi phục dòng i
            removedRows[i] = false;
        }
    }

    outputFile << removedCount << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
