# Mở file input và output
with open("incr.inp", "r") as infile, open("incr.out", "w") as outfile:
    # Đọc dữ liệu
    n, d = map(int, infile.readline().split())
    b = list(map(int, infile.readline().split()))
    
    total_operations = 0

    # Duyệt qua từng cặp phần tử liên tiếp
    for i in range(1, n):
        if b[i] <= b[i - 1]:
            # Tính số thao tác cần thiết
            needed_increase = (b[i - 1] - b[i] + d) // d
            total_operations += needed_increase
            # Cập nhật giá trị mới của b[i]
            b[i] += needed_increase * d

    # Ghi kết quả ra file output
    outfile.write(f"{total_operations}\n")
