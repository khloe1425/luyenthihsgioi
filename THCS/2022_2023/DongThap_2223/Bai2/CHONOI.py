def main():
    # Đọc dữ liệu từ tệp CHONOI.INP
    with open("CHONOI.INP", "r") as f:
        n, k = map(int, f.readline().strip().split())
        weights = list(map(int, f.readline().strip().split()))

    # Sắp xếp danh sách trọng lượng
    weights.sort()
    
    count = 0
    left = 0
    right = n - 1

    # Sử dụng phương pháp hai con trỏ
    while left < right:
        if weights[left] + weights[right] <= k:
            # Nếu tổng trọng lượng nhỏ hơn hoặc bằng k, đếm số cặp
            count += (right - left)
            left += 1
        else:
            right -= 1

    # Ghi kết quả vào tệp CHONOI.OUT
    with open("CHONOI.OUT", "w") as f:
        f.write(str(count) + "\n")

if __name__ == "__main__":
    main()
