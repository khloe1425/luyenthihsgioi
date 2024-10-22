# Đọc dữ liệu từ file CHIPHI.INP
with open("CHIPHI.INP", "r") as input_file:
    n, x = map(int, input_file.readline().strip().split())

# Tính số ghế đá
if n % 2 == 0:
    num_benches = n // 2  # Nếu n chẵn
else:
    num_benches = (n // 2) + 1  # Nếu n lẻ

# Tính tổng chi phí
total_cost = num_benches * x

# Ghi kết quả ra file CHIPHI.OUT
with open("CHIPHI.OUT", "w") as output_file:
    output_file.write(str(total_cost) + "\n")
