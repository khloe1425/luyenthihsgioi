#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Function to check if a year is a leap year
bool is_leap_year(int year) {
    return (year % 4 == 0);
}

// Function to check if the day is valid for the given month and year
bool is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1) return false;

    // Days in each month
    if (month == 2) {
        return day <= (is_leap_year(year) ? 29 : 28);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    } else {
        return day <= 31;
    }
}

// Function to parse and validate date from string S
std::string parse_date(const std::string &S) {
    int year = std::stoi(S.substr(S.size() - 2, 2)); // Last two characters as year

    // Possible day-month combinations
    std::vector<std::pair<int, int>> possible_dates;

    if (S.size() == 4) {
        // Case for 4 characters (e.g., 1316, where day=1, month=3, year=16)
        int day = S[0] - '0';
        int month = std::stoi(S.substr(1, 1));
        possible_dates.emplace_back(day, month);
    } else if (S.size() == 5) {
        // Case for 5 characters (e.g., 11216, can be day=11, month=2 or day=1, month=12)
        int day1 = std::stoi(S.substr(0, 1));
        int month1 = std::stoi(S.substr(1, 2));

        int day2 = std::stoi(S.substr(0, 2));
        int month2 = std::stoi(S.substr(2, 1));

        possible_dates.emplace_back(day1, month1);
        possible_dates.emplace_back(day2, month2);
    }

    // Check each possible day-month combination for validity
    for (const auto &date : possible_dates) {
        int day = date.first;
        int month = date.second;

        if (is_valid_date(day, month, year)) {
            return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
        }
    }

    return "KHONG TAO DUOC";
}

int main() {
    std::ifstream infile("BAI01.INP");
    std::ofstream outfile("BAI01.OUT");

    if (!infile || !outfile) {
        std::cerr << "Lỗi mở file đầu vào hoặc đầu ra!" << std::endl;
        return 1;
    }

    std::string S;
    while (infile >> S) {
        outfile << parse_date(S) << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
