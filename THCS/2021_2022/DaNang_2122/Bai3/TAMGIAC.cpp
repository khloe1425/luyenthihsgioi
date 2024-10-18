#include <iostream>
#include <fstream>
#include <cmath> // Thư viện toán học để sử dụng hàm abs (giá trị tuyệt đối)
using namespace std;

int main() {
    ifstream fin("TAMGIAC.INP");
    ofstream fout("TAMGIAC.OUT");

    int a, b;
    fin >> a >> b;

    // Tính khoảng giá trị của c
    int min_c = abs(a - b) + 1;  // c phải lớn hơn |a - b|
    int max_c = a + b - 1;       // c phải nhỏ hơn a + b

    // Số lượng các giá trị c thỏa mãn
    int count_c = 0;
    if (min_c <= max_c) {
        count_c = max_c - min_c + 1;
    }

    // Ghi kết quả ra file
    fout << count_c << endl;

    fin.close();
    fout.close();

    return 0;
}
