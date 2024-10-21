#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("B4.INP");
    ofstream outfile("B4.OUT");

    int k;
    infile >> k;

    string firstRow, secondRow;
    infile >> firstRow;

    if (k == 2) {
        infile >> secondRow;
    }

    int totalTubes = firstRow.length() + (k == 2 ? secondRow.length() : 0);
    int score = 1000000; // Tổng số thẻ bài

    // Biến đánh dấu các ống đã được sử dụng
    vector<bool> used(totalTubes, false);
    int usedCount = 0;

    // Duyệt qua các thẻ bài từ 1 đến 1.000.000
    for (int i = 1; i <= 1000000; i++) {
        char color = ' ';

        // Chọn màu dựa vào số chẵn hoặc lẻ
        if (i % 2 == 0) { // Số chẵn -> ống xanh
            for (int j = 0; j < firstRow.size(); j++) {
                if (firstRow[j] == 'B' && !used[j]) {
                    used[j] = true;
                    usedCount++;
                    break;
                }
            }
            // Nếu có hàng thứ hai
            if (k == 2) {
                for (int j = 0; j < secondRow.size(); j++) {
                    if (secondRow[j] == 'B' && !used[j + firstRow.size()]) {
                        used[j + firstRow.size()] = true;
                        usedCount++;
                        break;
                    }
                }
            }
        } else { // Số lẻ -> ống đỏ
            for (int j = 0; j < firstRow.size(); j++) {
                if (firstRow[j] == 'R' && !used[j]) {
                    used[j] = true;
                    usedCount++;
                    break;
                }
            }
            // Nếu có hàng thứ hai
            if (k == 2) {
                for (int j = 0; j < secondRow.size(); j++) {
                    if (secondRow[j] == 'R' && !used[j + firstRow.size()]) {
                        used[j + firstRow.size()] = true;
                        usedCount++;
                        break;
                    }
                }
            }
        }
    }

    // Tính điểm cuối cùng
    score -= usedCount;
    outfile << score << endl;

    infile.close();
    outfile.close();
    
    return 0;
}
