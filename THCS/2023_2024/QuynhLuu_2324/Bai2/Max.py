def find_max_number(number, remove_count):
    stack = []
    to_remove = remove_count

    for digit in number:
        while stack and to_remove > 0 and stack[-1] < digit:
            stack.pop()
            to_remove -= 1
        stack.append(digit)

    # Nếu còn chữ số cần loại bỏ thì loại bỏ từ cuối
    while to_remove > 0 and stack:
        stack.pop()
        to_remove -= 1

    return ''.join(stack)  # Chuyển stack thành chuỗi

def main():
    # Đọc dữ liệu từ file Max.INP
    with open("Max.INP", "r") as infile:
        n, k = map(int, infile.readline().strip().split())
        number = infile.readline().strip()

    # Tìm số lớn nhất
    result = find_max_number(number, k)

    # Ghi kết quả ra file Max.OUT
    with open("Max.OUT", "w") as outfile:
        outfile.write(result + "\n")

if __name__ == "__main__":
    main()
