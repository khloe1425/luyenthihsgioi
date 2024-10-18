#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("TNV.INP");
    ofstream output("TNV.OUT");

    int n;
    input >> n; 

    vector<int> heights(251, 0); 

    
    for (int i = 0; i < n; ++i) {
        int height;
        input >> height;
        heights[height]++;
    }

    int max_count = 0;
    int max_height = 0;

    
    for (int h = 1; h <= 250; ++h) {
        if (heights[h] > max_count || (heights[h] == max_count && h > max_height)) {
            max_count = heights[h];
            max_height = h;
        }
    }

    
    output << max_height << " " << max_count << endl;

    input.close();
    output.close();

    return 0;
}
