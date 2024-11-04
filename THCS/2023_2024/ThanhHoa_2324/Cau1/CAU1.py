def convert_prop_to_join_case(var_name):
    result = []
    for i, ch in enumerate(var_name):
        if ch.isupper() and i > 0:  # Nếu là chữ cái viết hoa và không phải ký tự đầu
            result.append('_')
        result.append(ch.lower())  # Thêm chữ cái (chuyển thành chữ thường)
    return ''.join(result)

# Đọc dữ liệu từ tệp CAU1.INP
with open('CAU1.INP', 'r') as file:
    prop_case_var = file.read().strip()

# Chuyển đổi từ PropCase sang join_case
join_case_var = convert_prop_to_join_case(prop_case_var)

# Ghi kết quả vào tệp CAU1.OUT
with open('CAU1.OUT', 'w') as file:
    file.write(join_case_var)
