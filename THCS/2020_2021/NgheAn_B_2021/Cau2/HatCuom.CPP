// HATCUOM.CPP
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("HatCuom.Inp");
    ofstream output("HatCuom.Out");

    int N;
    string beads;

    // Đọc dữ liệu từ file
    input >> N >> beads;

    int countX = 0, countT = 0;

    // Đếm số lượng ký tự 'X' và 'T'
    for (char c : beads) {
        if (c == 'X') {
            countX++;
        } else if (c == 'T') {
            countT++;
        }
    }

    // Ghi chuỗi sắp xếp vào file
    for (int i = 0; i < countX; ++i) {
        output << 'X';
    }
    for (int i = 0; i < countT; ++i) {
        output << 'T';
    }
    output << endl;

    input.close();
    output.close();

    return 0;
}
