#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Đường dẫn tới tệp nhập và xuất
    ifstream input("GAME.INP");
    ofstream output("GAME.OUT");

    // Kiểm tra tệp có mở thành công không
    if (!input.is_open() || !output.is_open()) {
        cerr << "Lỗi khi mở tệp!" << endl;
        return 1;
    }

    // Đọc n và k
    int n, k;
    input >> n >> k;

    // Đọc số bóng của từng chùm đèn
    vector<int> lights(n);
    for (int i = 0; i < n; i++) {
        input >> lights[i];
    }

    // Biến để đếm số cách chọn
    long long count = 0;
    int oddCount = 0;
    int left = 0;

    // Sử dụng hai con trỏ để duyệt qua mảng
    for (int right = 0; right < n; right++) {
        // Kiểm tra chùm đèn hiện tại có số bóng lẻ hay không
        if (lights[right] % 2 != 0) {
            oddCount++;
        }

        // Khi số chùm đèn lẻ lớn hơn k, di chuyển con trỏ trái
        while (oddCount > k) {
            if (lights[left] % 2 != 0) {
                oddCount--;
            }
            left++;
        }

        // Khi số chùm đèn lẻ đúng bằng k
        if (oddCount == k) {
            int tempLeft = left;
            // Tìm cách chọn con trỏ trái
            while (tempLeft < n && lights[tempLeft] % 2 == 0) {
                tempLeft++;
            }

            // Đếm số cách chọn
            int rightCount = right - left + 1;
            int leftCount = tempLeft - left;
            count += leftCount;
        }
    }

    output << count << endl;

    // Đóng tệp
    input.close();
    output.close();

    return 0;
}
