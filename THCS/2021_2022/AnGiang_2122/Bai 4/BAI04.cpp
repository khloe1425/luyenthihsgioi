#include <iostream>
#include <fstream>
#include <string>

// Function to find the longest repeating substring in S
std::string find_longest_repeating_substring(const std::string &S) {
    int n = S.size();
    std::string longest_repeating_substring = "";

    // Iterate over possible starting points for the substring
    for (int length = 2; length <= n; length += 2) { // Only even lengths
        for (int i = 0; i + length <= n; i++) {
            std::string substring = S.substr(i, length);
            int half_length = length / 2;

            // Check if the substring is a repeating pattern
            if (substring.substr(0, half_length) == substring.substr(half_length, half_length)) {
                if (substring.size() > longest_repeating_substring.size()) {
                    longest_repeating_substring = substring;
                }
            }
        }
    }

    // If no repeating substring found, return "KHONG TIM DUOC"
    if (longest_repeating_substring.empty()) {
        return "KHONG TIM DUOC";
    }
    
    return longest_repeating_substring;
}

int main() {
    std::ifstream infile("BAI04.INP");
    std::ofstream outfile("BAI04.OUT");

    if (!infile || !outfile) {
        std::cerr << "Error opening input or output file!" << std::endl;
        return 1;
    }

    std::string S;
    infile >> S; // Reading the input string from file

    // Find the longest repeating substring
    std::string result = find_longest_repeating_substring(S);
    
    // Write the result to the output file
    outfile << result << std::endl;

    infile.close();
    outfile.close();

    return 0;
}
