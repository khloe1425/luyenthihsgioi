#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <fstream>

int calculateMinimumSteps(int transactionCount, const std::vector<int>& transactions) {
    int currentBalance = 0;
    int totalSteps = 0;
    std::deque<std::pair<int, int>> pendingLoans;

    // Process each transaction
    for (int i = 0; i < transactionCount; ++i) {
        ++totalSteps; // Count the step for moving to the current transaction

        if (transactions[i] > 0) {
            currentBalance += transactions[i]; // Accumulate cash
        } else {
            pendingLoans.push_back({i, transactions[i]}); // Record pending loan
        }

        // Attempt to repay loans if possible
        while (!pendingLoans.empty() && currentBalance >= std::abs(pendingLoans.front().second)) {
            auto loan = pendingLoans.front();
            pendingLoans.pop_front();
            currentBalance += loan.second; // Repay the loan (loan.second is negative)
            totalSteps += (i - loan.first); // Steps to move forward to repay the loan
        }
    }

    // After processing all transactions, attempt to clear any remaining loans
    while (!pendingLoans.empty()) {
        auto loan = pendingLoans.front();
        if (currentBalance >= std::abs(loan.second)) {
            pendingLoans.pop_front();
            currentBalance += loan.second;
            totalSteps += (transactionCount - loan.first); // Steps to return and repay the loan
        } else {
            return -1; // If unable to repay, return -1
        }
    }

    return totalSteps;
}

int main() {
    std::ifstream inputFile("Tinhtoan.INP");
    std::ofstream outputFile("Tinhtoan.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error: Unable to open input or output file." << std::endl;
        return 1;
    }

    int transactionCount;
    inputFile >> transactionCount;
    std::vector<int> transactions(transactionCount);
    for (int i = 0; i < transactionCount; ++i) {
        inputFile >> transactions[i];
    }

    int result = calculateMinimumSteps(transactionCount, transactions);
    outputFile << result << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
