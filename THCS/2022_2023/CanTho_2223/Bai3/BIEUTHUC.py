# Đọc dữ liệu từ file BIEUTHUC.INP
with open('BIEUTHUC.INP', 'r') as file:
    expression = file.readline().strip()

# Tính toán kết quả của biểu thức
result = eval(expression)

# Ghi kết quả ra file BIEUTHUC.OUT
with open('BIEUTHUC.OUT', 'w') as file:
    file.write(str(result))
