def count_valid_boxes(m, n):
    """Đếm số loại hộp bánh có thể mua."""
    count = 0
    for i in range(1, n + 1):
        total_packages = (i * (i + 1)) // 2  # Tính tổng số gói bánh
        if total_packages % m == 0:  # Kiểm tra chia đều cho m bạn
            count += 1
    return count

if __name__ == "__main__":
    # Nhập dữ liệu từ bàn phím
    m = int(input("Nhập số lượng học sinh (m): "))
    n = int(input("Nhập kích thước tối đa của hộp bánh (n): "))
    
    result = count_valid_boxes(m, n)
    print(result)  # In ra kết quả
