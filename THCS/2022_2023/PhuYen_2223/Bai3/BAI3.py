def extract_expressions(expression):
    """
    Hàm tách các cụm biểu thức trong dấu ngoặc đơn.
    """
    stack = []
    results = []
    current_expression = []
    
    for i, char in enumerate(expression):
        if char == '(':
            # Nếu gặp dấu mở ngoặc, đẩy vị trí bắt đầu vào stack
            stack.append(i)
        elif char == ')':
            # Nếu gặp dấu đóng ngoặc, lấy vị trí mở ngoặc gần nhất
            start = stack.pop()
            # Trích xuất cụm biểu thức từ vị trí mở ngoặc đến vị trí đóng ngoặc
            current_expression = expression[start:i+1]
            results.append(current_expression)
    
    return results

# Đọc dữ liệu từ file BAI3.INP
with open("BAI3.INP", "r") as inp_file:
    expression = inp_file.readline().strip()

# Tách các cụm biểu thức
expressions = extract_expressions(expression)

# Ghi kết quả vào file BAI3.OUT
with open("BAI3.OUT", "w") as out_file:
    out_file.write(str(len(expressions)) + "\n")  # Ghi số lượng cụm
    for expr in expressions:
        out_file.write(expr + "\n")  # Ghi từng cụm

