import math

# Hàm kiểm tra một số có phải là số nguyên tố hay không
def la_so_nguyen_to(n):
    if n < 2:
        return False  # Số nhỏ hơn 2 không phải là số nguyên tố
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Đọc dữ liệu từ file nguyento.inp
with open("nguyento.inp", "r") as infile:
    a, b = map(int, infile.readline().split())

# Đếm số lượng số nguyên tố trong đoạn [a, b]
dem_so_nguyen_to = 0
for n in range(a, b + 1):
    if la_so_nguyen_to(n):
        dem_so_nguyen_to += 1

# Ghi kết quả ra file nguyento.out
with open("nguyento.out", "w") as outfile:
    outfile.write(str(dem_so_nguyen_to) + "\n")
