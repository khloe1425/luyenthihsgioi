def calculate_sum(M, N):
    total_sum = 0
    MOD = 1532023  # Số dư

    # Tính tổng các số trên bảng theo quy luật
    for i in range(1, M + 1):
        for j in range(1, N + 1):
            if (i + j) % 2 == 0:  # Kiểm tra (i + j) có chẵn không
                total_sum += (i - 1) * N + j
                total_sum %= MOD  # Lấy dư ngay sau mỗi lần cộng

    return total_sum

def main():
    with open("TONGBANG.INP", "r") as infile:
        # Đọc giá trị M và N từ tệp
        M, N = map(int, infile.readline().strip().split())

    result = calculate_sum(M, N)

    with open("TONGBANG.OUT", "w") as outfile:
        outfile.write(str(result) + "\n")  # Ghi kết quả vào tệp

if __name__ == "__main__":
    main()
