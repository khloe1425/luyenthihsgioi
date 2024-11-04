# Mở file input và output
with open("donu.inp", "r") as infile, open("donu.out", "w") as outfile:
    # Đọc dữ liệu
    n, k = map(int, infile.readline().split())
    s = infile.readline().strip()

    # Khởi tạo biến để lưu kết quả và các chỉ số cho thuật toán two-pointer
    max_time = 0
    left = 0
    zeros_count = 0

    # Duyệt qua xâu s với thuật toán two-pointer
    for right in range(n):
        if s[right] == '0':
            zeros_count += 1
        
        # Nếu số lượng '0' trong đoạn vượt quá k, dịch con trỏ trái (left)
        while zeros_count > k:
            if s[left] == '0':
                zeros_count -= 1
            left += 1

        # Cập nhật giá trị time lớn nhất
        max_time = max(max_time, right - left + 1)

    # Ghi kết quả ra file output
    outfile.write(f"{max_time}\n")
