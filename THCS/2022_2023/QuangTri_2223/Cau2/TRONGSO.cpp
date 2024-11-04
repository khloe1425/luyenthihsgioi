#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

double calculate_weight(const string &s) {
    int sum = 0;
    int count = 0;

    // Tính tổng các chữ số và đếm số chữ số
    for (char ch : s) {
        if (isdigit(ch)) {
            sum += ch - '0'; // Chuyển đổi ký tự sang số
            count++;
        }
    }
    
    // Tính trung bình cộng
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}

int main() {
    ifstream infile("TRONGSO.INP");
    ofstream outfile("TRONGSO.OUT");
    
    int N;
    infile >> N; // Đọc số lượng xâu
    infile.ignore(); // Bỏ qua ký tự newline còn lại trong buffer

    string result_string = "0";
    double max_weight = -1.0;

    for (int i = 0; i < N; ++i) {
        string s;
        getline(infile, s); // Đọc xâu

        double weight = calculate_weight(s);
        if (weight > max_weight) {
            max_weight = weight;
            result_string = s;
        }
    }

    outfile << result_string << endl;

    infile.close();
    outfile.close();
    
    return 0;
}
