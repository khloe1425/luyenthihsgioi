# Hàm tính tổng các ước thực sự của n
def tong_uoc_thuc_su(n):
    tong = 0
    for i in range(1, n):
        if n % i == 0:  # i là ước của n
            tong += i
    return tong

# Hàm kiểm tra số khỏe mạnh
def la_so_khoe_manh(n):
    return tong_uoc_thuc_su(n) > n

# Đọc dữ liệu từ file sokhoemanh.inp
with open("sokhoemanh.inp", "r") as infile:
    a, b = map(int, infile.readline().split())

# Đếm số lượng số khỏe mạnh trong đoạn [a, b]
dem_so_khoe_manh = 0
for n in range(a, b + 1):
    if la_so_khoe_manh(n):
        dem_so_khoe_manh += 1

# Ghi kết quả ra file sokhoemanh.out
with open("sokhoemanh.out", "w") as outfile:
    outfile.write(str(dem_so_khoe_manh) + "\n")
