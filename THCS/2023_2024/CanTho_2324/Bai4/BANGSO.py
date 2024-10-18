input_path = "./BANGSO.INP"
output_path = "./BANGSO.OUT"
def count_occurrences(input_file, output_file):
    with open(input_file, 'r') as infile:
        n, k = map(int, infile.readline().strip().split())

    count = 0

    # Tìm tất cả các ước số của k
    for i in range(1, int(k**0.5) + 1):
        if k % i == 0:  # i là ước của k
            j = k // i  # Tính j

            # Kiểm tra (i, j) có hợp lệ không
            if i <= n and j <= n:
                count += 1  # Đếm (i, j)
            if i != j and j <= n and i <= n:
                count += 1  # Đếm (j, i) nếu khác nhau

    with open(output_file, 'w') as outfile:
        outfile.write(f"{count}\n")

count_occurrences(input_path, output_path)
