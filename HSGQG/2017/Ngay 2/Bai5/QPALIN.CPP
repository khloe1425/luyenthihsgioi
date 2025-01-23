#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Hàm kiểm tra xâu có đối xứng hay không
bool isPalindrome(const string& s) {
    int len = s.size();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - 1 - i]) return false;
    }
    return true;
}

// Hàm sinh xâu đối xứng cấp k
void generatePalindrome(int n, int k, const vector<char>& omega, string& current, vector<string>& result, int level) {
    if ((int)current.size() == n) {
        // Kiểm tra điều kiện đối xứng cấp k
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            string sub = current.substr(0, i);
            if (isPalindrome(sub)) ++count;
        }
        if (count >= k + 1) {
            result.push_back(current);
        }
        return;
    }

    // Thử tất cả các ký tự trong tập omega
    for (char c : omega) {
        current.push_back(c);
        generatePalindrome(n, k, omega, current, result, level + 1);
        current.pop_back();
    }
}

int main() {
    ifstream input("QPALIN.INP");
    ofstream output("QPALIN.OUT");

    // Kiểm tra mở file
    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc dữ liệu đầu vào
    int n, k, t;
    string omega;
    input >> n >> k;
    input >> omega;
    input >> t;

    // Chuyển ký tự trong omega thành vector để dễ xử lý
    vector<char> omegaVec(omega.begin(), omega.end());
    sort(omegaVec.begin(), omegaVec.end()); // Sắp xếp tập ký tự để đảm bảo thứ tự từ điển

    // Sinh tất cả các xâu đối xứng cấp k
    vector<string> result;
    string current = "";
    generatePalindrome(n, k, omegaVec, current, result, 0);

    // Sắp xếp kết quả theo thứ tự từ điển
    sort(result.begin(), result.end());

    // Ghi kết quả ra file
    if (t > (int)result.size() || t <= 0) {
        output << "-1" << endl; // Nếu không tìm thấy xâu thứ t
    } else {
        output << result[t - 1] << endl; // Xâu thứ t (1-based index)
    }

    input.close();
    output.close();
    return 0;
}
