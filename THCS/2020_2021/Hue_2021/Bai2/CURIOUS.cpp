// CURIOUS.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    ifstream input("CURIOUS.INP");
    ofstream output("CURIOUS.OUT");

    int n;
    input >> n;

    int totalSum = n * (2 * n + 1); // Tổng tất cả các số từ 1 đến 2n

    // Kiểm tra nếu không thể chia tổng cho 2
    if (totalSum % 2 != 0)
    {
        output << "No Solution";
        return 0;
    }

    int targetRowSum = totalSum / 2; // Tổng mỗi hàng
    vector<int> numbers;
    for (int i = 1; i <= 2 * n; ++i)
    {
        numbers.push_back(i);
    }

    do
    {
        // Chia ma trận thành 2 hàng
        vector<int> row1(numbers.begin(), numbers.begin() + n);
        vector<int> row2(numbers.begin() + n, numbers.end());

        // Tính tổng hàng 1 và hàng 2
        int sumRow1 = accumulate(row1.begin(), row1.end(), 0);
        int sumRow2 = accumulate(row2.begin(), row2.end(), 0);

        // Kiểm tra nếu thỏa mãn điều kiện tổng hàng
        if (sumRow1 == targetRowSum && sumRow2 == targetRowSum)
        {
            // Kiểm tra tổng từng cột
            bool valid = true;
            for (int i = 0; i < n; ++i)
            {
                if (row1[i] + row2[i] != row1[0] + row2[0])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                // Ghi hàng đầu tiên
                for (int num : row1)
                {
                    output << num << " ";
                }
                output << endl;

                // Ghi hàng thứ hai
                for (int num : row2)
                {
                    output << num << " ";
                }
                output << endl;

                // Ghi tổng
                output << targetRowSum << endl;
                return 0;
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    // Không tìm được giải pháp
    output << "No Solution";
    return 0;
}
