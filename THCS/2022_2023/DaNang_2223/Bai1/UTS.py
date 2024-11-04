# Đọc giá trị x từ file UTS.INP
with open('UTS.INP', 'r') as input_file:
    x = int(input_file.readline().strip())

# Tìm ước thực sự lớn nhất của x
for i in range(x // 2, 0, -1):
    if x % i == 0:
        result = i
        break

# Ghi kết quả ra file UTS.OUT
with open('UTS.OUT', 'w') as output_file:
    output_file.write(str(result))
