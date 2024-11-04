def main():
    # Đọc dữ liệu từ file
    with open("CHUSO.INP", "r") as input_file:
        a0 = input_file.readline().strip()  # Đọc a0
        n, m = map(int, input_file.readline().strip().split())  # Đọc n và m

    length = len(a0)  # Độ dài của a0
    current_length = length  # Độ dài hiện tại

    # Tính độ dài của a_n
    for i in range(n):
        current_length *= 2  # Mỗi lần nhân đôi chiều dài
        # Kiểm tra xem chiều dài có vượt quá m không
        if current_length >= m:
            break

    # Nếu độ dài của a_n nhỏ hơn m thì không tìm được chữ số thứ m
    if current_length < m:
        with open("CHUSO.OUT", "w") as output_file:
            output_file.write("-1\n")
        return

    # Xác định chữ số thứ m trong a_n
    for i in range(n, -1, -1):
        # Tính chiều dài của a_i
        len_ai = length * (2 ** i)  # 2^i

        if m > len_ai:
            m -= len_ai  # Giảm m để tìm trong phần tiếp theo
        else:
            # Xác định phần nào trong a_i mà chúng ta cần
            if m <= length:
                with open("CHUSO.OUT", "w") as output_file:
                    output_file.write(f"{a0[m - 1]}\n")  # Nếu nằm trong phần đầu
            else:
                m -= length  # Giảm m để tìm trong phần sau
                with open("CHUSO.OUT", "w") as output_file:
                    output_file.write(f"{a0[length - m]}\n")  # Tìm trong phần đảo ngược
            return

    # Nếu không tìm thấy
    with open("CHUSO.OUT", "w") as output_file:
        output_file.write("-1\n")

if __name__ == "__main__":
    main()
