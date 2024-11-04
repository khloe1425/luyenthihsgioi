input_path = './FADOUBLE.INP'
output_path = './FADOUBLE.OUT'

def double_factorial(n):
    if n == 0:
        return 1
    if n % 2 == 0:  # n chẵn
        result = 1
        for i in range(2, n + 1, 2):
            result *= i
        return result
    else:  # n lẻ
        result = 1
        for i in range(1, n + 1, 2):
            result *= i
        return result

with open(input_path, 'r') as file:
    n = int(file.readline().strip())

total = 0
for i in range(1, n + 1):
    if i % 2 == 0:
        total -= double_factorial(i) 
    else:
        total += double_factorial(i)  

with open(output_path, 'w') as file:
    file.write(str(total) + '\n')
