import math

# Hàm kiểm tra một số có phải số nguyên tố hay không
def is_prime(n):
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(math.sqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

# Nhập số nguyên dương a từ bàn phím
a = int(input("Nhập số nguyên dương a: "))

b = 1
while not is_prime(a + b):
    b += 1

# In ra số nguyên dương b nhỏ nhất
print(f"Số nguyên dương b nhỏ nhất là: {b}")
