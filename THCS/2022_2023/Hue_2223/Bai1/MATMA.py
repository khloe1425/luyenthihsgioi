import math

# Function to calculate the least common multiple (LCM)
def lcm(a, b):
    return abs(a * b) // math.gcd(a, b)

# Function to calculate the sum of digits from a given date (day, month, year)
def sum_of_digits(day, month, year):
    return sum(int(digit) for digit in str(day) + str(month) + str(year))

# Reading input from the file
with open('MATMA.INP', 'r') as file:
    # Reading the first line for mother's birth date
    mom_day, mom_month, mom_year = map(int, file.readline().split())
    
    # Reading the second line for father's birth date
    dad_day, dad_month, dad_year = map(int, file.readline().split())

# Calculating the sum of digits for both mother and father
sum_mom = sum_of_digits(mom_day, mom_month, mom_year)
sum_dad = sum_of_digits(dad_day, dad_month, dad_year)

# Calculating the smallest number divisible by both sums (LCM)
password = lcm(sum_mom, sum_dad)

# Writing the result to the output file
with open('MATMA.OUT', 'w') as file:
    file.write(f"Mat ma khoa xe la: {password}\n")
