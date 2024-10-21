def reverse(s):
    return s[::-1]

def multiply_large_numbers(num1, num2):
    num1 = reverse(num1)
    num2 = reverse(num2)
    
    len1 = len(num1)
    len2 = len(num2)

    # Khởi tạo mảng kết quả
    result = [0] * (len1 + len2)

    for i in range(len2):
        carry = 0
        for j in range(len1):
            product = (int(num2[i]) * int(num1[j])) + carry + result[i + j]
            result[i + j] = product % 10
            carry = product // 10
        
        # Nếu còn số nhớ thì thêm vào
        if carry > 0:
            result[i + len1] += carry

    # Loại bỏ số 0 thừa ở đầu
    while len(result) > 1 and result[-1] == 0:
        result.pop()

    return ''.join(map(str, reversed(result)))

def main():
    # Đọc dữ liệu từ file
    with open('BAI4.INP', 'r') as infile:
        num1 = infile.readline().strip()
        num2 = infile.readline().strip()
    
    # Tính tích
    product = multiply_large_numbers(num1, num2)

    # Ghi kết quả vào file
    with open('BAI4.OUT', 'w') as outfile:
        outfile.write(product + '\n')

if __name__ == '__main__':
    main()
