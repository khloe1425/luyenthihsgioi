# Đọc dữ liệu từ file KHUYENMAI.INP
with open('KHUYENMAI.INP', 'r') as file:
    a, b, c, n = map(int, file.readline().split())

# Số lượng sách có thể nhận được trong mỗi lần mua
total_books_per_purchase = a + b

# Số lần mua đầy đủ
full_purchase_times = n // total_books_per_purchase

# Số sách còn thiếu sau các lần mua đầy đủ
remaining_books = n % total_books_per_purchase

# Tính tổng số tiền
total_cost = full_purchase_times * a * c

# Xử lý số sách còn thiếu nếu cần mua thêm
if remaining_books > 0:
    if remaining_books <= a:
        total_cost += remaining_books * c
    else:
        total_cost += a * c

# Ghi kết quả ra file KHUYENMAI.OUT
with open('KHUYENMAI.OUT', 'w') as file:
    file.write(str(total_cost))
