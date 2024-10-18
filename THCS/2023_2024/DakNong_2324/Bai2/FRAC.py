import math

def main():
    # Đọc dữ liệu từ file FRAC.INP
    with open("FRAC.INP", "r") as input_file:
        a, b = map(int, input_file.readline().strip().split())
    
    # Kiểm tra tính hợp lệ của phân số
    if b == 0:
        # Nếu mẫu số bằng 0, phân số không hợp lệ
        with open("FRAC.OUT", "w") as output_file:
            output_file.write("INVALID")
        return
    
    # Tìm ước chung lớn nhất giữa tử số và mẫu số
    gcd = math.gcd(a, b)
    
    # Rút gọn tử số và mẫu số
    a //= gcd
    b //= gcd

    # Đưa dấu âm lên tử số nếu mẫu số âm
    if b < 0:
        a = -a
        b = -b

    # Ghi kết quả vào file FRAC.OUT
    with open("FRAC.OUT", "w") as output_file:
        # Nếu mẫu số là 1, chỉ in ra tử số
        if b == 1:
            output_file.write(f"{a}")
        # Nếu phân số là số nguyên
        elif a % b == 0:
            output_file.write(f"{a // b}")
        # Trường hợp khác, in ra phân số rút gọn
        else:
            output_file.write(f"{a} {b}")

if __name__ == "__main__":
    main()