#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("BOI.INP");
    ofstream fout("BOI.OUT");

    long long P, N;
    fin >> P >> N;

    int count = 0;
    long long num = 9;  // Số chứa toàn chữ số 9 (khởi đầu là 9)

    for (int i = 1; i <= N; ++i) {
        if (num % P == 0) {
            count++;
        }
        // Tạo số tiếp theo có toàn chữ số 9
        num = num * 10 + 9;  // Thêm một chữ số 9 vào cuối
    }

    fout << count << endl;

    fin.close();
    fout.close();

    return 0;
}
