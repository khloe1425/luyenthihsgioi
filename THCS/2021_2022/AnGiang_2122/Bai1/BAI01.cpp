#include <iostream>
#include <string>

using namespace std;

// Hàm kiểm tra năm nhuận
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Hàm kiểm tra ngày hợp lệ
bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    // Số ngày tối đa trong từng tháng
    int daysInMonth;
    if (month == 2) {
        daysInMonth = isLeapYear(year) ? 29 : 28; // Tháng 2
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30; // Tháng 30 ngày
    } else {
        daysInMonth = 31; // Tháng 31 ngày
    }

    return day <= daysInMonth;
}

int main() {
    string s;
    cin >> s;

    int length = s.length();
    if (length < 4 || length > 5) {
        cout << "KHONG TAO DUOC" << endl;
        return 0;
    }

    int year = 0, day = 0, month = 0;

    // Tách năm
    year = stoi(s.substr(length - 2)) + 2000; // Hai ký tự cuối là năm

    if (length == 4) {
        day = stoi(s.substr(0, 1)); // 1 ký tự đầu là ngày
        month = stoi(s.substr(1, 2)); // 2 ký tự tiếp theo là tháng
    } else if (length == 5) {
        if (isdigit(s[1])) {
            day = stoi(s.substr(0, 2)); // 2 ký tự đầu là ngày
            month = stoi(s.substr(2, 3)); // 3 ký tự còn lại là tháng
        } else {
            day = stoi(s.substr(0, 1)); // 1 ký tự đầu là ngày
            month = stoi(s.substr(1, 4)); // 4 ký tự còn lại là tháng
        }
    }

    // Kiểm tra ngày hợp lệ
    if (isValidDate(day, month, year)) {
        cout << day << "/" << month << "/" << (year % 100) << endl; // In ra ngày/tháng/năm
    } else {
        cout << "KHONG TAO DUOC" << endl;
    }

    return 0;
}
