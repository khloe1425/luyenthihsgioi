def main():
    # Đọc dữ liệu từ tệp MM.INP
    with open("MM.INP", "r") as input_file:
        s = input_file.readline().strip()  # Đọc xâu mật thư

    # Sử dụng tập hợp để lưu trữ các số nguyên phân biệt
    unique_numbers = set()

    # Biến để lưu trữ số tạm thời
    temp_number = ""

    for char in s:
        # Kiểm tra nếu ký tự là một chữ số
        if char.isdigit():
            temp_number += char  # Thêm ký tự vào số tạm thời
        else:
            # Nếu có số tạm thời, thêm vào tập hợp và reset
            if temp_number:
                unique_numbers.add(int(temp_number))  # Chuyển đổi thành số nguyên và thêm vào tập
                temp_number = ""

    # Kiểm tra nếu có số tạm thời còn lại sau vòng lặp
    if temp_number:
        unique_numbers.add(int(temp_number))

    # Số lượng số nguyên phân biệt
    result = len(unique_numbers)

    # Ghi kết quả ra tệp MM.OUT
    with open("MM.OUT", "w") as output_file:
        output_file.write(str(result) + "\n")

if __name__ == "__main__":
    main()
