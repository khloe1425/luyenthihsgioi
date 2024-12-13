#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    ifstream input("LUYENTAP.INP");
    ofstream output("LUYENTAP.OUT");

    int n;
    input >> n;

    unordered_map<int, int> frequency; // Đếm tần suất của từng giá trị
    int maxFrequency = 0;

    for (int i = 0; i < n; i++) {
        int x;
        input >> x;

        frequency[x]++;
        if (frequency[x] > maxFrequency) {
            maxFrequency = frequency[x]; // Cập nhật tần suất lớn nhất
        }
    }

    output << maxFrequency << endl;

    input.close();
    output.close();

    return 0;
}
