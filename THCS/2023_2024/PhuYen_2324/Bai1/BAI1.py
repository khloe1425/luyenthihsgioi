def calculate_persistence(n):
    # Nếu số có một chữ số, độ bền là 0
    if n < 10:
        return 0
    
    # Tính tích các chữ số của n
    product = 1
    while n > 0:
        product *= n % 10
        n //= 10
    
    # Đệ quy để tính độ bền
    return calculate_persistence(product) + 1

# Đọc dữ liệu từ file
with open('BAI1.INP', 'r') as infile:
    lines = infile.readlines()

# Khởi tạo danh sách để lưu kết quả
results = []

# Xử lý từng số trong file
for line in lines:
    n = int(line.strip())
    persistence = calculate_persistence(n)
    results.append(persistence)

# Ghi kết quả ra file
with open('BAI1.OUT', 'w') as outfile:
    for result in results:
        outfile.write(str(result) + '\n')
