# Hàm tính tổng các chữ số của một số
def tong_cac_chu_so(n):
    return sum(int(c) for c in str(n))

# Đọc dữ liệu từ file SIMILAR.INP
with open("SIMILAR.INP", "r") as infile:
    l, r = map(int, infile.readline().split())

# Tạo một từ điển để lưu danh sách các số theo tổng chữ số
tu_dien = {}

# Duyệt qua tất cả các số trong đoạn từ l đến r
for n in range(l, r + 1):
    tong_chu_so = tong_cac_chu_so(n)  # Tính tổng các chữ số
    if tong_chu_so not in tu_dien:
        tu_dien[tong_chu_so] = []  # Tạo danh sách mới nếu chưa có
    tu_dien[tong_chu_so].append(n)  # Thêm số vào danh sách

# Tìm hiệu lớn nhất
hieu_lon_nhat = 0
for ds in tu_dien.values():
    if len(ds) > 1:  # Chỉ xét nếu có ít nhất 2 số có cùng tổng chữ số
        hieu_lon_nhat = max(hieu_lon_nhat, max(ds) - min(ds))

# Ghi kết quả ra file SIMILAR.OUT
with open("SIMILAR.OUT", "w") as outfile:
    outfile.write(str(hieu_lon_nhat) + "\n")
