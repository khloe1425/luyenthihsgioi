#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Mở file input và output
    ifstream input("FRIENDNUM.INP");
    ofstream output("FRIENDNUM.OUT");

    // Kiểm tra file
    if (!input || !output) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    // Đọc dữ liệu từ file input
    int n;
    input >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        input >> arr[i];
    }

    // Đếm số cặp số bạn bè
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % 3 == 0) {
                count++;
            }
        }
    }

    // Ghi kết quả vào file output
    output << count << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
