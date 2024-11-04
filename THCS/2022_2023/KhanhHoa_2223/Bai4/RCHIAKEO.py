def min_sadness(M, desires):
    # Khởi tạo mảng DP với giá trị lớn (vô cực)
    dp = [float('inf')] * (M + 1)
    dp[0] = 0  # Không có kẹo, không có giận hờn

    for desire in desires:
        # Duyệt ngược để cập nhật DP
        for j in range(M, -1, -1):
            # Duyệt từ 0 đến desire hoặc j
            for k in range(min(desire, j) + 1):
                # Tính mức độ giận hờn
                sadness = (desire - k) ** 2
                dp[j] = min(dp[j], dp[j - k] + sadness if j - k >= 0 else float('inf'))

    return min(dp)  # Trả về mức độ giận hờn nhỏ nhất

def main():
    # Đọc dữ liệu từ tệp RCHIAKEO.INP
    with open("RCHIAKEO.INP", "r") as infile:
        M, N = map(int, infile.readline().strip().split())
        desires = [int(infile.readline().strip()) for _ in range(N)]
    
    # Tính toán mức độ giận hờn nhỏ nhất
    result = min_sadness(M, desires)

    # Ghi kết quả ra tệp RCHIAKEO.OUT
    with open("RCHIAKEO.OUT", "w") as outfile:
        outfile.write(str(result) + '\n')

if __name__ == "__main__":
    main()
