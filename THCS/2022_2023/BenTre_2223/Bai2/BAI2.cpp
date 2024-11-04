#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

bool canDivideIntoGroups(int n, const vector<vector<int>>& acquaintanceMatrix, vector<int>& group) {
    for (int person = 0; person < n; ++person) {
        if (group[person] == -1) {  // Nếu chưa được phân nhóm
            queue<int> q;
            q.push(person);
            group[person] = 0;  // Gán nhóm 0

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                int nextGroup = 1 - group[current];  // Chuyển sang nhóm khác

                for (int acquaintance = 0; acquaintance < n; ++acquaintance) {
                    if (acquaintanceMatrix[current][acquaintance] == 1) { // Nếu là quen biết
                        if (group[acquaintance] == -1) { // Chưa phân nhóm
                            group[acquaintance] = nextGroup;
                            q.push(acquaintance);
                        } else if (group[acquaintance] == group[current]) { // Cùng nhóm
                            return false; // Không thể chia nhóm
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ifstream infile("CHIANHOM.INP");
    ofstream outfile("CHIANHOM.OUT");

    int n;
    infile >> n;

    vector<vector<int>> acquaintanceMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> acquaintanceMatrix[i][j];
        }
    }

    vector<int> group(n, -1); // -1: chưa phân nhóm, 0: nhóm 1, 1: nhóm 2
    if (!canDivideIntoGroups(n, acquaintanceMatrix, group)) {
        outfile << "0\n"; // Không thể chia nhóm
    } else {
        vector<int> group1, group2;
        for (int i = 0; i < n; ++i) {
            if (group[i] == 0) {
                group1.push_back(i + 1); // Thêm vào nhóm 1 (bắt đầu từ 1)
            } else {
                group2.push_back(i + 1); // Thêm vào nhóm 2
            }
        }
        for (int person : group1) {
            outfile << person << " ";
        }
        outfile << "\n";
        for (int person : group2) {
            outfile << person << " ";
        }
        outfile << "\n";
    }

    infile.close();
    outfile.close();
    return 0;
}
