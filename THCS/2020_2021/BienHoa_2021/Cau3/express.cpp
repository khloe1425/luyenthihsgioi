#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("EXPRESS.INP");
    ofstream outputFile("EXPRESS.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string code;
    inputFile >> code;
    inputFile.close();

    // Tính tổng các chữ số của mã số
    int sumDigits = 0;
    for (char c : code) {
        sumDigits += (c - '0');
    }

    // Tính khối lượng bưu phẩm
    int weight = sumDigits * 1000;

    // Tính giá vận chuyển
    double costPerKg = 0;
    if (weight <= 1000) {
        costPerKg = 6500;
    } else if (weight <= 2500) {
        costPerKg = 8000;
    } else if (weight <= 5000) {
        costPerKg = 12000;
    } else {
        costPerKg = 19000;
    }

    // Tính tổng chi phí vận chuyển (khối lượng * giá mỗi kg)
    double totalCost = costPerKg * (weight / 1000.0);

    // Thêm 10% VAT
    totalCost += totalCost * 0.1;

    // Ghi kết quả ra file
    outputFile << weight << endl;
    outputFile << fixed << setprecision(2) << totalCost << endl;
    outputFile.close();

    return 0;
}
