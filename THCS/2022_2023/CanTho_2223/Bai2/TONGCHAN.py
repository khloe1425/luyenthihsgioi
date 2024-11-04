# Đọc dữ liệu từ file TONGCHAN.INP
with open('TONGCHAN.INP', 'r') as file:
    # Đọc số lượng phần tử n
    n = int(file.readline().strip())
    
    # Đọc các giá trị của dãy số
    arr = list(map(int, file.readline().split()))

# Đếm số lượng phần tử chẵn và lẻ
even_count = sum(1 for x in arr if x % 2 == 0)
odd_count = n - even_count  # Số lẻ = tổng số phần tử - số chẵn

# Kết quả là số phần tử nhỏ hơn giữa chẵn và lẻ
result = min(even_count, odd_count)

# Ghi kết quả ra file TONGCHAN.OUT
with open('TONGCHAN.OUT', 'w') as file:
    file.write(str(result))
