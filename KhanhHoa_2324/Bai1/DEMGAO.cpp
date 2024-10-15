#include <iostream>
#include <fstream>

using namespace std;

int main() {
    long long a, b, k;
    ifstream input("DEMGAO.INP");
    ofstream output("DEMGAO.OUT");

    input >> a >> b >> k;

    // Tìm bội số đầu tiên của k lớn hơn hoặc bằng a
    long long first_multiple = ((a + k - 1) / k) * k;

    // Tìm bội số cuối cùng của k nhỏ hơn hoặc bằng b
    long long last_multiple = (b / k) * k;

    // Kiểm tra nếu không có bội số nào thỏa mãn
    if (first_multiple > b || last_multiple < a) {
        output << 0 << endl;
    } else {
        // Đếm số lượng bội số
        long long count = (last_multiple - first_multiple) / k + 1;
        output << count << endl;
    }

    input.close();
    output.close();
    return 0;
}