#include <iostream>
#include <deque>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    // Open input and output files
    ifstream inputFile("BONUS.INP");
    ofstream outputFile("BONUS.OUT");

    // Read n and k
    int n, k;
    inputFile >> n >> k;

    // Read card values into a deque
    deque<int> cards(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> cards[i];
    }

    // Variable to store the maximum total reward
    int totalReward = 0;

    // Debugging log
    cout << "Initial Cards: ";
    for (int card : cards) cout << card << " ";
    cout << endl;

    // Perform k steps to select card pairs
    for (int step = 0; step < k; ++step) {
        int option1 = abs(cards.front() - cards.back()); // Difference between first and last
        int option2 = abs(cards.front() - cards[1]);    // Difference between first two
        int option3 = abs(cards[cards.size() - 2] - cards.back()); // Difference between last two

        // Choose the operation yielding the highest reward
        if (option1 >= option2 && option1 >= option3) {
            totalReward += option1;
            cout << "Step " << step + 1 << ": Pick " << cards.front() << " and " << cards.back()
                 << " -> Reward = " << option1 << endl;
            cards.pop_front();
            cards.pop_back();
        } else if (option2 >= option1 && option2 >= option3) {
            totalReward += option2;
            cout << "Step " << step + 1 << ": Pick " << cards.front() << " and " << cards[1]
                 << " -> Reward = " << option2 << endl;
            cards.pop_front();
            cards.pop_front();
        } else {
            totalReward += option3;
            cout << "Step " << step + 1 << ": Pick " << cards[cards.size() - 2] << " and " << cards.back()
                 << " -> Reward = " << option3 << endl;
            cards.pop_back();
            cards.pop_back();
        }

        // Debugging log
        cout << "Remaining Cards: ";
        for (int card : cards) cout << card << " ";
        cout << endl;
    }

    // Output the maximum total reward
    outputFile << totalReward << endl;

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
