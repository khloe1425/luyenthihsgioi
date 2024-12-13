#include <iostream>
#include <fstream>
#include <string>

// Hàm tìm chuỗi con lặp dài nhất trong S
std::string find_longest_repeating_substring(const std::string &S)
{
    int n = S.size();
    std::string longest_repeating_substring = "";

    // Duyệt qua các điểm bắt đầu có thể có cho chuỗi con
    for (int length = 2; length <= n; length += 2)
    { // Chỉ xét các độ dài chẵn
        for (int i = 0; i + length <= n; i++)
        {
            std::string substring = S.substr(i, length);
            int half_length = length / 2;

            // Kiểm tra nếu chuỗi con là một mẫu lặp
            if (substring.substr(0, half_length) == substring.substr(half_length, half_length))
            {
                if (substring.size() > longest_repeating_substring.size())
                {
                    longest_repeating_substring = substring;
                }
            }
        }
    }

    // Nếu không tìm thấy chuỗi con lặp, trả về "KHONG TIM DUOC"
    if (longest_repeating_substring.empty())
    {
        return "KHONG TIM DUOC";
    }

    return longest_repeating_substring;
}

int main()
{
    std::ifstream infile("BAI04.INP");
    std::ofstream outfile("BAI04.OUT");

    if (!infile || !outfile)
    {
        std::cerr << "Lỗi mở file đầu vào hoặc đầu ra!" << std::endl;
        return 1;
    }

    std::string S;
    infile >> S; // Đọc chuỗi đầu vào từ file

    // Tìm chuỗi con lặp dài nhất
    std::string result = find_longest_repeating_substring(S);

    // Ghi kết quả vào file đầu ra
    outfile << result << std::endl;

    infile.close();
    outfile.close();

    return 0;
}
