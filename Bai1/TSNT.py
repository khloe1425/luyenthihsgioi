input_path = './THCS/2024/Hue/Bai1/TSNT.INP'
output_path = './THCS/2024/Hue/Bai1/TSNT.OUT'

def prime_factors(n):
    factors = []
    # Kiểm tra số 2
    while n % 2 == 0:
        factors.append(2)
        n //= 2
    # Kiểm tra các số lẻ từ 3 đến √n
    for i in range(3, int(n**0.5) + 1, 2):
        while n % i == 0:
            factors.append(i)
            n //= i
    # Nếu n là số nguyên tố lớn hơn 2
    if n > 2:
        factors.append(n)
    return factors

with open(input_path, 'r') as file:
    n = int(file.readline().strip())

factors = prime_factors(n)

result = '.'.join(map(str, factors))

with open(output_path, 'w') as file:
    file.write(result)
