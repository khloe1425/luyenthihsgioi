import math

# Hàm tìm ước của một số
def find_divisors(n):
    divisors = []
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
    return sorted(divisors)

# Đọc dữ liệu từ tệp UOCCHUNG.INP
with open("UOCCHUNG.INP", "r") as f:
    A, B = map(int, f.readline().split())

# Tìm ước chung lớn nhất (GCD)
gcd_value = math.gcd(A, B)

# Tìm các ước của GCD
divisors = find_divisors(gcd_value)

# Lấy ước lớn thứ hai
second_largest_divisor = divisors[-2] if len(divisors) > 1 else divisors[0]

# Ghi kết quả vào tệp UOCCHUNG.OUT
with open("UOCCHUNG.OUT", "w") as f:
    f.write(str(second_largest_divisor))