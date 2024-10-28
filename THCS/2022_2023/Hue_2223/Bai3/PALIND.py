def expand_around_center(s, left, right):
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return right - left - 1  # Độ dài của xâu con đối xứng

def longest_palindrome_length(s):
    if not s:
        return 0

    max_length = 1  # Độ dài tối thiểu của palindrome là 1
    for i in range(len(s)):
        # Kiểm tra palindrome có độ dài lẻ
        len1 = expand_around_center(s, i, i)
        # Kiểm tra palindrome có độ dài chẵn
        len2 = expand_around_center(s, i, i + 1)
        max_length = max(max_length, len1, len2)
    
    return max_length

def main():
    # Đọc dữ liệu từ file PALIND.INP
    with open("PALIND.INP", "r") as input_file:
        s = input_file.readline().strip()  # Đọc toàn bộ xâu và loại bỏ khoảng trắng

    # Tìm độ dài của xâu con đối xứng dài nhất
    result = longest_palindrome_length(s)

    # Ghi kết quả vào file PALIND.OUT
    with open("PALIND.OUT", "w") as output_file:
        output_file.write(str(result))

if __name__ == "__main__":
    main()
