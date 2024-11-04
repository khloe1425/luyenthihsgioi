def find_array_a(n, B):
    A = [0] * n
    total = 0  # tổng các phần tử của A từ A[1] đến A[i-1]
    
    for i in range(n):
        A[i] = (i + 1) * B[i] - total
        total += A[i]  # cập nhật tổng sau khi tính A[i]
    
    return A

# Input
n = int(input())  # đọc số phần tử
B = list(map(int, input().split()))  # đọc mảng B

# Tìm mảng A
A = find_array_a(n, B)

# Output
print(" ".join(map(str, A)))
