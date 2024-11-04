def find_longest_word(input_string):
    # Thay thế ký tự '_' bằng dấu cách để tách từ
    input_string = input_string.replace('_', ' ')
    
    # Tách chuỗi thành danh sách các từ
    words = input_string.split()
    
    # Khởi tạo độ dài và từ dài nhất
    max_length = 0
    longest_word = ""
    
    # Lặp qua từng từ trong danh sách
    for word in words:
        word_length = len(word)
        # Cập nhật nếu tìm thấy từ dài hơn
        if word_length >= max_length:
            max_length = word_length
            longest_word = word
    
    return max_length, longest_word

def main():
    # Đọc dữ liệu từ tệp
    with open('TUDAI.INP', 'r') as file:
        input_string = file.readline().strip()
    
    # Tìm từ dài nhất
    max_length, longest_word = find_longest_word(input_string)
    
    # Ghi kết quả vào tệp
    with open('TUDAI.OUT', 'w') as file:
        file.write(f"{max_length}\n{longest_word}\n")

if __name__ == "__main__":
    main()
