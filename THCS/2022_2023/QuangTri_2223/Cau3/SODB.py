def is_prime(n):
    """Kiểm tra xem số nguyên n có phải là số nguyên tố hay không."""
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def count_even_odd_digits(n):
    """Đếm số chữ số chẵn và lẻ trong số nguyên n."""
    even_count = 0
    odd_count = 0
    
    while n > 0:
        digit = n % 10
        if digit % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
        n //= 10  # Chia nguyên cho 10 để loại bỏ chữ số cuối
    return even_count, odd_count

def main():
    with open("SODB.INP", "r") as infile:
        N = int(infile.readline().strip())  # Đọc số lượng phần tử
        A = list(map(int, infile.readline().strip().split()))  # Đọc danh sách các số nguyên

    special_count = 0

    for number in A:
        if is_prime(number):  # Kiểm tra số nguyên tố
            even_count, odd_count = count_even_odd_digits(number)  # Đếm chữ số chẵn và lẻ
            
            # Kiểm tra điều kiện số đặc biệt
            if even_count != odd_count:
                special_count += 1

    with open("SODB.OUT", "w") as outfile:
        outfile.write(str(special_count) + "\n")  # Ghi kết quả

if __name__ == "__main__":
    main()
