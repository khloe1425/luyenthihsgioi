def count_numbers_with_sum_digits(N):
    count = 0
    # Duyệt qua tất cả các chữ số a, b, c, d
    for a in range(1, 10):  # a phải từ 1 đến 9 vì đây là chữ số đầu tiên của số có 4 chữ số
        for b in range(0, 10):
            for c in range(0, 10):
                for d in range(0, 10):
                    if a + b + c + d == N:
                        count += 1
    return count

# Đọc dữ liệu từ file SUMDIGITS.INP
with open('SUMDIGITS.INP', 'r') as inp_file:
    T = int(inp_file.readline().strip())  # Số bộ dữ liệu
    queries = [int(inp_file.readline().strip()) for _ in range(T)]  # Các giá trị N

# Ghi kết quả ra file SUMDIGITS.OUT
with open('SUMDIGITS.OUT', 'w') as out_file:
    for N in queries:
        result = count_numbers_with_sum_digits(N)
        out_file.write(f"{result}\n")
