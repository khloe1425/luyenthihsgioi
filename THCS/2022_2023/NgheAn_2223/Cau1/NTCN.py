def euler_totient(n):
    result = n  # Khởi tạo với n

    # Duyệt qua các số từ 2 đến sqrt(n)
    p = 2
    while p * p <= n:
        # Nếu p là ước số nguyên tố của n
        if n % p == 0:
            # Cập nhật result
            while n % p == 0:
                n //= p  # Loại bỏ ước số p khỏi n
            result -= result // p  # Cập nhật phi(n)
        p += 1

    # Nếu n còn lớn hơn 1, thì n là một số nguyên tố
    if n > 1:
        result -= result // n  # Cập nhật phi(n) với n

    return result

def main():
    # Đọc dữ liệu từ tệp NTCN.INP
    with open('NTCN.INP', 'r') as input_file:
        n = int(input_file.readline().strip())  # Đọc n

    # Tính số lượng số nguyên dương nhỏ hơn n và nguyên tố cùng nhau với n
    result = euler_totient(n)

    # Xuất kết quả ra tệp NTCN.OUT
    with open('NTCN.OUT', 'w') as output_file:
        output_file.write(str(result) + '\n')

if __name__ == '__main__':
    main()
