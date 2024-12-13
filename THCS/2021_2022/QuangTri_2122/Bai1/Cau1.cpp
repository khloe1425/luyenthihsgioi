#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm tính số ngược của một số nguyên
int reverseNumber(int x) {
    int reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed;
}

// Hàm tính GCD (Ước chung lớn nhất)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ifstream input("CAU1.INP");
    ofstream output("CAU1.OUT");

    int N;
    input >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        input >> numbers[i];
    }

    for (int i = 0; i < N; ++i) {
        int reversed = reverseNumber(numbers[i]);
        int gcdValue = gcd(numbers[i], reversed);

        // Debug thông tin
        cout << "Number: " << numbers[i] 
             << ", Reversed: " << reversed 
             << ", GCD: " << gcdValue << endl;

        if (gcdValue == 1) {
            output << 1 << endl;
        } else {
            output << 0 << endl;
        }
    }

    input.close();
    output.close();
    return 0;
}
