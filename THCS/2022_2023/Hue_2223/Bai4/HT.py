def generate_combinations(n, k, start=1, current_combination=[]):
    if len(current_combination) == k:
        result.append(tuple(current_combination))  # Lưu tổ hợp hiện tại
        return

    for i in range(start, n + 1):
        current_combination.append(i)  # Thêm người vào tổ hợp
        generate_combinations(n, k, i + 1, current_combination)  # Gọi đệ quy
        current_combination.pop()  # Loại bỏ người vừa thêm để quay lại

# Đọc dữ liệu từ file HT.INP
with open("HT.INP", "r") as input_file:
    n, k = map(int, input_file.readline().strip().split())

result = []  # Danh sách để chứa các tổ hợp
generate_combinations(n, k)

# Ghi kết quả vào file HT.OUT
with open("HT.OUT", "w") as output_file:
    for combination in result:
        output_file.write(f"{{{','.join(map(str, combination))}}}\n")
    output_file.write(f"{len(result)}\n")  # Ghi tổng số tổ hợp
