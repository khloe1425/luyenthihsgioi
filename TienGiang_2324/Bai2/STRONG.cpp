#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int calculate_strength(const string &s) {
    unordered_map<char, int> count_map; // Từ điển để đếm số lần xuất hiện của từng ký tự

    // Đếm số lần xuất hiện của từng ký tự
    for (char c : s) {
        count_map[c]++;
    }

    int distinct_count = count_map.size(); // Số ký tự phân biệt
    int max_count = 0;

    // Tìm số lần xuất hiện nhiều nhất của một ký tự
    for (const auto &pair : count_map) {
        max_count = max(max_count, pair.second);
    }

    // Tính độ mạnh
    return distinct_count * max_count;
}

int main() {
    ifstream input_file("STRONG.INP");
    ofstream output_file("STRONG.OUT");

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string s;
    getline(input_file, s); // Đọc xâu từ tệp

    int strength = calculate_strength(s); // Tính độ mạnh của xâu

    output_file << strength << endl; // Ghi kết quả vào tệp

    input_file.close();
    output_file.close();

    return 0;
}
