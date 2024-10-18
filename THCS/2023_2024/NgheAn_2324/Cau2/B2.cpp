#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Kiểm tra số chia hết cho 5
bool divisible_by_5(const string& number_str) {
    return stoi(number_str) % 5 == 0;
}

// Kiểm tra số chia hết cho 3
bool divisible_by_3(const string& number_str) {
    int sum = 0;
    for (char c : number_str) {
        sum += (c - '0');
    }
    return sum % 3 == 0;
}

int main() {
    ifstream infile("B2.INP");
    ofstream outfile("B2.OUT");

    int t;
    infile >> t;
    vector<string> results;

    for (int i = 0; i < t; ++i) {
        string number_str;
        int flag;
        infile >> number_str >> flag;

        string best_number = "-1";

        int n = number_str.size();

        for (int length = n; length > 0; --length) {
            // Tạo các chuỗi con với độ dài là 'length'
            for (int start = 0; start <= n - length; ++start) {
                string sub_number = number_str.substr(start, length);

                // Kiểm tra điều kiện
                if (flag == 0 && divisible_by_5(sub_number)) {
                    if (best_number == "-1" || stoll(sub_number) > stoll(best_number)) {
                        best_number = sub_number;
                    }
                } else if (flag == 1 && divisible_by_3(sub_number)) {
                    if (best_number == "-1" || stoll(sub_number) > stoll(best_number)) {
                        best_number = sub_number;
                    }
                }
            }
            if (best_number != "-1") {
                break;
            }
        }
        results.push_back(best_number);
    }

    for (const string& result : results) {
        outfile << result << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
