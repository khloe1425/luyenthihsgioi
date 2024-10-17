def gcd(a, b):
    """Hàm tính ước số chung lớn nhất của a và b."""
    while b:
        a, b = b, a % b
    return a

def main():
    # Đọc dữ liệu từ file UCLN.INP
    with open("UCLN.INP", "r") as infile:
        a, b, c = map(int, infile.read().strip().split())

    # Tính UCLN của a và b
    ucln = gcd(a, b)

    # Ghi kết quả vào file UCLN.OUT
    with open("UCLN.OUT", "w") as outfile:
        if ucln == c:
            outfile.write("1\n")  # Nếu c là UCLN, ghi 1
        else:
            outfile.write("0\n")  # Ngược lại, ghi 0

if __name__ == "__main__":
    main()
