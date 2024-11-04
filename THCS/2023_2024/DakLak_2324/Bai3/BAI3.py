def longest_unique_substring(s):
    n = len(s)
    char_index = {}
    start = 0
    max_length = 0
    max_start_index = 0

    for end in range(n):
        # Nếu kí tự đã xuất hiện trong đoạn con hiện tại
        if s[end] in char_index and char_index[s[end]] >= start:
            start = char_index[s[end]] + 1
        
        char_index[s[end]] = end  # Cập nhật vị trí kí tự hiện tại
        current_length = end - start + 1

        # Chỉ cập nhật nếu chiều dài hiện tại lớn hơn chiều dài lớn nhất
        if current_length > max_length:
            max_length = current_length
            max_start_index = start

    # Chuyển đổi chỉ số từ 0-based sang 1-based
    return max_start_index + 1, max_length

def main():
    s = input("Nhập xâu kí tự S: ")
    start_index, length = longest_unique_substring(s)
    print(start_index, length)

if __name__ == "__main__":
    main()
