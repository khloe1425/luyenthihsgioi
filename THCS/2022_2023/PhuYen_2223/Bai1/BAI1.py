def decimal_to_roman(num):
    # Bảng các số La Mã
    roman_numerals = [
        (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
        (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
        (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
    ]
    
    result = []
    
    # Lặp qua từng giá trị La Mã từ lớn tới bé
    for value, roman in roman_numerals:
        while num >= value:
            result.append(roman)
            num -= value
    
    return ''.join(result)

# Đọc dữ liệu từ tệp
with open('BAI1.INP', 'r') as inp_file:
    numbers = [int(line.strip()) for line in inp_file]

# Chuyển đổi và ghi kết quả vào tệp
with open('BAI1.OUT', 'w') as out_file:
    for num in numbers:
        out_file.write(decimal_to_roman(num) + '\n')
