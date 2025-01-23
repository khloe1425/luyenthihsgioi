#include <bits/stdc++.h>
using namespace std;

// Hàm chuẩn hóa từ: loại bỏ ký tự lặp liên tiếp
string normalize(const string &word) {
    string result;
    for (char c : word) {
        if (result.empty() || c != result.back()) {
            result += c;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI2.INP");
    ofstream fout("BAI2.OUT");

    string line1, line2;
    getline(fin, line1); // Đọc lần gõ đầu tiên
    getline(fin, line2); // Đọc lần gõ thứ hai

    // Tách các từ trong hai xâu
    stringstream ss1(line1), ss2(line2);
    vector<string> words1, words2;
    string word;

    while (ss1 >> word) words1.push_back(word);
    while (ss2 >> word) words2.push_back(word);

    // So sánh từng từ
    int count = 0;
    for (size_t i = 0; i < words1.size(); ++i) {
        if (normalize(words1[i]) == words2[i]) {
            count++;
        }
    }

    fout << count << "\n";

    fin.close();
    fout.close();
    return 0;
}
