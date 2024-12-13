// KHAOSATGIA.CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ifstream input("KhaoSatGia.Inp");
    ofstream output("KhaoSatGia.Out");

    int N;
    input >> N;
    input.ignore(); // Bỏ qua ký tự xuống dòng sau số N

    vector<pair<char, int>> items;
    int totalCost = 0;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(input, line);

        char itemName = line[0];
        vector<int> prices;

        for (size_t j = 1; j < line.size(); ++j) {
            if (isdigit(line[j])) {
                prices.push_back(line[j] - '0');
            }
        }

        int minPrice = *min_element(prices.begin(), prices.end());
        items.push_back({itemName, minPrice});
        totalCost += minPrice;
    }

    for (const auto &item : items) {
        output << item.first << " " << item.second << endl;
    }
    output << totalCost << endl;

    input.close();
    output.close();

    return 0;
}
