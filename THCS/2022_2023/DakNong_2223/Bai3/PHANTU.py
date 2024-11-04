def calculate_molecular_weight(formula):
    """Tính phân tử lượng từ công thức hóa học."""
    # Định nghĩa nguyên tử lượng
    atomic_weights = {
        'H': 1,
        'O': 16,
        'N': 14,
        'C': 12
    }

    i = 0
    total_weight = 0
    n = len(formula)

    while i < n:
        element = formula[i]  # Lấy nguyên tử
        i += 1
        count = 0

        # Kiểm tra nếu có số đi kèm nguyên tử
        while i < n and formula[i].isdigit():
            count = count * 10 + int(formula[i])  # Tính số lượng
            i += 1

        if count == 0:  # Nếu không có số, mặc định số lượng là 1
            count = 1
        
        # Tính tổng trọng lượng cho nguyên tử hiện tại
        total_weight += atomic_weights[element] * count

    return total_weight

# Đọc dữ liệu từ file PHANTU.INP
with open("PHANTU.INP", "r") as input_file:
    formula = input_file.readline().strip()

# Tính phân tử lượng
molecular_weight = calculate_molecular_weight(formula)

# Ghi kết quả ra file PHANTU.OUT
with open("PHANTU.OUT", "w") as output_file:
    output_file.write(str(molecular_weight) + "\n")
