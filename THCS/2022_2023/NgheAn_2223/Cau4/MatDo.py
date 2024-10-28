def max_high_density_length(s):
    n = len(s)
    max_length = 0

    # Duyệt từng vị trí trong chuỗi
    for i in range(n):
        count = {}  # Đếm số lần xuất hiện của các ký tự
        for j in range(i, n):
            char = s[j]
            if char in count:
                count[char] += 1
            else:
                count[char] = 1

            # Kiểm tra điều kiện mật độ xuất hiện cao
            max_count = max(count.values())
            total_count = j - i + 1
            other_count = total_count - max_count
            
            if max_count > other_count:
                max_length = max(max_length, total_count)

    return max_length

# Đọc dữ liệu từ tệp MatDo.INP
with open('MatDo.Inp', 'r') as f:
    s = f.readline().strip()

# Tính độ dài chuỗi con có mật độ xuất hiện cao
result = max_high_density_length(s)

# Ghi kết quả vào tệp MatDo.OUT
with open('MatDo.Out', 'w') as f:
    f.write(str(result) + '\n')
