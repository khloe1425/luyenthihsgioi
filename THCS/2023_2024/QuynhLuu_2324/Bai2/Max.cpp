#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

// Hàm tìm số lớn nhất sau khi loại bỏ các chữ số
string find_max_number(const string& number, int remove_count) {
    stack<char> s;
    int to_remove = remove_count;

    for (char digit : number) {
        while (!s.empty() && to_remove > 0 && s.top() < digit) {
            s.pop();
            to_remove--;
        }
        s.push(digit);
    }

    // Nếu còn chữ số cần loại bỏ thì loại bỏ từ cuối
    while (to_remove > 0 && !s.empty()) {
        s.pop();
        to_remove--;
    }

    string result;
    // Chuyển stack thành chuỗi
    while (!s.empty()) {
        result = s.top() + result; // Đặt lại thứ tự từ trên xuống
        s.pop();
    }

    return result;
}

int main() {
    // Đọc dữ liệu từ file Max.INP
    ifstream infile("Max.INP");
    int n, k;
    string number;

    infile >> n >> k;
    infile >> number;
    infile.close();

    // Tìm số lớn nhất
    string result = find_max_number(number, k);

    // Ghi kết quả ra file Max.OUT
    ofstream outfile("Max.OUT");
    outfile << result << endl;
    outfile.close();

    return 0;
}
