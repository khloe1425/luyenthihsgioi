# Đọc dữ liệu từ file tinhtong.inp
with open('tinhtong.inp', 'r') as infile:
    n = int(infile.readline().strip())

# Tính tổng các số chẵn nhỏ hơn n
if n > 2:
    k = (n // 2) - 1
    total = k * (n // 2)
else:
    total = 0

# Ghi kết quả vào file tinhtong.out
with open('tinhtong.out', 'w') as outfile:
    outfile.write(str(total) + '\n')
