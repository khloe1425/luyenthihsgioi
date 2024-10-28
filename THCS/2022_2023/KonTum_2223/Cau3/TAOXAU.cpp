#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

// Hàm đệ quy để tạo ra các xâu con
void generateSubstrings(const string& s, int m, int n, int start, string current, set<string>& resultSet) {
    // Nếu độ dài của current đạt m, thêm vào tập hợp
    if (current.length() >= m) {
        resultSet.insert(current);
    }

    // Nếu đã đạt đến n, dừng
    if (start == n) {
        return;
    }

    // Duyệt các ký tự trong xâu
    for (int i = start; i < n; i++) {
        generateSubstrings(s, m, n, i + 1, current + s[i], resultSet);
    }
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("TAOXAU.INP");
    ofstream output("TAOXAU.OUT");

    int n, m;
    input >> n >> m;
    string s;
    input >> s;

    // Tập hợp để lưu các xâu con khác nhau
    set<string> resultSet;

    // Tạo xâu con
    generateSubstrings(s, m, n, 0, "", resultSet);

    // Ghi kết quả vào file
    output << resultSet.size() << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
