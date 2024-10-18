def find_max_password(n, arr):
    # Sắp xếp mảng
    arr.sort()
    
    # Chọn giá trị lớn nhất từ hai cặp hiệu
    # (a_n - a_1) * (a_{n-1} - a_2) và (a_n - a_2) * (a_{n-1} - a_1)
    option1 = (arr[-1] - arr[0]) * (arr[-2] - arr[1])
    option2 = (arr[-1] - arr[1]) * (arr[-2] - arr[0])
    
    # Kết quả là giá trị lớn nhất trong các lựa chọn
    return max(option1, option2)

# Đọc dữ liệu từ file
with open("pass.inp", "r") as f:
    n = int(f.readline())
    arr = list(map(int, f.readline().split()))

# Gọi hàm và tìm kết quả
result = find_max_password(n, arr)

# Ghi kết quả ra file
with open("pass.out", "w") as f:
    f.write(f"{result}\n")
