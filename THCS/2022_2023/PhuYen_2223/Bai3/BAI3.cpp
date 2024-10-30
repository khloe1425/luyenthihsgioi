#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

vector<string> extract_expressions(const string& expression) {
    stack<int> positions;
    vector<string> results;
    
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            // Khi gặp dấu mở ngoặc, đẩy vị trí vào ngăn xếp
            positions.push(i);
        }
        else if (expression[i] == ')') {
            // Khi gặp dấu đóng ngoặc, lấy vị trí dấu mở ngoặc gần nhất
            int start = positions.top();
            positions.pop();
            // Trích xuất biểu thức từ dấu mở ngoặc đến dấu đóng ngoặc
            results.push_back(expression.substr(start, i - start + 1));
        }
    }
    
    return results;
}

int main() {
    // Đọc dữ liệu từ file BAI3.INP
    ifstream inp_file("BAI3.INP");
    string expression;
    if (inp_file.is_open()) {
        getline(inp_file, expression);
        inp_file.close();
    } else {
        cerr << "Không thể mở file BAI3.INP" << endl;
        return 1;
    }

    // Tách các cụm biểu thức
    vector<string> expressions = extract_expressions(expression);

    // Ghi kết quả vào file BAI3.OUT
    ofstream out_file("BAI3.OUT");
    if (out_file.is_open()) {
        out_file << expressions.size() << endl;  // Ghi số lượng cụm
        for (const auto& expr : expressions) {
            out_file << expr << endl;  // Ghi từng cụm biểu thức
        }
        out_file.close();
    } else {
        cerr << "Không thể mở file BAI3.OUT" << endl;
        return 1;
    }

    return 0;
}
