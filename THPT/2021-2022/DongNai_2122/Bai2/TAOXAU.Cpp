#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

// Hàm chuẩn hóa chuỗi: loại bỏ khoảng trắng, dấu câu và chuyển chữ thường
string normalize(const string& s) {
    string result;
    for (char c : s) {
        if (isalnum(c)) { // Giữ lại chỉ ký tự chữ cái và số
            result += tolower(c);
        }
    }
    return result;
}

// Kiểm tra xem có thể tạo S1 từ S2 không
bool canCreateString(const string& S1, const string& S2) {
    vector<int> freq(26, 0);

    // Đếm tần suất ký tự trong S2
    for (char c : S2) {
        if (isalpha(c)) { // Chỉ xét chữ cái
            freq[c - 'a']++;
        }
    }

    // Kiểm tra tần suất ký tự trong S1
    for (char c : S1) {
        if (isalpha(c)) {
            if (freq[c - 'a'] <= 0) {
                return false; // Không đủ ký tự
            }
            freq[c - 'a']--;
        }
    }

    return true;
}

int main() {
    ifstream infile("TAOXAU.INP");
    ofstream outfile("TAOXAU.OUT");

    string S1, S2;
    getline(infile, S1);
    getline(infile, S2);

    // Chuẩn hóa chuỗi
    S1 = normalize(S1);
    S2 = normalize(S2);

    // Kiểm tra và ghi kết quả
    if (canCreateString(S1, S2)) {
        outfile << 1 << endl;
    } else {
        outfile << 0 << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
