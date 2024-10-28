#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Hàm tính số ngày leo để đạt đến đỉnh
int calculateDays(int V, int A, int B) {
    if (A >= V) return 1; // Nếu A >= V thì chỉ cần 1 ngày để leo đến đỉnh
    return ceil((double)(V - A) / (A - B)) + 1;
}

int main() {
    ifstream inputFile("ATHORUA.INP");
    ofstream outputFile("ATHORUA.OUT");

    int V, A1, B1, A2, B2;
    inputFile >> V >> A1 >> B1 >> A2 >> B2;

    // Tính số ngày cho Thỏ và Rùa
    int daysTho = calculateDays(V, A1, B1);
    int daysRua = calculateDays(V, A2, B2);

    // Xác định kết quả
    if (daysTho < daysRua) {
        outputFile << "THO";
    } else if (daysTho > daysRua) {
        outputFile << "RUA";
    } else {
        outputFile << "HOA";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
