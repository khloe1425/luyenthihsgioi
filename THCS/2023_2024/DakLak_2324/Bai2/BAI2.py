import math

def sum_of_digits(x):
    return sum(int(digit) for digit in str(x))

def find_minimum_x(n):
    x = n
    while True:
        y = sum_of_digits(x)
        if math.gcd(x, y) > 1:
            return x
        x += 1

def main():
    n = int(input("Nhập số nguyên dương N: "))
    result = find_minimum_x(n)
    print(result)

if __name__ == "__main__":
    main()
