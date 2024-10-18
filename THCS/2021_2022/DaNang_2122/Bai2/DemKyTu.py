# Nhập xâu ký tự từ bàn phím
S = input("Nhập xâu ký tự S: ")

# Đếm số lượng ký tự 'A'
countA = 0
for c in S:
    if c == 'A':
        countA += 1

# In ra kết quả
print(f"Số lượng ký tự 'A' trong xâu S là: {countA}")
