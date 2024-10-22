from math import factorial

# Hàm tính tổng các chữ số
def sum_of_digits(num):
    return sum(int(digit) for digit in str(num))

# Đọc giá trị x từ file TONGHV.INP
with open("TONGHV.INP", "r") as input_file:
    x = input_file.readline().strip()  # Đọc số nguyên dương x

# Chuyển đổi x thành số nguyên
x_int = int(x)
n = len(x)  # Số chữ số trong x
sum_digits = sum_of_digits(x)  # Tính tổng các chữ số
n_factorial = factorial(n)  # Tính n!

# Tính tổng giá trị các vị trí
positional_sum = (10**n - 1) // 9  # 1 + 10 + 100 + ... + 10^(n-1)

# Tính tổng hoán vị
total_sum = n_factorial * sum_digits * positional_sum

# Cộng thêm x vào tổng
final_total = total_sum + x_int

# Ghi kết quả ra file TONGHV.OUT
with open("TONGHV.OUT", "w") as output_file:
    output_file.write(str(final_total) + "\n")  # Ghi số nguyên m vào file
