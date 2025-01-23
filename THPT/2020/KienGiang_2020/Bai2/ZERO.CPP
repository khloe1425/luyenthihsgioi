#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Hàm tính giá trị của biểu thức
int evaluateExpression(const string& expr) {
    int result = 0, num = 0, sign = 1; // sign: +1 cho phép cộng, -1 cho phép trừ
    for (char c : expr) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else {
            result += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        }
    }
    result += sign * num; // Cộng số cuối cùng
    return result;
}

// Hàm quay lui để tạo tất cả các biểu thức
void generateExpressions(int n, int current, string expr, vector<string>& results) {
    if (current > n) {
        // Nếu đã tạo xong biểu thức, kiểm tra giá trị
        if (evaluateExpression(expr) == 0) {
            results.push_back(expr);
        }
        return;
    }

    // Thêm số hiện tại vào biểu thức với dấu cộng
    generateExpressions(n, current + 1, expr + "+" + to_string(current), results);

    // Thêm số hiện tại vào biểu thức với dấu trừ
    generateExpressions(n, current + 1, expr + "-" + to_string(current), results);

    // Nối số hiện tại vào số trước đó
    generateExpressions(n, current + 1, expr + to_string(current), results);
}

int main() {
    ifstream input("ZERO.INP");
    ofstream output("ZERO.OUT");

    int N;
    input >> N;

    vector<string> results;

    // Bắt đầu tạo biểu thức từ số 1
    generateExpressions(N, 2, "1", results);

    // Ghi kết quả ra file
    output << results.size() << endl;
    for (const string& expr : results) {
        output << expr << "=0" << endl;
    }

    input.close();
    output.close();

    return 0;
}
