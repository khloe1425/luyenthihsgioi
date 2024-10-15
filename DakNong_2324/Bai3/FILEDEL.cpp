#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("FILEDEL.INP");
    ofstream outputFile("FILEDEL.OUT");

    int n, q;
    inputFile >> n >> q;
    
    vector<string> files(n);
    vector<int> remaining_files;
    unordered_set<char> deleted_chars;
    
    // Đọc danh sách tệp tin
    for (int i = 0; i < n; ++i) {
        inputFile >> files[i];
    }

    // Xử lý từng thao tác xóa
    for (int i = 0; i < q; ++i) {
        char delete_char;
        inputFile >> delete_char;

        deleted_chars.insert(delete_char);
        int count = 0;

        for (const auto& file : files) {
            bool to_delete = false;

            for (char ch : file) {
                if (deleted_chars.count(ch)) {
                    to_delete = true;
                    break;
                }
            }
            
            if (!to_delete) {
                count++;
            }
        }

        // Lưu số lượng tệp tin còn lại sau mỗi thao tác xóa
        remaining_files.push_back(count);
    }

    // Ghi kết quả ra file
    for (int i = 0; i < q; ++i) {
        outputFile << remaining_files[i] << endl;
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}