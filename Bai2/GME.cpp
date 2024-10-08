#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input_path = "GME.INP";
    string output_path = "GME.OUT";

    ifstream input_file(input_path);
    if (!input_file) {
        cerr << "Không thể mở file " << input_path << endl;
        return 1;
    }

    int n;
    input_file >> n; 
    vector<int> menhGia(n);

    for (int i = 0; i < n; ++i) {
        input_file >> menhGia[i];
    }
    input_file.close(); 

    sort(menhGia.begin(), menhGia.end());

    long long tongSoTien = 0;
    for (int i = 0; i < n; ++i) {
        tongSoTien += menhGia[i];
    }

    ofstream output_file(output_path);
    if (!output_file) {
        cerr << "Không thể mở file " << output_path << endl;
        return 1;
    }

    output_file << "- Tien sau khi sap xep: ";
    for (int i = 0; i < n; ++i) {
        output_file << menhGia[i] << (i < n - 1 ? " " : "\n");
    }
    output_file << "- Menh gia thap nhat: " << menhGia[0] << " (dong); Menh gia cao nhat: " << menhGia[n - 1] << " (dong)\n";
    output_file << "- Tong so tien thu duoc: " << tongSoTien << " (dong)\n";
    
    output_file.close(); 

    return 0;
}
