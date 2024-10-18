# Đọc dữ liệu từ file CAYXANH.INP
with open('CAYXANH.INP', 'r') as file:
    # Đọc dòng đầu tiên và tách các giá trị n, l, m
    n, l, m = map(int, file.readline().split())
    
    # Đọc dòng thứ hai và tách thành danh sách các chiều cao cây
    heights = list(map(int, file.readline().split()))

# Khởi tạo biến đếm
count = 0

# Duyệt qua từng chiều cao cây và kiểm tra điều kiện
for height in heights:
    if abs(height - l) <= m:
        count += 1

# Ghi kết quả vào file CAYXANH.OUT
with open('CAYXANH.OUT', 'w') as file:
    file.write(str(count))
