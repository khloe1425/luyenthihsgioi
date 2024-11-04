# Nhập số nguyên dương n
n = int(input())

# Khởi tạo biến tổng
total_sum = 0

# Tính tổng các chữ số
while n > 0:
    total_sum += n % 10  # Lấy chữ số cuối và cộng vào tổng
    n //= 10              # Cập nhật n bằng cách bỏ chữ số cuối

# In ra kết quả
print(total_sum)