def max_pieces(n):
    # Chia n thành hai phần gần bằng nhau
    x = n // 2
    y = n - x
    return (x + 1) * (y + 1)

# Nhập số lần cắt
n = int(input())
# Tính và in ra số mảnh tối đa
print(max_pieces(n))
