def is_prime(num):
    """Kiểm tra xem một số có phải là số nguyên tố hay không."""
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True

def sum_of_squares_of_digits(num):
    """Tính tổng bình phương các chữ số của một số."""
    return sum(int(digit) ** 2 for digit in num)

def main():
    # Mở file để đọc
    with open("BAI3.INP", "r") as infile:
        n = int(infile.readline().strip())  # Đọc số n
        results = []

        # Đọc từng số ai
        for _ in range(n):
            a = infile.readline().strip()  # Đọc số ai
            sum_squares = sum_of_squares_of_digits(a)  # Tính tổng bình phương
            if is_prime(sum_squares):  # Kiểm tra số đẹp
                results.append(f"{a} {sum_squares}")  # Lưu kết quả

    # Ghi kết quả vào file
    with open("BAI3.OUT", "w") as outfile:
        if results:
            outfile.write("\n".join(results) + "\n")  # Ghi các số đẹp
        else:
            outfile.write("0\n")  # Ghi 0 nếu không có số đẹp

if __name__ == "__main__":
    main()
