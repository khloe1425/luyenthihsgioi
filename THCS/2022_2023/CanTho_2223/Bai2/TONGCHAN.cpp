#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Khai báo biến
    int n;
    long long ai;
    int even_count = 0, odd_count = 0;

    // Đọc dữ liệu từ file TONGCHAN.INP
    ifstream fin("TONGCHAN.INP");
    fin >> n;

    // Đếm số lượng phần tử chẵn và lẻ
    for (int i = 0; i < n; i++) {
        fin >> ai;
        if (ai % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    fin.close();

    // Kết quả là số lượng phần tử nhỏ hơn giữa chẵn và lẻ
    int result = min(even_count, odd_count);

    // Ghi kết quả ra file TONGCHAN.OUT
    ofstream fout("TONGCHAN.OUT");
    fout << result;
    fout.close();

    return 0;
}
