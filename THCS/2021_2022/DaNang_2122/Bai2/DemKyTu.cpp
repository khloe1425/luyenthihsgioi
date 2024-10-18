#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cout << "Nhập xâu ký tự S: ";
    getline(cin, S);  // Nhập toàn bộ chuỗi ký tự, bao gồm khoảng trắng

    int countA = 0;
    // Duyệt qua từng ký tự trong chuỗi
    for (char c : S) {
        if (c == 'A') {
            countA++;
        }
    }

    // In kết quả
    cout << "Số lượng ký tự 'A' trong xâu S là: " << countA << endl;
    return 0;
}
