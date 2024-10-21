#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

// Hàm chuyển đổi ký tự thành số
string convertToNumbers(const string& input) {
    unordered_map<char, char> mapping;
    // Ánh xạ chữ cái đến số
    mapping['A'] = '2'; mapping['B'] = '2'; mapping['C'] = '2';
    mapping['a'] = '2'; mapping['b'] = '2'; mapping['c'] = '2';
    mapping['D'] = '3'; mapping['E'] = '3'; mapping['F'] = '3';
    mapping['d'] = '3'; mapping['e'] = '3'; mapping['f'] = '3';
    mapping['G'] = '4'; mapping['H'] = '4'; mapping['I'] = '4';
    mapping['g'] = '4'; mapping['h'] = '4'; mapping['i'] = '4';
    mapping['J'] = '5'; mapping['K'] = '5'; mapping['L'] = '5';
    mapping['j'] = '5'; mapping['k'] = '5'; mapping['l'] = '5';
    mapping['M'] = '6'; mapping['N'] = '6'; mapping['O'] = '6';
    mapping['m'] = '6'; mapping['n'] = '6'; mapping['o'] = '6';
    mapping['P'] = '7'; mapping['Q'] = '7'; mapping['R'] = '7'; mapping['S'] = '7';
    mapping['p'] = '7'; mapping['q'] = '7'; mapping['r'] = '7'; mapping['s'] = '7';
    mapping['T'] = '8'; mapping['U'] = '8'; mapping['V'] = '8';
    mapping['t'] = '8'; mapping['u'] = '8'; mapping['v'] = '8';
    mapping['W'] = '9'; mapping['X'] = '9'; mapping['Y'] = '9'; mapping['Z'] = '9';
    mapping['w'] = '9'; mapping['x'] = '9'; mapping['y'] = '9'; mapping['z'] = '9';

    string result;
    for (char ch : input) {
        result += mapping[ch];  // Chuyển đổi ký tự
    }
    return result;
}

// Hàm kiểm tra xem chuỗi có phải là thuận nghịch hay không
bool isPalindrome(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;  // Không phải thuận nghịch
        }
        left++;
        right--;
    }
    return true;  // Là thuận nghịch
}

int main() {
    // Đọc dữ liệu từ file TNGH.INP
    ifstream infile("TNGH.INP");
    string input;
    getline(infile, input);
    infile.close();

    // Chuyển đổi ký tự thành dãy số
    string numberString = convertToNumbers(input);

    // Kiểm tra xem dãy số có phải là thuận nghịch hay không
    int result = isPalindrome(numberString) ? 1 : 0;

    // Ghi kết quả vào file TNGH.OUT
    ofstream outfile("TNGH.OUT");
    outfile << result << endl;
    outfile.close();

    return 0;
}
