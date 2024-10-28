import math

# Hàm đọc dữ liệu từ file RUTGON.INP
def read_rutgon_inp(file_path):
    with open(file_path, 'r') as file:
        # Đọc hai số nguyên a và b
        a, b = map(int, file.readline().split())
    return a, b

# Hàm ghi kết quả vào file RUTGON.OUT
def write_rutgon_out(file_path, a, b):
    with open(file_path, 'w') as file:
        file.write(f"{a} {b}\n")

# Hàm rút gọn phân số
def simplify_fraction(a, b):
    gcd_ab = math.gcd(a, b)  # Tìm ước số chung lớn nhất của a và b
    a //= gcd_ab  # Chia cả tử số và mẫu số cho ước số chung lớn nhất
    b //= gcd_ab
    return a, b

# Đường dẫn file
file_path_inp = 'RUTGON.INP'
file_path_out = 'RUTGON.OUT'

# Đọc dữ liệu từ file RUTGON.INP
a, b = read_rutgon_inp(file_path_inp)

# Rút gọn phân số
a, b = simplify_fraction(a, b)

# Ghi kết quả vào file RUTGON.OUT
write_rutgon_out(file_path_out, a, b)
