def main():
    # Đọc dữ liệu từ tệp bai5.inp
    with open("bai5.inp", "r") as infile:
        n = int(infile.readline().strip())  # Đọc n
        A = list(map(int, infile.readline().strip().split()))  # Đọc dãy số A

    # Sắp xếp dãy số A
    A.sort()

    max_mod = 0  # Biến lưu giá trị lớn nhất của ai mod aj

    # Duyệt qua từng phần tử trong dãy đã sắp xếp
    for i in range(n):
        for j in range(i):
            # Tính ai mod aj
            mod_value = A[i] % A[j]
            # Cập nhật giá trị lớn nhất
            if mod_value > max_mod:
                max_mod = mod_value

    # Ghi kết quả vào tệp bai5.out
    with open("bai5.out", "w") as outfile:
        outfile.write(str(max_mod) + "\n")

if __name__ == "__main__":
    main()
