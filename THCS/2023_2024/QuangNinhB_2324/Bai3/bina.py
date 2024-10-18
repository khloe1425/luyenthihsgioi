def minimize_flips(s, n, k):
    flips = 0
    s = list(s)  # Chuyển chuỗi thành danh sách để có thể chỉnh sửa
    
    i = 0
    while i < n:
        # Tìm đoạn liên tiếp
        j = i
        while j < n and s[j] == s[i]:
            j += 1
        # Nếu đoạn liên tiếp dài hơn k
        if j - i > k:
            # Bắt đầu từ vị trí thứ k+1 trong đoạn liên tiếp
            for x in range(i + k, j, k + 1):
                s[x] = '0' if s[x] == '1' else '1'  # Lật bit
                flips += 1
        i = j  # Di chuyển đến bit tiếp theo ngoài đoạn liên tiếp

    # Kết quả đầu ra là số lật và chuỗi mới
    return flips, ''.join(s)

# Đọc dữ liệu từ tệp
with open("bina.inp", "r") as f:
    n, k = map(int, f.readline().split())
    s = f.readline().strip()

# Gọi hàm
flips, modified_string = minimize_flips(s, n, k)

# Ghi kết quả vào tệp
with open("bina.out", "w") as f:
    f.write(f"{flips}\n")
    f.write(modified_string + "\n")
