#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

// Hàm tính giá trị biểu thức
int evaluate(const string& expr) {
    stack<int> nums;
    stack<char> ops;
    int n = expr.size();
    
    for (int i = 0; i < n; ++i) {
        if (isdigit(expr[i])) {
            int num = 0;
            while (i < n && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            nums.push(num);
        } else if (expr[i] == '(') {
            ops.push(expr[i]);
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                if (op == '+') nums.push(a + b);
                else if (op == '-') nums.push(a - b);
                else if (op == '*') nums.push(a * b);
            }
            ops.pop(); // Bỏ dấu '('
        } else {
            while (!ops.empty() && ops.top() != '(' &&
                   ((expr[i] == '+' || expr[i] == '-') || (expr[i] == '*' && ops.top() == '*'))) {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                if (op == '+') nums.push(a + b);
                else if (op == '-') nums.push(a - b);
                else if (op == '*') nums.push(a * b);
            }
            ops.push(expr[i]);
        }
    }
    while (!ops.empty()) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        if (op == '+') nums.push(a + b);
        else if (op == '-') nums.push(a - b);
        else if (op == '*') nums.push(a * b);
    }
    return nums.top();
}

// Hàm sinh tất cả cách thêm ngoặc
void generateExpressions(const string& expr, int l, int r, set<int>& results) {
    if (l >= r) {
        results.insert(evaluate(expr));
        return;
    }

    for (int i = l; i < r; ++i) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
            string left = "(" + expr.substr(0, i) + ")";
            string right = "(" + expr.substr(i + 1) + ")";
            string newExpr = left + expr[i] + right;
            results.insert(evaluate(newExpr));
        }
    }
}

int main() {
    ifstream input("EXAM.INP");
    ofstream output("EXAM.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    input >> n;
    vector<string> expressions(n);

    for (int i = 0; i < n; ++i) {
        input >> expressions[i];
    }

    bool hasSolution = true;
    for (const auto& expr : expressions) {
        set<int> results;
        generateExpressions(expr, 0, expr.size() - 1, results);

        if (results.size() < n) {
            hasSolution = false;
            output << "NO SOLUTION" << endl;
            break;
        }

        for (const auto& result : results) {
            output << result << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}
