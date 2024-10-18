def is_independent(n):
    # Kiểm tra xem các chữ số trong n có xuất hiện trùng lặp hay không
    digits = str(n)
    return len(set(digits)) == len(digits)

# Đọc dữ liệu từ file SODOCLAP.INP
with open("SODOCLAP.INP", "r") as file_in:
    X = int(file_in.read().strip())

# Tìm số độc lập nhỏ nhất lớn hơn X
result = X + 1
while not is_independent(result):
    result += 1

# Ghi kết quả ra file SODOCLAP.OUT
with open("SODOCLAP.OUT", "w") as file_out:
    file_out.write(str(result) + "\n")
