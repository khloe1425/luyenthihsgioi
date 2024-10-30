def sum_divisors(x):
    total = 0
    for i in range(1, int(x**0.5) + 1):
        if x % i == 0:
            total += i
            if i != x // i:  # Tránh tính gấp đôi nếu i và x/i là giống nhau
                total += x // i
    return total

def is_nearly_perfect(x):
    divisor_sum = sum_divisors(x)
    return 2 * x <= divisor_sum

def main():
    with open("GHH.INP", "r") as input_file:
        N = int(input_file.readline().strip())
        A = list(map(int, input_file.readline().strip().split()))

    with open("GHH.OUT", "w") as output_file:
        for number in A:
            if is_nearly_perfect(number):
                output_file.write("1\n")
            else:
                output_file.write("0\n")

if __name__ == "__main__":
    main()
