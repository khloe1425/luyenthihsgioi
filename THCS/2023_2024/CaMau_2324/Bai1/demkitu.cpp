#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void count_characters(const string& input_file, const string& output_file) {
    ifstream input(input_file);
    ofstream output(output_file);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Cannot open file!" << endl;
        return;
    }

    string S;
    getline(input, S);  // Đọc xâu S

    vector<int> count(26, 0);  // Mảng đếm ký tự

    // Đếm số lần xuất hiện của các ký tự
    for (char charac : S) {
        count[charac - 'a']++;
    }

    // Ghi kết quả vào tệp tin
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            output << char(i + 'a') << " " << count[i] << endl;  // Ghi ký tự và số lần xuất hiện
        }
    }

    input.close();
    output.close();
}

int main() {
    count_characters("demkitu.inp", "demkitu.out");
    return 0;
}
