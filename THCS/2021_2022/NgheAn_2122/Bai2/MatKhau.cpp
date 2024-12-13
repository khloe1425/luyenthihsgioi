#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ifstream input("MatKhau.INP");
    ofstream output("MatKhau.OUT");

    int n;
    input >> n;
    string password = "";

    for (int i = 0; i < n; i++) {
        string s;
        input >> s;

        // Đếm số lần xuất hiện của từng ký tự
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Tìm ký tự xuất hiện đúng 1 lần
        for (char c : s) {
            if (freq[c] == 1) {
                password += c;
                break; // Lấy ký tự đầu tiên thỏa mãn
            }
        }
    }

    output << password << endl;

    input.close();
    output.close();

    return 0;
}
