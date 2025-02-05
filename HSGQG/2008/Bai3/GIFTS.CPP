#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm tính chỉ số của một ô sau khi cắt bánh
int getFinalIndex(int k, int row, int col) {
    int index = 0;
    for (int i = k - 1; i >= 0; i--) {
        int mask = 1 << i;
        index *= 2;
        if (row & mask) index++;
        index *= 2;
        if (col & mask) index++;
    }
    return index + 1; // Thứ tự tính từ 1
}

int main() {
    ifstream fin("GIFTS.INP");
    ofstream fout("GIFTS.OUT");
    
    int k, p, q, u, v;
    fin >> k >> p >> q >> u >> v;
    fin.close();
    
    int index1 = getFinalIndex(k, p, q);
    int index2 = getFinalIndex(k, u, v);
    
    fout << index1 << " " << index2 << endl;
    fout.close();
    
    return 0;
}
