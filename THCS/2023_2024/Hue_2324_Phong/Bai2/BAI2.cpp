#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ifstream infile("CHECK.INP");
    ofstream outfile1("CHECK1.OUT");
    ofstream outfile2("CHECK2.OUT");

    int N;
    infile >> N;
    infile.ignore();  // Bỏ qua ký tự newline sau số N

    for (int i = 1; i <= N; ++i) {
        string line;
        getline(infile, line);

        stringstream ss(line);
        vector<double> weights;
        double weight;
        double totalWeight = 0;
        int itemCount = 0;

        // Tính tổng trọng lượng và số lượng kiện hàng
        while (ss >> weight) {
            totalWeight += weight;
            itemCount++;
        }

        // Ghi tổng số cân nặng của hành khách vào file CHECK1.OUT
        outfile1 << totalWeight << endl;

        // Kiểm tra nếu hành khách không đủ điều kiện
        if (totalWeight > 20 || itemCount > 10) {
            outfile2 << i << endl;
        }
    }

    infile.close();
    outfile1.close();
    outfile2.close();
    return 0;
}
