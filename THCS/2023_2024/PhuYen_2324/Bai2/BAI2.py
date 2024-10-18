def is_palindrome(word):
    """Kiểm tra xem một từ có phải là từ đối xứng hay không."""
    return word == word[::-1]

def main():
    # Mở file để đọc
    with open("BAI2.INP", "r") as infile:
        line = infile.readline().strip()  # Đọc dòng đầu tiên

    words = line.split()  # Tách chuỗi thành danh sách các từ
    palindromes = []

    # Đọc từng từ trong chuỗi
    for word in words:
        if len(word) >= 2 and is_palindrome(word):
            palindromes.append(word)  # Lưu từ đối xứng vào danh sách

    # Tìm độ dài lớn nhất của các từ đối xứng
    max_length = max(len(p) for p in palindromes) if palindromes else 0

    # Lưu các từ đối xứng có độ dài lớn nhất vào kết quả
    longest_palindromes = [p for p in palindromes if len(p) == max_length]

    # Ghi số lượng từ đối xứng và các từ đối xứng có độ dài lớn nhất vào file
    with open("BAI2.OUT", "w") as outfile:
        outfile.write(f"{len(palindromes)}\n")  # Số lượng từ đối xứng
        for lp in longest_palindromes:
            outfile.write(f"{lp}\n")  # Ghi các từ đối xứng có độ dài lớn nhất

if __name__ == "__main__":
    main()
