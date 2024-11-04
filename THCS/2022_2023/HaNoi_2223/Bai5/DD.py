def count_beautiful_subarrays(n, A):
    count = 0  # Biến đếm số dãy con đẹp

    # Vòng lặp lồng nhau để kiểm tra tất cả các dãy con
    for i in range(n):
        min_val = A[i]  # Giá trị nhỏ nhất trong dãy con
        max_val = A[i]  # Giá trị lớn nhất trong dãy con

        for j in range(i, n):
            min_val = min(min_val, A[j])  # Cập nhật giá trị nhỏ nhất
            max_val = max(max_val, A[j])  # Cập nhật giá trị lớn nhất

            # Kiểm tra điều kiện để là dãy đẹp
            if max_val - min_val == j - i:
                count += 1  # Tăng số dãy con đẹp

    return count

# Đọc dữ liệu từ tệp DD.INP
with open('DD.INP', 'r') as inp:
    n = int(inp.readline().strip())  # Đọc số nguyên dương N
    A = list(map(int, inp.readline().strip().split()))  # Đọc các phần tử của A

# Tính số dãy con đẹp
result = count_beautiful_subarrays(n, A)

# Ghi kết quả ra tệp DD.OUT
with open('DD.OUT', 'w') as out:
    out.write(f"{result}\n")
